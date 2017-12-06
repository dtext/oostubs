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

class Application : public Entrant {
private:
    Application(const Application &copy); // Verhindere Kopieren

public:

    Application(void *tos) : Entrant(tos) {}

    void action();
};

#endif
