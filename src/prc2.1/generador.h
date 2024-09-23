/**
 * Generador de palabras de una longitud definida a partir de un alfabeto.
 */

#define OK 0 /* La operación se ha realizado correctamente */

#define ERR_YACONF 1 /* El generador se debe configurar una sola vez */
#define ERR_NOCONF 2 /* Es necesario configurar el generador previamente */ 
#define ERR_PARAM 3 /* Los parámetros de configuración no son válidos */
#define ERR_NOPOS 4 /* La posición indicada no es válida */

/**
 * Configura el generador de palabras. Tiene como parámetros:
 *	alfabeto: cadena de caracteres que contiene los símbolos del alfabeto.
 *	longitud: entero que indica el tamaño de las palabras a generar.
 * Si el generador se ha configurado correctamente, devuelve OK.
 * Si ya se había invocado esta función anteriormente, devuelve ERR_YACONF.
 * Si los parámetros de configuración no son válidos, devuelve ERR_PARAM.
 */
extern int configura_generador(const char* const alfabeto, const int longitud);

/**
 * Genera la palabra que ocupa la posición pos entre todas las palabras que
 * puede generar este generador. Tiene como parámetros:
 *	pos: posición que ocupa la palabra a obtener en orden lexicográfico.
 *	palabra: array de caracteres que recogerá la palabra generada. Debe
 *	tener capacidad suficiente para albergar una palabra de la longitud
 *	configurada previamente.
 * Si se ha generado la palabra solicitada, devuelve OK.
 * Si aún no se había configurado el generador, devuelve ERR_NOCONF y el
 * valor del parámetro palabra será indeterminado.
 * Si se solicita la palabra de una posición negativa o que supera el número
 * de palabras que se pueden generar, devuelve ERR_NOPOS.
 */
extern int genera_palabra(const int pos, char palabra[]);

/**
 * Devuelve el número total de palabras que puede generar este generador.
 * Si no ha sido configurado, el número de palabras que puede generar es 0.
 */
extern int total_palabras(void);

/**
 * Devuelve la longitud de las palabras que van a generar.
 * Si no ha sido configurado, la longitud de las palabras que
 * puede generar es 0.
 */
extern int longitud(void);
