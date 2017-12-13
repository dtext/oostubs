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
#include <syscall/guarded_scheduler.h>
#include "watch.h"

void Watch::windup() {
    plugbox.assign(plugbox.timer, *this);
    pic.allow(pic.timer);
}

bool Watch::prologue() {
    return true;
}

void Watch::epilogue() {
    scheduler.Scheduler::resume();
}
