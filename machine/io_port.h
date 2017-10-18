/* $Id$ */

#ifndef __io_port_include__
#define __io_port_include__

/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              I O _ P O R T                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Diese Klasse dient dem Zugriff auf die Ein-/Ausgabe Ports des PCs. Beim   */
/* PC gibt es einen gesonderten I/O-Adressraum, der nur mittels der Maschi-  */
/* neninstruktionen 'in' und 'out' angesprochen werden kann. Ein IO_Port-    */
/* Objekt wird beim Erstellen an eine Adresse des I/O-Adressraums gebunden   */
/* und kann dann fuer byte- oder wortweise Ein- oder Ausgaben verwendet wer- */
/* den.                                                                      */
/*****************************************************************************/

/* BENUTZTE FUNKTIONEN */

extern "C" void outb  (int port, int value);
extern "C" void outw (int port, int value);
extern "C" int inb   (int port);
extern "C" int inw  (int port);

/* KLASSENDEFINITION */

class IO_Port
 {
      // Kopieren erlaubt!

      // Adresse im I/O-Adressraum
      int address;
   public:
      IO_Port (int a) : address (a) {};

      // OUTB: Byteweise Ausgabe eines Wertes ueber einen I/O-Port.
      void outb (int val) const
       { 
	 ::outb (address, val); 
       };

      // OUTW: Wortweise Ausgabe eines Wertes ueber einen I/O-Port.
      void outw (int val) const
       { 
	 ::outw (address, val); 
       };

      // INB: Byteweises Einlesen eines Wertes ueber einen I/O-Port.
      int inb () const
       { 
	 return ::inb (address); 
       };

      // INW: Wortweises Einlesen eines Wertes ueber einen I/O-Port.
      int inw () const
       { 
	 return ::inw (address); 
       };
 };

#endif
