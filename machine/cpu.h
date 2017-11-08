/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                                   C P U                                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Implementierung einer Abstraktion fuer den Prozessor.                     */
/* Derzeit wird nur angeboten, Interrupts zuzulassen, zu verbieten oder den  */
/* Prozessor anzuhalten.                                                     */
/*****************************************************************************/

#ifndef __CPU_include__
#define __CPU_include__

// Die folgenden drei Funktionen werden in cpu.asm implementiert.
extern "C" void int_enable ();
extern "C" void int_disable ();
extern "C" void cpu_idle ();
extern "C" void cpu_halt ();

class CPU
 {
private:
    CPU(const CPU &copy); // Verhindere Kopieren
public:
CPU() {}
    // Erlauben von (Hardware-)Interrupts
    inline void enable_int ()
     {
       int_enable ();
     }

    // Interrupts werden ignoriert/verboten
    inline void disable_int ()
     {
       int_disable ();
     }

    // Prozessor bis zum naechsten Interrupt anhalten
    inline void idle ()
      {
	cpu_idle ();
      }

    // Prozessor anhalten
    inline void halt ()
      {
	cpu_halt ();
      }
 };

#endif
