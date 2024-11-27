
#include "e9_system.h" /* e9_printf */
#include "kernel.h"
#include <sys/vm.h> /* I386_VM_PRESENT, ... , I386_CR0_PG */

typedef unsigned pte_t;
typedef unsigned pde_t;

#define BIOS_DATE 0x000FFFF5
#define CEIL_DIV(x, y) (((x) + (y) - 1) / (y))
#define MEM_SIZE_MB 128

void setup_paging(void)
{
    e9_printf("\n*** En setup_paging() ***\n");

}
