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

extern "C" void guardian(unsigned int slot);

/* GUARDIAN: Low-Level Interrupt-Behandlung. Die Funktion wird spaeter noch */
/*           erweitert.                                                     */

void guardian(unsigned int slot) {
    if (plugbox.report(slot).prologue()) {
        plugbox.report(slot).epilogue(); // TODO
    }

}
