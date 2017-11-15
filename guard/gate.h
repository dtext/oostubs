/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                  G A T E                                  */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Klasse von Objekten, die in der Lage sind, Unterbrechungen zu behandeln.  */
/*****************************************************************************/

#ifndef __Gate_include__
#define __Gate_include__

#include "object/chain.h"

class Gate : Chain {

private:
    bool inQueue = false;

public:
    virtual bool prologue() = 0;

    virtual void epilogue() {};

    void queued(bool q) {
        inQueue = q;
    }

    bool queued() {
        return inQueue;
    }
};

#endif
