/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                   G U A R D E D _ S E M A P H O R E                       */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Systemaufrufschnittstelle zum Semaphor.                                   */
/*****************************************************************************/

#include "guard/secure.h"
#include "meeting/semaphore.h"
#include "guarded_semaphore.h"

void Guarded_Semaphore::p() {
    Secure section;
    Semaphore::p();
}

void Guarded_Semaphore::v() {
    Secure section;
    Semaphore::v();
}
