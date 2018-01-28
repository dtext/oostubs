/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                         A P P L I C A T I O N                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Application definiert die einzige Anwendung von OO-Stubs.      */
/*****************************************************************************/

/* INCLUDES */

#include <thread/coroutine.h>
#include <syscall/guarded_scheduler.h>
#include <machine/key.h>
#include <syscall/guarded_keyboard.h>
#include <syscall/guarded_buzzer.h>
#include <device/cgastr.h>
#include "user/appl.h"
#include "snake/data.h"

Guarded_Semaphore coutSemaphore(1);

void Application::action() {

}
