/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Standard Unterbrechungsbehandlung.                                        */
/*****************************************************************************/
/* Hier muesst ihr selbst Code vervollstaendigen */
/* Hier muesst ihr selbst Code vervollstaendigen */

/* INCLUDES */

#include "device/panic.h"
#include "device/cgastr.h"
#include "machine/cpu.h"

Panic panic;

bool Panic::prologue() {
    cout << "Kernel Panic :(";
    cout.flush();
    cpu.halt();
    return false; // this is here to avoid compiler errors
}


