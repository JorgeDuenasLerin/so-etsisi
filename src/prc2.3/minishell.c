#include <stdio.h>
#include <string.h>
#include "orden.h"

void mostrar_orden(struct orden* o)
{
	int i;

	for (i = 0; o->args[i] != NULL; i++)
	{
		printf("%s ", o->args[i]);
	}
	if (o->entrada != NULL)
	{
		printf("< %s ", o->entrada);
	}
	if (o->salida != NULL)
	{
		printf("> %s ", o->salida);
	}
	printf ("\n");
}

int main(const int argc, const char* argv[])
{
	struct orden* actual;

	do
	{
		actual = leer_orden("mish>");
		mostrar_orden(actual);
	} while (strcmp("exit", actual->args[0]) != 0);
	return 0;
}
