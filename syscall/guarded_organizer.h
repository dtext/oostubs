/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ O R G A N I Z E R                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Organizer.                                  */
/*****************************************************************************/

#ifndef __Guarded_Organizer_include__
#define __Guarded_Organizer_include__

#include "syscall/thread.h"
#include "thread/organizer.h"

class Guarded_Organizer
        : public Organizer {
private:
    Guarded_Organizer(const Guarded_Organizer &copy); // Verhindere Kopieren
public:
    Guarded_Organizer() {}
/* Hier muesst ihr selbst Code vervollstaendigen */
};

extern Guarded_Organizer organizer;

#endif
