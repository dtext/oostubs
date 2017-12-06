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
    char *error;
public:
    Panic() {}

    bool prologue();

    void setError(char *error) {
        this->error = error;
    }
};

extern Panic panic;

#endif

