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

#define SHORT_DIGIT 5
#define INT_DIGIT 10
#define LONG_DIGIT 20

#include "object/o_stream.h"

O_Stream &O_Stream::convert(unsigned long value) {

    short numeralSystem = 10;
    switch (currentOutputFormat) {
        case BIN:
            numeralSystem = 2;
            break;
        case OCT:
            numeralSystem = 8;
            break;
        case DEC:
            numeralSystem = 10;
            break;
        case HEX:
            numeralSystem = 16;
            break;
        default:
            break;
    }

    char buffer[100];
    int i;
    for (i = 0; value > 0; i++) {
        short temp = value % numeralSystem;
        if (temp >= 10)
            buffer[i] = temp + 55;
        else
            buffer[i] = temp + 48;
        value /= numeralSystem;
    }

    for (; i >= 0; i--) {
        this->put(buffer[i]);
    }

    return *this;
}

O_Stream &O_Stream::operator<<(unsigned char c) {
    if (currentOutputFormat != DEC)
        return convert((unsigned long) c);
    this->put(c);
    return *this;
}

// TODO: Convert to unsigned
O_Stream &O_Stream::operator<<(char c) {
    this->put(c);
    return *this;
}

O_Stream &O_Stream::operator<<(unsigned short number) {

    if (currentOutputFormat != DEC)
        return convert(number);

    char buffer[SHORT_DIGIT];
    int i;
    for (i = SHORT_DIGIT - 1; i >= 0; i--) {
        buffer[i] = (number % 10) + 48;
        number /= 10;
        if (number <= 0)
            break;
    }

    for (; i < SHORT_DIGIT; i++) {
        this->put(buffer[i]);
    }

    return *this;

}

O_Stream &O_Stream::operator<<(short number) {

    char buffer[SHORT_DIGIT];
    if (number < 0) {
        number *= -1;
        this->put('-');
    }

    return *this << (unsigned short) number;

}

O_Stream &O_Stream::operator<<(unsigned int number) {

    if (currentOutputFormat != DEC)
        return convert(number);

    char buffer[INT_DIGIT];
    int i;

    for (i = INT_DIGIT - 1; i >= 0; i--) {
        buffer[i] = (number % 10) + 48;
        number /= 10;
        if (number <= 0)
            break;
    }

    for (; i < INT_DIGIT; i++) {
        this->put(buffer[i]);
    }

    return *this;

}

O_Stream &O_Stream::operator<<(int number) {

    char buffer[INT_DIGIT];
    if (number < 0) {
        number *= -1;
        this->put('-');
    }

    return *this << (unsigned int) number;

}

O_Stream &O_Stream::operator<<(unsigned long number) {

    if (currentOutputFormat != DEC)
        return convert(number);

    char buffer[LONG_DIGIT];
    int i;

    for (i = LONG_DIGIT - 1; i >= 0; i--) {
        buffer[i] = (number % 10) + 48;
        number /= 10;
        if (number <= 0)
            break;
    }

    for (; i < LONG_DIGIT; i++) {
        this->put(buffer[i]);
    }

    return *this;

}

O_Stream &O_Stream::operator<<(long number) {

    char buffer[LONG_DIGIT];
    if (number < 0) {
        number *= -1;
        this->put('-');
    }

    return *this << (unsigned long) number;

}

O_Stream &O_Stream::operator<<(void *pointer) {
    OutputFormat tempOutputFormat = currentOutputFormat;
    return *this << hex << (long) pointer << tempOutputFormat;
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
