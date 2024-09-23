/* Implementación del generador de palabras */

#include <stdio.h>
#include <string.h>
#include "generador.h"

static struct generador
{
	int longitud;
	const char* alfabeto;
	int alfa_tam;
	int total_palabras;
} gen = {0, NULL, 0, 0};

static int potencia(const int base, const int exp)
{
	int res;
	int i;

	for (res = 1, i = 0; i < exp; i++)
	{
		res = res * base;
	}
	return res;
}

int configura_generador(const char* const alfabeto, const int longitud)
{
	if (gen.alfabeto != NULL)
	{
		return ERR_YACONF;
	}
	if (alfabeto == NULL || strlen(alfabeto) == 0 || longitud <= 0)
	{
		return ERR_PARAM;
	}
	gen.longitud = longitud;
	gen.alfabeto = alfabeto;
	gen.alfa_tam = strlen(alfabeto);
	gen.total_palabras = potencia(strlen(alfabeto), longitud);
	return OK;
}
	
int genera_palabra(int pos, char palabra[])
{
	int ix_letra;

	if (gen.alfabeto == NULL)
	{
		return ERR_NOCONF;
	}
	if (pos >= gen.total_palabras || pos < 0)
	{
		return ERR_NOPOS;
	}
	palabra[gen.longitud] = '\0';
	for (ix_letra = gen.longitud - 1; ix_letra >= 0; ix_letra--)
	{
		const int ix_alfa_letra = pos % gen.alfa_tam;
		pos = pos / gen.alfa_tam;
		palabra[ix_letra] = gen.alfabeto[ix_alfa_letra];
	}
	return OK;
}

int total_palabras(void)
{
	return gen.total_palabras;
}

int longitud(void)
{
	return gen.longitud;
}

