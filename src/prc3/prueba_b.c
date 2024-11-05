/* ----------------------------------------------------------------------- */
/*   prueba_b.c: Crea 3 procesos hijos, dos procesos con NICE              */
/* ----------------------------------------------------------------------- */
/*                     formato: prueba_b [ iteraciones ]                   */
/* ----------------------------------------------------------------------- */
#define _MINIX
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define ERR_EXEC 100

#define ITERACIONES_POR_DEFECTO "10"

int main ( int argc, char * argv [ ] )
{
	char * strIteraciones = ITERACIONES_POR_DEFECTO;
	int estado, pid, i, return_value, return_exe;

	if (argc > 1) strIteraciones = argv[1] ;

	if (fork() == 0) {
		printf("iniciando doCPU_0\n");
		execl("/usr/bin/nice","N_doCPU_0","-n","-20","./doCPU_0", strIteraciones, NULL);
		printf("Error (N_doCPU_0): %s\n", strerror(errno));
		exit(ERR_EXEC);
	}
	
	if (fork() == 0) {
		printf("iniciando doCPU_1\n");
		execl("/usr/bin/nice","N_doCPU_1","-n","20","./doCPU_1", strIteraciones, NULL);
		printf("Error (N_doCPU_1): %s\n", strerror(errno));
		exit(ERR_EXEC);
	}

	if (fork() == 0){
		printf("iniciando doCPU_2\n");
		execl("./doCPU_2","N_doCPU_2", strIteraciones, NULL);
		printf("Error (N_doCPU_2): %s\n", strerror(errno));
		exit(ERR_EXEC);
	}

	for (i = 0 ; i < 3 ; i++)
	{
		pid = wait(&estado) ;
		return_value = WEXITSTATUS(estado);
		printf(" Termino el hijo %i con estado (%i)\n",
			   pid, return_value) ;
	}
	
	return(0) ;
}
