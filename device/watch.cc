/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              W A T C H                                    */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/*****************************************************************************/

#include <machine/plugbox.h>
#include <machine/pic.h>
#include <syscall/guarded_organizer.h>
#include <meeting/bellringer.h>
#include "watch.h"

void Watch::windup() {
    plugbox.assign(plugbox.timer, *this);
    pic.allow(pic.timer);
}

bool Watch::prologue() {
    return true;
}

void Watch::epilogue() {
    organizer.Scheduler::resume();
    bellringer.check();
}
