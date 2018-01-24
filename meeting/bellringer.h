/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                          B E L L R I N G E R                              */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Der "Gloeckner" wird im Rahmen der Timer-Epilog Bearbeitung aktiviert.    */
/* Er prueft, ob irgendwelche Glocken (Bell-Objekte) laeuten muessen. Die    */
/* Glocken befinden sich in einer Liste, die der Gloeckner verwaltet.        */
/*****************************************************************************/

#ifndef __Bellringer_include__
#define __Bellringer_include__


#include <object/list.h>
#include <device/cgastr.h>
#include "bell.h"

class Bellringer : public List {
private:
    Bellringer(const Bellringer &copy);
public:
    Bellringer() {}

    /**
     * Rings all bells that need to be rung.
     */
    void check();

    /**
     * Adds a new bell that will be rung after the specified amount of ticks.
     * @param bell the Bell object
     * @param ticks the amount of ticks to wait
     */
    void job(Bell *bell, int ticks);

    /**
     * Removes a bell from the job list.
     * @param bell the bell to be removed
     */
    void cancel(Bell *bell);

};

extern Bellringer bellringer;

#endif
