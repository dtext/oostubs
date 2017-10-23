/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                       S T R I N G B U F F E R                             */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse Stringbuffer stellt einen Puffer fuer die Sammlung von Zeichen */
/* zur Darstellung auf dem Bildschirm oder anderen Ausgabegeraeten bereit.   */
/* Die Ausgabe der Zeichen erfolgt, sobald der Puffer voll ist oder wenn     */
/* explizit die Methode flush() aufgerufen wird.                             */
/* Da Stringbuffer geraeteunabhaengig sein soll, ist flush() eine virtuelle  */
/* Methode, die von den abgeleiteten Klassen definiert werden muss.          */
/*****************************************************************************/

#ifndef __strbuf_include__
#define __strbuf_include__

#define BUFFER_SIZE 4000

enum OutputFormat {
    BIN, OCT, DEC, HEX
};

class Stringbuffer {
private:
    Stringbuffer(const Stringbuffer &copy); // Verhindere Kopieren
    int i = 0;

protected:
    char buffer[BUFFER_SIZE];

public:
    OutputFormat currentOutputFormat;

    Stringbuffer() {
        currentOutputFormat = DEC;
    }

    void put(char c);

    int get_length();

    void setOutputFormat(OutputFormat newOutputFormat);

    virtual void flush() = 0;
};

#endif
