/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

#ifndef __application_include__
#define __application_include__

#include <thread/entrant.h>
#include <syscall/thread.h>
#include <syscall/guarded_semaphore.h>

class Application : public Thread {
private:
    Application(const Application &copy); // Verhindere Kopieren

public:

    Application(void *tos) : Thread(tos) {}

    void action();
};

extern Guarded_Semaphore coutSemaphore;

#endif
