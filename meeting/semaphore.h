/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                           S E M A P H O R E                               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Semaphore werden zur Synchronisation von Threads verwendet.               */
/*****************************************************************************/

#ifndef __Semaphore_include__
#define __Semaphore_include__

#include "waitingroom.h"

class Semaphore : public Waitingroom {
private:
    Semaphore(const Semaphore &copy); // Verhindere Kopieren

    int c;
public:
    Semaphore(int c);


    void p();

    void v();

    inline void wait() { p(); }

    inline void signal() { v(); }
};

#endif
