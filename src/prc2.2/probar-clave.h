/**
 * Funciones para probar una clave con un salt y un hash.
 */
#ifndef PROBAR_CLAVE_H /* Para evitar inclusiones dobles */
#define PROBAR_CLAVE_H

/**
 * Comprueba si la clave es válida.
 * @param clave Cadena de caracteres que contiene la clave a probar.
 * @param salt_hash Cadena de caracteres que contiene el hash de la clave con el salt
 *        antepuesto.
 * @param salt Cadena de caracteres que contiene el salt.
 * @return 0 si la clave es válida, distinto de 0 en caso contrario.
 */
extern int probar_clave(const char clave[], const char salt_hash[], const char salt[]);

/**
 * Función de test para probar_clave.
 */
extern void test_probar_clave(void);

#endif
