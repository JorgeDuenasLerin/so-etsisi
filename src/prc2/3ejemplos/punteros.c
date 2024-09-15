/* 3punteros.c */ 

#include <stdio.h> 

/* Función que modifica el valor de una variable usando punteros */ 
void modificar_valor(int* ptr) 
{ 
    /* Cambia el valor de la variable a la que apunta el puntero */ 
    *ptr = 20; 
} 

int main(int argc, char* argv[]) 
{ 
    int numero = 10; 

    printf("Antes de la función: %d\n", numero);

    /* Llamada a la función pasando la dirección de la variable */ 

    modificar_valor(&numero); 

    printf("Después de la función: %d\n", numero); 

    return 0; 
}