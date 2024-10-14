#define MAX_ARGS 128

/**
 * Estructura de datos que representa una orden:
 * En el campo args[0] va la orden a ejecutar.
 * De args[1] en adelante van los argumentos con los que
 * se quiere ejecutar el programa.
 * la lista de argumentos termina siempre con NULL.
 * Ejemplo: en la orden ls -l /usr args[0] = "ls",
 * args[1] = "-l", args[2] = "/usr" y args[3] = NULL.
 * si entrada o salida son distintos de NULL,
 * se debe redirigir la entrada y/o la salida al
 * fichero cuyo nombre se indica.
 */
struct orden
{
	char* args[MAX_ARGS];
	const char* entrada;
	const char* salida;
};

/**
 * Muestra por la salida estándar el indicador que
 * recibe como parámetro. A continuación lee una línea
 * completa, la analiza y rellena una estructura de datos
 * de tipo struct orden con la información correspondiente.
 */
struct orden* leer_orden(const char* indicador);
