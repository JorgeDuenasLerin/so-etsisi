/* ------------------------------------------------------------------------*/
/*                                 sf_defs.h                               */
/* ----------------------------------------------------------------------- */
/*                                                                         */
/* ----------------------------------------------------------------------- */

#ifndef H_SF_DEFS
#define H_SF_DEFS

#include "driver.h"                                           /* tamSector */

#define TAMBLOQUE           tamSector                               /* 512 */
#define NUMBLOQUES              1024                                /* 1 K */
#define NUMINODOS               1000 
#define TAMINODO  sizeof(descInodo_t)                                /* 64 */
#define TAMPTR       sizeof(unsigned)                                 /* 4 */
#define NUMPTRD                    10        /* punteros directos       10 */
#define NUMPTRI                     1        /* punteros indirectos      1 */
#define NUMPTR2                     1        /* punteros directos dobles 1 */
#define TAMENTRADA  sizeof(entrada_t)                                /* 32 */
#define TAMNUMINODO  sizeof(unsigned)                                 /* 4 */ 

typedef struct
{
    unsigned tamBloque ; 
    unsigned numBloques ;
    unsigned numINodos ;
    unsigned tamINodo ;
    unsigned tamPtr ;
    unsigned numPtrD ;
    unsigned numPtrI ;
    unsigned numPtr2 ;
    unsigned tamEntrada ;
    unsigned tamNumINodo ; 
} superbloque_t ;                      /* sizeof(superbloque_t) = 40 bytes */

#define LIBRE      0
#define FICHERO    1
#define DIRECTORIO 2
#define ENLACESIMB 3

typedef struct
{
    unsigned tipo ;           /* fichero, directorio, enlaceSimbolico, ... */
    unsigned tam ;
    unsigned numEnlaces ;
    unsigned permisos ; 
    unsigned ptrBlqD [ 10 ] ; 
    unsigned ptrBlqI [  1 ] ;
    unsigned ptrBlq2 [  1 ] ;
} descInodo_t ;                              /* sizeof(inodo_t) = 64 bytes */

typedef struct
{
    unsigned nino ;                                    /* numero de i-nodo */
    char     nombre [ 28 ] ;
} entrada_t ;                              /* sizeof(entrada_t) = 32 bytes */

#endif /* H_SF_DEFS */
