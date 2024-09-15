/* 2cadena.c */
#include <stdio.h>

int main(int argc, char *argv[]) {
    char cadena[] = "Hola";

    /* Accediendo y modificando los elementos de la cadena */
    printf("%c\n", cadena[0]);  /* Imprime 'H' */
    cadena[1] = 'e';            /* Cambia 'o' por 'e' */
    printf("%s\n", cadena);     /* Imprime "Hela" */
    return 0;
}
