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
        }
    }

    /**
     * @return whether or not the counter ran down
     */
    bool run_down() {
        return counter <= 0;
    }

    /**
     * Called by Bellringer when counter ran down
     */
    virtual void ring() = 0;

};

#endif
