#ifndef COLOUR_H
#define COLOUR_H
#include "hexdecimal.h"
#include <QVector>
class Colour
{
    Hexdecimal R;
    Hexdecimal B;
    Hexdecimal G;
public:
    Colour(const QString & ="#00", const QString ="#00", const QString ="#00");
    Colour(const Colour& c);
    Colour(const int& =00,const int& =00, const int& =00);
    Colour(const QString& c);
    Colour* operator+(const Colour&) const;
    Colour* operator-(const Colour&) const;
    Colour* operator!() const;
    QString toStringHex() const;
    QString toStringDec() const;
    static QVector<Colour*> triPalette(const Colour&, const int& =0);
    static QVector<Colour*> quadPalett(const Colour& c);

};
#endif // COLOUR_H
