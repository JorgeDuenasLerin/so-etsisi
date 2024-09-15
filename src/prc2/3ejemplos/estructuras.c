/* estructuras.c */ 

#define _MINIX 
#include <sys/types.h> 
#include <stdio.h> 
#include <stdarg.h> 
#include <stdlib.h> 
#define TAM_NOMBRE 50 

/* Definición del struct para representar un alumno */ 
struct alumno 
{ 
    char nombre[TAM_NOMBRE];  /* Nombre del alumno */ 
    int edad;         /* Edad del alumno */ 
}; 

/* Función para imprimir la información de un alumno */ 
void imprimir_alumno(const struct alumno* alumno) 
{ 
    /* Acceso a campos a través de puntero */ 
    printf("Nombre: %s\n", alumno->nombre); 
    printf("Edad: %d\n", alumno->edad); 
} 

int main(int argc, char *argv[]) 
{ 
    /* Declaración de un alumno */ 
    /* Inicializa con nombre y edad */ 
    const struct alumno alumno1 = {"Homer Jay Simpson", 40}; 
    /* Reserva dinámica de memoria para un alumno */ 
    /* Reserva memoria inicializada a 0 */ 
    struct alumno* p_alumno2 = calloc(1, sizeof(struct alumno)); 
    if (p_alumno2 == NULL) 
    { 
        perror("No se pudo asignar memoria para el alumno"); 
        return EXIT_FAILURE; 
    } 
    /* Asigna nombre "Philip J. Fry" y edad 22 al segundo alumno */ 
    /* Ver la página de manual de la función snprintf */ 
    snprintf(p_alumno2->nombre, TAM_NOMBRE, "Philip J. Fry"); 
    p_alumno2->edad = 22; 
    /* Imprime la información de ambos alumnos */ 
    imprimir_alumno(&alumno1); 
    imprimir_alumno(p_alumno2); 
    /* Imprime el nombre del alumno1 */ 
    printf("Nombre de alumno1: %s\n", alumno1.nombre); 
    /* Libera la memoria reservada dinámicamente */ 
    free(p_alumno2); 
    return 0; 
} 