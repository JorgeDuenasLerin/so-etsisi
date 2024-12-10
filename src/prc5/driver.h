/* ------------------------------------------------------------------------*/
/*                                 driver.h                                */
/* ----------------------------------------------------------------------- */
/*      driver de un disco implementado mediante un fichero de imagen      */
/* ----------------------------------------------------------------------- */

#ifndef H_OPS_DRIVER
#define H_OPS_DRIVER

#define tamSector 512
#define NUMBLOQUES 1024 /* 1 K */

int inicDisk(const char *nombreImagen); /* retorna num. sectores */

void cerrarDisk(void);

int leerSector(unsigned s, void *bufer);

int escribirSector(unsigned s, void *bufer);

#endif /* H_OPS_DRIVER */
