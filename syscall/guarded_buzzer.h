/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         G U A R D E D _ B U Z Z E R                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Schnittstelle von Anwendungsthreads zu Buzzer-Objekten.                   */
/*****************************************************************************/

#ifndef __Guarded_Buzzer_include__
#define __Guarded_Buzzer_include__

#include <meeting/buzzer.h>

class Guarded_Buzzer : public Buzzer {
private:
    Guarded_Buzzer(const Guarded_Buzzer &copy); // Verhindere Kopieren
public:
    Guarded_Buzzer() {}

    virtual ~Guarded_Buzzer();

    void set(int ms);

    void sleep();
};

#endif
