/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                        G U A R D E D _ B U Z Z E R                        */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Schnittstelle von Anwendungsthreads zu Buzzer-Objekten.                   */
/*****************************************************************************/

/* INCLUDES */

#include "syscall/guarded_buzzer.h"
#include "guard/secure.h"

Guarded_Buzzer::~Guarded_Buzzer() {
    Secure secure;
    Buzzer::destructor();
}

void Guarded_Buzzer::set(int ms) {
    Secure secure;
    Buzzer::set(ms);
}

void Guarded_Buzzer::sleep() {
    Secure secure;
    Buzzer::sleep();
}

