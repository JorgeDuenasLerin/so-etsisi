#include <stdio.h> 
#include <string.h> /* necesario para strlen */ 

int main(int argc, char *argv[]) 
{ 
    int numeros[5]; 
    char cadena[10]; 
    cadena[0] = 'H'; 
    cadena[1] = 'o'; 
    cadena[2] = 'l'; 
    cadena[3] = 'a'; 
    cadena[4] = '\0'; /* Si no, no es cadena */ 
    /* Tamaño de un entero (depende del sistema) */ 
    printf("Tamaño de int: %lu\n", sizeof(int)); 
    /* Tamaño de array de enteros */ 
    printf("Tamaño de numeros: %lu\n", sizeof(numeros)); 
    /* Tamaño del array cadena */ 
    printf("Tamaño de cadena: %lu\n", sizeof(cadena)); 
    /* Longitud de la cadena, sin contar la marca de fin de cadena */ 
    printf("Longitud de cadena: %u\n", strlen(cadena)); 
    return 0; 
}
