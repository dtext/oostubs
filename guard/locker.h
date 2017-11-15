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

class Locker
 {
private:
    Locker(const Locker &copy); // Verhindere Kopieren
/* Hier muesst ihr selbst Code vervollstaendigen */ 
 };

#endif
