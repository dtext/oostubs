/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          D I S P A T C H E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung des Dispatcher.                                           */
/* Der Dispatcher verwaltet den life-Pointer, der die jeweils aktive         */
/* Koroutine angibt. mit go() wird der life Pointer initialisiert und die    */
/* erste Koroutine gestartet, alle weiteren Kontextwechsel werden mit        */
/* dispatch() ausgeloest. active() liefert den life Pointer zurueck.         */
/*****************************************************************************/

#ifndef __dispatch_include__
#define __dispatch_include__

#include "thread/coroutine.h"

/**
 * Dispatcher manages the pointer to the currently active coroutine and
 * executes the context switches between coroutines.
 */
class Dispatcher {
private:
    Dispatcher(const Dispatcher &copy); // Verhindere Kopieren

protected:
    Coroutine *activeCoroutine;

public:
    Dispatcher() {
        activeCoroutine = 0;
    }

    /**
     * Makes first the active coroutine and calls its go() function
     * @param first the first coroutine in the system
     */
    void go(Coroutine &first);

    /**
     * Switches from the active coroutine to the next coroutine.
     * @param next the coroutine to switch to
     */
    void dispatch(Coroutine &next);

    /**
     * @return the currently active coroutine
     */
    Coroutine *active() {
        return activeCoroutine;
    }
};

#endif
