#include <stdio.h>
#include <string.h>

#include "orden.h"

#define MAX_LIN 1024

char salir[] = "exit";
static struct orden actual;
static char orden[MAX_LIN];
static int i; /* recorre la orden */
static int num_param; /* número de parámetros de la orden */
static int longitud; /* longitud de la línea leída */

static void borrar_orden_actual(void)
{
	i = 0;
	num_param=0;
	longitud = strlen(orden) - 1;
	orden[longitud]='\0';
	actual.entrada = NULL;
	actual.salida = NULL;
}

static void saltar_blancos(void)
{
	while (orden[i] == ' ' || orden[i] == '\t')
	{
		i++;
	}
}

static void final_palabra(void)
{
	while
	(	orden[i] != ' ' &&
		orden[i] != '\t' &&
		orden[i] != '\0'
	)
	{
		i++;
	}
}

static char* obtener_cadena(void)
{
	char* pal = &orden[i];
	final_palabra();
	orden[i] = '\0';
	i++;
	return pal;
}

static void extraer_param(void)
{
	actual.args[num_param++] = obtener_cadena();
}

static void redirigir_entrada(void)
{
	i++;
	saltar_blancos();
	actual.entrada = obtener_cadena();
	if (strlen(actual.entrada) == 0)
	{
		fprintf(stderr, "Falta fichero de entrada\n" );
		actual.args[0] = NULL;
	}
}

static void redirigir_salida(void)
{
	i++;
	saltar_blancos();
	actual.salida = obtener_cadena();
	if (strlen(actual.salida) == 0)
	{
		fprintf(stderr, "Falta fichero de salida\n" );
		actual.args[0] = NULL;
	}
}

static void extraer_palabra(void)
{
	char* pal;

	saltar_blancos();
	switch (orden[i])
	{
		case '<':
			redirigir_entrada(); break;
		case '>':
			redirigir_salida(); break;
		case '\0':
			break;
		default:
			extraer_param();
	}
}

static void analizar_orden(void)
{
	do
	{
		extraer_palabra();
	} while (i < longitud && num_param < MAX_ARGS-2);
	if (num_param >= MAX_ARGS-2)
	{
		fprintf(stderr, "Demasiados argumentos\n");
		actual.args[0] = NULL;
	}
	actual.args[num_param] = NULL;
}

struct orden* leer_orden(const char* indicador)
{
	do
	{
		fprintf(stdout, "%s ", indicador);
		fgets(orden, MAX_LIN, stdin);
		if (feof(stdin))
		{
			actual.args[0] = salir;
			actual.args[1] = NULL;
			actual.entrada = NULL;
			actual.salida = NULL;
		}
		else
		{
			borrar_orden_actual();
			analizar_orden();
		}
	} while (actual.args[0] == NULL);
	return &actual;
}
