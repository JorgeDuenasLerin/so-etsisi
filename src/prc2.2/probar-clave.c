#include "probar-clave.h"
#define _MINIX
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int probar_clave(const char clave[], const char salt_hash[], const char salt[])
{
    // TODO: rellenar según la especificación contenida en probar-clave.h
}

void test_probar_clave(void)
{
    struct 
    {
        const char* clave;
        const char* hash;
        const char* salt;
        int es_clave_correcta;
    } casos[] = {
        /* Caso 1: Clave correcta */
        { "pw2003", "mBgpqZDwMlac6", "mB", 1 },
        
        /* Caso 2: Clave incorrecta */
        { "pw2004", "mBVT5KtbUzAeM", "mB", 0 },
        
        /* Caso 3: Clave vacía */
        { "", "mBgpqZDwMlac6", "$6$saltsalt", 0 },
        
        /* Caso 4: Salt incorrecto */
        { "pw2003", "mBgpqZDwMlac6", "mC", 0 },
        
        /* Caso 5: Hash nulo */
        { "pw2003", NULL, "mB", 0 },
        
        /* Caso 6: Salt nulo */
        { "pw2003", "mBgpqZDwMlac6", NULL, 0 }
    };
    int i;
    int todos_pasados = 1;

    for (i = 0; i < sizeof(casos) / sizeof(casos[0]); i++)
    {
        int resultado = probar_clave(casos[i].clave, casos[i].hash, casos[i].salt);
        
        printf("C%d: clave='%s', hash='%s', salt='%s'. Res. esperado: %s, obtenido: %d\n",
               i + 1,
               casos[i].clave,
               casos[i].hash ? casos[i].hash : "NULL",
               casos[i].salt ? casos[i].salt : "NULL",
               casos[i].es_clave_correcta ? "0" : "!= 0",
               resultado);
        
        if ((casos[i].es_clave_correcta && resultado == 0) 
            || (!casos[i].es_clave_correcta && resultado != 0))
        {
            printf("Test %d: PASADO\n", i + 1);
        } else 
        {
            printf("Test %d: FALLADO\n", i + 1);
            todos_pasados = 0;
        }
    }
    if (todos_pasados)
    {
        printf("Todos los tests han pasado\n");
    } else
    {
        printf("Algunos tests han fallado\n");
    }
}
