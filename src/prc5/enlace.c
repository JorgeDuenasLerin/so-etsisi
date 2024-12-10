/* ------------------------------------------------------------------------*/
/*                                pon_boot.c                               */
/* ----------------------------------------------------------------------- */
/*                                                                         */
/* ----------------------------------------------------------------------- */

#include "driver.h" /* inicDisk, cerrarDisk, escribirSector */
#include "sf_defs.h"

#include <stdio.h>

char bufer[tamSector];

int main(int argc, char *argv[])
{
    char *nombre_imagen;
    int i;

    if (argc != 2)
    {
        printf("\n formato: enlace imagen \n");
        return (1);
    }

    nombre_imagen = argv[1];

    inicDisk(nombre_imagen);

    /*Introducir tantas líneas como necesites para llevar
    a cabo las modificaciones pedidas en el apartado 7 */

    /*Para leer un sector sustituya el cero por el número de bloque*/
    leerSector(0, &bufer);

    /*Para escribir un sector sustituya el cero por el número de bloque*/
    escribirSector(0, &bufer);

    cerrarDisk();

    return (0);
}
