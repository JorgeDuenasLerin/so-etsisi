#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "generador.h"

static int escribir_palabras(const int longitud)
{
	int i;
	char* palabra = calloc(longitud+2, sizeof(char));

	for (i = 0; i < total_palabras(); i++)
	{
		if (genera_palabra(i, palabra) != OK)
		{
			return !OK;
		}
		fprintf(stdout, "%s\n", palabra);
	}

	free(palabra);
	return OK;
}

static int trabajar(const char alfabeto[], const int longitud)
{
	if (configura_generador(alfabeto, longitud) != OK)
	{
		return !OK;
	}

	escribir_palabras(longitud);

	return OK;
}

static void uso(const char prog[])
{
	fprintf(stderr, "Uso: %s <alfabeto> <longitud>\n", prog);
}

/**
 * Dada una cadena de caracteres, obtiene su representación numérica entera.
 * Tiene los siguientes parámetros:
 *	cadena: la versión textual del número.
 *	num: referencia al entero que albergará el valor numérico de la cadena.
 * Si cadena contiene una cadena numérica válida, devuelve OK.
 * En caso contrario, devuelve !OK y el valor referenciado por num es
 * indeterminado.
 */
static int str2int(const char cadena[], long *num)
{
	char* endptr;

	errno = OK;
	*num = strtol(cadena, &endptr, 10);
	if (errno != OK || *endptr != '\0' || *num < 1)
	{
		return !OK;
	}
	return OK;
}

int main(const int argc, const char * argv[])
{
	long longitud;

	if (argc != 3)
	{
		uso(argv[0]);
		return !OK;
	}
	if (str2int(argv[2], &longitud) != OK)
	{
		fprintf(stderr, "la longitud no es válida\n");
		return !OK;
	}
	if (trabajar(argv[1], longitud) != OK)
	{
		fprintf(stderr, "el programa ha fallado\n");
		return !OK;
	}
	return OK;
}

