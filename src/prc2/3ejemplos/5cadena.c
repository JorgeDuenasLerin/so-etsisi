#include <stdio.h> 

int main(void) 
{ 
    char cadena[] = "Hola"; 
    /* El puntero apunta al primer carácter de 'cadena' */ 
    char* ptr = cadena; 
    while (*ptr != '\0') 
    { 
        printf("%c\n", *ptr);  /* Imprime cada carácter de la cadena */ 
        ptr++;                 /* Avanza al siguiente carácter */ 
    } 
    return 0; 
} 
