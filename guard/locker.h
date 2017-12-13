/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                               L O C K E R                                 */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Locker implementiert eine Sperrvariable, die verwendet wird,   */
/* um kritische Abschnitte zu schuetzen. Die Variable zeigt allerdings nur   */
/* an, ob der kritische Abschnitt frei ist. Ein eventuelles Warten und der   */
/* Schutz der fuer diese Klasse notwendigen Zaehlfunktion muss ausserhalb    */
/* erfolgen.                                                                 */
/*****************************************************************************/

#ifndef __Locker_include__
#define __Locker_include__

#include "machine/cpu.h"
#include "device/cgastr.h"
#include "device/panic.h"

class Locker {
private:
    Locker(const Locker &copy); // Verhindere Kopieren
protected:
    bool locked;
public:
    Locker() { locked = false; };

    inline void enter() {
        if (locked) {
            panic.setError(const_cast<char *>("Locker error: Second call of enter"));
            panic.prologue();
        }
        locked = true;
    }

    inline void retne() {
        if (!locked) {
            panic.setError(const_cast<char *>("Locker error: Second call of retne"));
            panic.prologue();
        }
        locked = false;
    }

    inline bool avail() {
        return !locked;
    }
};

#endif
