/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                    G U A R D E D _ S C H E D U L E R                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Scheduler.                                  */
/*****************************************************************************/

void Guarded_Scheduler::ready(Thread &that) {
    Secure section;
    scheduler.ready(that);
}

void Guarded_Scheduler::exit() {
    Secure section;
    scheduler.exit();
}

void Guarded_Scheduler::kill(Thread &that) {
    Secure section;
    scheduler.kill(that);
}

void Guarded_Scheduler::resume() {
    Secure section;
    scheduler.resume();
}
