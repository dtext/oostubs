/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                       K E Y B O A R D _ C O N T R O L L E R               */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Tastaturcontroller des PCs.                                               */
/*****************************************************************************/

#ifndef __Keyboard_Controller_include__
#define __Keyboard_Controller_include__

#include "machine/io_port.h"
#include "machine/key.h"

class Keyboard_Controller
 {
private:
    Keyboard_Controller(const Keyboard_Controller &copy); // Verhindere Kopieren
private:
    unsigned char code;
    unsigned char prefix;
    Key gather;
    char leds;

    // Benutzte Ports des Tastaturcontrollers
    const IO_Port ctrl_port; // Status- (R) u. Steuerregister (W)
    const IO_Port data_port; // Ausgabe- (R) u. Eingabepuffer (W)

    // Bits im Statusregister
    enum { outb = 0x01, inpb = 0x02, auxb = 0x20 };

    // Kommandos an die Tastatur
    struct kbd_cmd
     {
	enum { set_led = 0xed, set_speed = 0xf3 };
     };
    enum { cpu_reset = 0xfe };

    // Namen der LEDs
    struct led
     {
	  enum { caps_lock = 4, num_lock = 2, scroll_lock = 1 };
     };

    // Antworten der Tastatur
    struct kbd_reply
     {
	  enum { ack = 0xfa };
     }; 

    // Konstanten fuer die Tastaturdekodierung
    enum { break_bit = 0x80, prefix1 = 0xe0, prefix2   = 0xe1 };

    static unsigned char normal_tab[];
    static unsigned char shift_tab[];
    static unsigned char alt_tab[];
    static unsigned char asc_num_tab[];
    static unsigned char scan_num_tab[];
         
    // KEY_DECODED: Interpretiert die Make und Break-Codes der Tastatur und
    //              liefert den ASCII Code, den Scancode und Informationen
    //              darueber, welche zusaetzlichen Tasten wie Shift und Ctrl
    //              gedrueckt wurden. Ein Rueckgabewert true bedeutet, dass
    //              das Zeichen komplett ist, anderenfalls fehlen noch Make
    //              oder Breakcodes.
    bool key_decoded ();

    // GET_ASCII_CODE: ermittelt anhand von Tabellen aus dem Scancode und
    //                 den gesetzten Modifier-Bits den ASCII Code der Taste.
    void get_ascii_code ();
public:

   // KEYBOARD_CONTROLLER: Initialisierung der Tastatur: alle LEDs werden
   //                      ausgeschaltet und die Wiederholungsrate auf
   //                      maximale Geschwindigkeit eingestellt.
   Keyboard_Controller ();

   // KEY_HIT: Dient der Tastaturabfrage nach dem Auftreten einer Tastatur-
   //          unterbrechung. Wenn der Tastendruck abgeschlossen ist und
   //          ein Scancode, sowie gegebenenfalls ein ASCII Code emittelt
   //          werden konnte, werden diese in Key zurueckgeliefert. Anderen-
   //          falls liefert key_hit () einen ungueltigen Wert zurueck, was
   //          mit Key::valid () ueberprueft werden kann.
   Key key_hit ();

   // REBOOT: Fuehrt einen Neustart des Rechners durch. Ja, beim PC macht
   //         das der Tastaturcontroller.
   void reboot ();

   // SET_REPEAT_RATE: Funktion zum Einstellen der Wiederholungsrate der
   //                  Tastatur. delay bestimmt, wie lange eine Taste ge-
   //                  drueckt werden muss, bevor die Wiederholung einsetzt.
   //                  Erlaubt sind Werte zwischen 0 (minimale Wartezeit)
   //                  und 3 (maximale Wartezeit). speed bestimmt, wie
   //                  schnell die Tastencodes aufeinander folgen soll.
   //                  Erlaubt sind Werte zwischen 0 (sehr schnell) und 31
   //                  (sehr langsam).
   void set_repeat_rate (int speed, int delay);

   // SET_LED: setzt oder loescht die angegebene Leuchtdiode.
   void set_led (char led, bool on);
 };

#endif
