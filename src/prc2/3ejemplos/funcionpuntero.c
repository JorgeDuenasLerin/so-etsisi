/* funcionpuntero.c */ 

#include <stdio.h> 

/* Definición de funciones */ 
int sumar(int a, int b) 
{ 
    return a + b; 
} 

int restar(int a, int b) 
{ 
    return a - b; 
} 

/* Función que recibe un puntero a función */ 
int ejecutar_operacion(int (*operacion)(int, int), int x, int y) 
{ 
    /* 
    Se invoca a la función recibida en operación, pasándole como 
    parámetros los otros dos argumentos recibidos y se devuelve el resultado 
    */ 
    return operacion(x, y); 
}

int main(int argc, char *argv[]) 
{ 
    /* Declaración de variables al inicio */ 
    int resultado; 
    /* Llamada con la función sumar */ 
    resultado = ejecutar_operacion(sumar, 5, 3); 
    printf("Suma: %d\n", resultado); 

    /* Llamada con la función restar */ 
    resultado = ejecutar_operacion(restar, 5, 3); 
    printf("Resta: %d\n", resultado); 
    return 0; 
}