/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              G U A R D I A N                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Zentrale Unterbrechungsbehandlungsroutine des Systems.                    */
/* Der Parameter gibt die Nummer des aufgetretenen Interrupts an.            */
/*****************************************************************************/

/* INCLUDES */

/* FUNKTIONEN */

#include "machine/plugbox.h"
#include "guard/guard.h"

extern "C" void guardian(unsigned int slot);

/* GUARDIAN: Low-Level Interrupt-Behandlung. Die Funktion wird spaeter noch */
/*           erweitert.                                                     */

void guardian(unsigned int slot) {
    Gate *g = &plugbox.report(slot);  // obtain device driver
    if (g->prologue()) {              // execute its prologue
        guard.relay(g);               // if need be: queue its epilog
    }

}
