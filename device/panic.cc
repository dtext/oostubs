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

Panic panic;

void Panic::trigger() {
    cout << "Kernel Panic :(";
    cout.flush();
}

bool Panic::prologue() {
    //TODO
    return false;
}

void Panic::epilogue() {
    //TODO
}

