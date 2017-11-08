/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              P L U G B O X                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Abstraktion einer Interruptvektortabelle. Damit kann man die Adresse der  */
/* Behandlungsroutine fuer jeden Hardware-, Softwareinterrupt und jede       */
/* Prozessorexception festlegen.                                             */
/*****************************************************************************/

#ifndef __Plugbox_include__
#define __Plugbox_include__

#include "guard/gate.h"

class Plugbox
 {
private:
    Plugbox(const Plugbox &copy); // Verhindere Kopieren

public:
    static const timer = 32;
    static const keyboard = 33;

    Plugbox ();
    void assign (unsigned int slot, Gate& gate);
    Gate& report (unsigned int slot);
 };

#endif
