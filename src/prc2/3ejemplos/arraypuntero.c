/* arraypuntero.c */ 
#include <stdio.h> 

int main(int argc, char* argv[]) 
{ 
    /* Declaración de array de enteros */ 
    int array_enteros[5] = {10, 20, 30, 40, 50}; 
    int* puntero_a_array; /* Declaración de un puntero a entero */ 

    /* Asignación de la dirección del primer elemento del array al puntero */ 
    puntero_a_array = array_enteros;  

    /* Acceso a los elementos del array mediante puntero */ 
    printf("El primer elemento es: %d\n", *puntero_a_array); 
    printf("El segundo elemento es: %d\n", *(puntero_a_array + 1)); 
    printf("El tercer elemento es: %d\n", puntero_a_array[2]); 

    return 0; 
} 