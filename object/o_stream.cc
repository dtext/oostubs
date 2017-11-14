/*****************************************************************************/
/* Betriebssysteme                                                           */
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                            O _ S T R E A M                                */
/*                                                                           */
/*---------------------------------------------------------------------------*/
/* Die Klasse O_Stream enthaelt die Definition des << Operators fuer die     */
/* wichtigsten der vordefinierten Datentypen und realisiert somit die        */
/* bekannte Ausgabefunktion der C++ IO_Stream Bibliothek. Zur Zeit wird die  */
/* Darstellung von Zeichen, Zeichenketten und ganzen Zahlen unterstuetzt.    */
/* Ein weiterer << Operator erlaubt die Verwendung von Manipulatoren.        */
/*                                                                           */
/* Neben der Klasse O_Stream sind hier auch die Manipulatoren hex, dec, oct  */
/* und bin fuer die Wahl der Basis bei der Zahlendarstellung, sowie endl     */
/* fuer den Zeilenumbruch definiert.                                         */
/*****************************************************************************/

#include "object/o_stream.h"

O_Stream &O_Stream::convert(unsigned long value) {
    char buffer[128];
    int i;
    for (i = 0; value > 0; i++) {
        short temp = value % currentOutputFormat;
        if (temp >= 10)
            buffer[i] = temp + 55;
        else
            buffer[i] = temp + 48;
        value /= currentOutputFormat;
    }

    i--;
    for (; i >= 0; i--) {
        this->put(buffer[i]);
    }

    return *this;
}

O_Stream &O_Stream::operator<<(unsigned char c) {
    this->put(c);
    return *this;
}

O_Stream &O_Stream::operator<<(char c) {
    return *this << (unsigned char) c;
}

O_Stream &O_Stream::operator<<(unsigned short number) {
    return convert(number);
}

O_Stream &O_Stream::operator<<(short number) {

    if (number < 0) {
        number *= -1;
        this->put('-');
    }

    return *this << (unsigned short) number;

}

O_Stream &O_Stream::operator<<(unsigned int number) {
    return convert(number);
}

O_Stream &O_Stream::operator<<(int number) {

    if (number < 0) {
        number *= -1;
        this->put('-');
    }

    return *this << (unsigned int) number;

}

O_Stream &O_Stream::operator<<(unsigned long number) {
    return convert(number);
}

O_Stream &O_Stream::operator<<(long number) {

    if (number < 0) {
        number *= -1;
        this->put('-');
    }

    return *this << (unsigned long) number;

}

O_Stream &O_Stream::operator<<(void *pointer) {
    return *this << hex << (long) pointer;
}

O_Stream &O_Stream::operator<<(char *text) {

    while (*text != 0) {
        this->put(*text);
        text++;
    }

    return *this;

}

O_Stream &O_Stream::operator<<(O_Stream &(*fkt)(O_Stream &)) {
    return fkt(*this);
}

O_Stream &endl(O_Stream &os) {
    os << '\n';
    return os;
}

O_Stream &bin(O_Stream &os) {
    os.setOutputFormat(BIN);
    return os;
}

O_Stream &oct(O_Stream &os) {
    os.setOutputFormat(OCT);
    return os;
}

O_Stream &dec(O_Stream &os) {
    os.setOutputFormat(DEC);
    return os;
}

O_Stream &hex(O_Stream &os) {
    os.setOutputFormat(HEX);
    return os;
}
