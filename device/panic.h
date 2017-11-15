/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 P A N I C                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Standard Unterbrechungsbehandlung.                                        */
/*****************************************************************************/

#ifndef __panic_include__
#define __panic_include__

/* INCLUDES */

#include "guard/gate.h"

class Panic : public Gate {
private:
    Panic(const Panic &copy); // Verhindere Kopieren
public:
    Panic() {}

    void trigger();

    bool prologue();

    void epilogue();
};

extern Panic panic;

#endif

