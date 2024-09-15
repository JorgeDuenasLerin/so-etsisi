/* aritmeticapuntero.c */ 
#include <stdio.h> 

int main(void)  
{ 
    int numeros[5] = {10, 20, 30, 40, 50}; 
    int* puntero; 
    int diferencia; 
    /* puntero apunta al primer elemento del array */ 
    puntero = numeros; 

    /* Acceder a elementos del array usando aritmética de punteros */ 
    printf("Primer valor: %d\n", *puntero); /* 10 */ 
    printf("Segundo valor: %d\n", *(puntero + 1)); /* 20 */ 
    printf("Tercer valor: %d\n", *(puntero + 2)); /* 30 */ 

    /* Sumar punteros y comparar */ 
    diferencia = (puntero + 4) - puntero; 
    printf("Diferencia de punteros: %d\n", diferencia); /* 4 */ 
    return 0; 
}