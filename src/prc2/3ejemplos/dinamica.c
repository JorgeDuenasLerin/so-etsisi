#include <stdio.h>
#include <stdlib.h> /* Necesario para calloc y free */ 

int main(int argc, char *argv[]) 
{ 
    int* puntero_a_enteros; /* Declaración de un puntero a entero */ 

    int cantidad_elementos = 5; 

    int i = 0; 

    /* Reserva de memoria para un array de 5 enteros  
      con calloc (inicializa a 0) */ 
    puntero_a_enteros = calloc(cantidad_elementos, sizeof(int)); 
    /*  
       Reserva de memoria para un array de 5 enteros con malloc 
       Código comentado para comparar malloc y calloc 
       puntero_a_enteros = malloc(cantidad_elementos * sizeof(int)); 
    */ 
    /* Verificación de que calloc ha reservado la memoria correctamente */ 
    if (puntero_a_enteros == NULL) 
    { 
        fprintf(stderr, "Error al reservar memoria\n"); 
        return 1; 
    } 
    /* Impresión del array (todos los elementos estarán inicializados a 0)*/ 
    for (i= 0; i < cantidad_elementos; i++) 
    { 
        printf("Elemento %d: %d\n", i, puntero_a_enteros[i]); 
    } 
    /* Liberar la memoria reservada */ 
    free(puntero_a_enteros); 

    return 0; 
}
