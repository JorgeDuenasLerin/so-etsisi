/* ----------------------------------------------------------------------- */
/*   prueba_a.c: Crea X procesos hijos doCPU_x                           */
/* ----------------------------------------------------------------------- */
/*                     formato: prueba_a [ iteraciones ]                  */
/* ----------------------------------------------------------------------- */
#define _MINIX
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>

#define ERR_EXEC 100
#define ERR_NUM_ARGS 101
#define ERR_PAR_1 102

#define MAX_LONG_NOMBRE 11
#define ITERACIONES_POR_DEFECTO "10"
#define OK 0

int crear_fichero(int n_proceso, char* strIteraciones)
{
	char fichero[MAX_LONG_NOMBRE];
	snprintf(fichero, MAX_LONG_NOMBRE, "./doCPU_%i", n_proceso);
	if (fork() == 0){
		printf(" Se creo el proceso %i con %s iteraciones\n", getpid(), strIteraciones) ;
		execl(fichero, fichero, strIteraciones, NULL);
		printf("Error (pid:%i - %s): %s\n", getpid(), fichero, strerror(errno));
		exit(ERR_EXEC);
	}
	return 0 ;
}

void uso(void){
	printf("Uso: prueba_a <#procesos> [<#iteraciones>]\n");
}

int main ( int argc, char * argv [ ] )
{
	char* strIteraciones = ITERACIONES_POR_DEFECTO;
	int estado, pid, i, n_proceso, return_value;
	char* endptr;

	if (argc ==  1 || argc > 3) 
	{
		uso();
		return ERR_NUM_ARGS;
	}

	errno = OK;
	n_proceso = strtol(argv[1], &endptr, 10);
	if (errno != OK || *endptr != '\0' || n_proceso < 1)
	{
		uso();
		return ERR_PAR_1;
	}
	
	if (argc == 3) 
	{
		strIteraciones = argv[2] ;
	}

	for(i=0 ; i < n_proceso ; i++) {
		crear_fichero(i%10, strIteraciones);
	}	

	 for (i = 0 ; i < n_proceso; i++) 
	{
		pid = wait(&estado) ;
		if (WIFEXITED(estado))
		{
			return_value = WEXITSTATUS(estado);
			printf(" Termino el hijo %i con estado (%i)\n", pid, return_value) ;
		}
	}

	return(0) ;
}
