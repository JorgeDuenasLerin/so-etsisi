/* 3cadena.c */
#include <stdio.h>

int main(int argc, char *argv[]) {
    char cadena[] = "Hola";        /* Array de caracteres */
    char *ptr_cadena = "Mundo";    /* Puntero a una cadena de caracteres */

    printf("%s\n", cadena);        /* Imprime "Hola" */
    printf("%s\n", ptr_cadena);    /* Imprime "Mundo" */

    /* Modificando el array */
    cadena[0] = 'h';
    printf("%s\n", cadena);        /* Imprime "hola" */

    *ptr_cadena = 'm'; /* Accedemos a traves del puntero */
    printf("%s\n", ptr_cadena);        /* Imprime "mola" */

    return 0;
}
