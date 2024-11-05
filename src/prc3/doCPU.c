/* ----------------------------------------------------------------------- */
/*   doCPU_0.c: consume mucha CPU de manera continua                       */
/* ----------------------------------------------------------------------- */
/*                     formato: doCPU_0 [ iteraciones ]                    */
/* ----------------------------------------------------------------------- */

#include <stdio.h>

int main ( int argc, char * argv [ ] )
{
    unsigned i, j ;
    unsigned iteraciones ;

    if (argc == 1)
    { 
        iteraciones = 10 ;
    }
    else if (sscanf(argv[1], "%u", &iteraciones) != 1)
    {
        return 1;
    }
    
    for ( i = 0 ; i < iteraciones ; i++ )
    {
        for ( j = 1 ; j < 10000 ; j++ )
        {
             j = (unsigned)(((double)j*(double)j)/(double)j) ;
        }   
    }
    return 0 ;
}
