/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              P L U G B O X                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Abstraktion einer Interruptvektortabelle. Damit kann man die Behandlungs- */
/* routine fuer jeden Hardware-, Softwareinterrupt und jede Prozessor-       */
/* exception festlegen.                                                      */
/*****************************************************************************/
#include "device/panic.h"

Plugbox::Plugbox() {
    for (int slot = 0; slot < 64; ++slot) {
        gates[slot] = panic;
    }
}

void Plugbox::assign(unsigned int slot, Gate &gate) {
    gates[slot] = gate;
}

Gate &Plugbox::report(unsigned int slot) {
    return gates[slot];
}
