#include "procesos.h"

/*
Este fichero está completo y no necesita ser modificado.
*/

int main(int argc, char *argv[]) {
    struct proceso* procesos[MAX_PROCESOS] = {0};

    anadir_proceso(procesos, 0, 1, "/bin/bash", PREPARADO);
    anadir_proceso(procesos, 1, 2, "/bin/top", EJECUTANDO);
    anadir_proceso(procesos, 2, 3, "/bin/unzip", BLOQUEADO);

    listar_procesos(procesos);

    liberar_procesos(procesos);

    return 0;
}