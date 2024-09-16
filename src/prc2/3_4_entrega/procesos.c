#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "procesos.h"

/* estructura proceso con PID, ejecutable y estado */ 
struct proceso 
{ 
    /**** PRÁCTICA ****/ 
    /* declara un campo entero de nombre zz0000_pid donde zz0000 
       será tu matrícula */
    
    /* declara un campo de tipo array de caracteres de longitud  
       MAX_EJECUTABLE de nombre zz0000_ejecutable */ 

    /* declara un campo entero de nombre zz0000_estado */
    
}; 

/* función para añadir la información de un proceso al array procesos
   en la posición ix */
int anadir_proceso(struct proceso* procesos[], int ix, int pid,
                   char *ejecutable, int estado)
{
    /**** PRÁCTICA ****/
    /* Declara un puntero a struct proceso */
    
    /* Reserva memoria para guardar la información del nuevo proceso.
       Contempla que puede producirse error en la reserva.
       Devuelve MEM_ERROR
    */
    
    /* Modifica el valor del pid de la estructura reservada
       dinámicamente accediendo a través del operador '->' */
    
    /* Utiliza la función strncpy para copiar el parámetro con la ruta del
       ejecutable a la estructura */
    
    /* establece su estado */

    /* Asigna a la posición ix del array de punteros el nuevo registro */
    

    return 0;
}

/* función para listar */
void listar_procesos(struct proceso* procesos[])
{
    /**** PRÁCTICA ****/
    /* Recorre el array de procesos con for, escribiendo con printf los campos
       de cada proceso. Si una posición está vacía, imprimir "Vacía" */
}

/* función para liberar */
void liberar_procesos(struct proceso* procesos[])
{
    /**** PRÁCTICA ****/
    /* Recorre el array de procesos con for liberando la memoria de cada
       proceso */
}