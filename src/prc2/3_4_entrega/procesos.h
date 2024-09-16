#ifndef PROCESOS_H /* Protege de inclusión múltiple */
#define PROCESOS_H

/* constantes */
#define MAX_PROCESOS 4
#define PREPARADO    0
#define EJECUTANDO   1
#define BLOQUEADO    2

#define MAX_EJECUTABLE 50
#define MEM_ERROR -1

/* representa a un proceso */ 
extern struct proceso;

/* función para añadir un proceso al array procesos en la posición ix */
int anadir_proceso(struct proceso* procesos[], int ix, int pid,
                   char ejecutable[MAX_EJECUTABLE], int estado);

/* función para listar */
void listar_procesos(struct proceso* procesos[]);

/* función para liberar */
void liberar_procesos(struct proceso* procesos[]);

#endif /* PROCESOS_H */
