/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                 B E L L                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Eine "Glocke" ist eine abstrakte Basisklasse, die das Ausloesen einer     */
/* Aktivitaet nach einer bestimmten Wartezeit erlaubt.                       */
/* Dazu besitzt sie einen Zaehler, der vom "Gloeckner" (Bellringer) ver-     */
/* waltet wird.                                                              */
/*****************************************************************************/

#ifndef __Bell_include__
#define __Bell_include__

#include <object/chain.h>

class Bell : public Chain {
private:
    Bell(const Bell &copy);
    int counter;
    bool counter_zero;

public:
    Bell() {}

    /**
     * @return current wait counter value
     */
    int wait() {
        return counter;
    }

    /**
     * Set wait counter to value
     * @param value value to set the counter to
     */
    void wait(int value) {
        counter = value;
    }

    /**
     * Decrement the counter value
     */
    void tick() {
        if (!run_down()) {
            --counter;
            counter_zero = (counter <= 0);
        }
    }

    /**
     * @return whether or not the counter ran down
     */
    bool run_down() {
        return counter_zero;
    }

    /**
     * Called by Bellringer when counter ran down
     */
    virtual void ring() = 0;

};

#endif
