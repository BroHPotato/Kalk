#ifndef HEXDECIMAL_H
#define HEXDECIMAL_H
#include "number.h"
#include "binary.h"
#include "octal.h"
class Hexdecimal : public Number
{
private:
    QString HexNumb;
    bool sgn;
    unsigned int dim;
    static char comparison(const Hexdecimal& _l, const Hexdecimal& _r);
public:
    Hexdecimal();
    Hexdecimal(const int &);
    Hexdecimal(const QString&);
    Hexdecimal(const Number& HN);
    Hexdecimal(const Number* HN);
    Hexdecimal(const Hexdecimal&);
    Hexdecimal(const Hexdecimal*);
    static Number* toHex(const int&);
    void operator=(const Number&);
    void operator=(const Number*);
    void operator=(const int&);
    void operator=(const Hexdecimal*);
    void operator=(const Hexdecimal&);
    Number* operator+(const Number&) const;
    Number* operator-(const Number&) const;
    Number* operator*(const Number&) const;
    Number* operator/(const Number&) const;
    Number* operator%(const Number&) const;
    Number* operator! () const;
    bool operator<(const Number&) const;
    bool operator<=(const Number&) const;
    bool operator>=(const Number&) const;
    bool operator>(const Number&) const;
    bool operator==(const Number&) const;
    QString getNumber() const;
    void stdo() const;
    int toTen() const;
    static Hexdecimal abs(const Hexdecimal&);
    Hexdecimal* operator+(const Hexdecimal&) const;
    Hexdecimal* operator-(const Hexdecimal&) const;
    Hexdecimal* operator/(const Hexdecimal&) const;
    Hexdecimal* operator%(const Hexdecimal&) const;
    Hexdecimal* operator*(const Hexdecimal&) const;
    bool operator<(const Hexdecimal&) const;
    bool operator<=(const Hexdecimal&) const;
    bool operator>=(const Hexdecimal&) const;
    bool operator>(const Hexdecimal&) const;
    bool operator==(const Hexdecimal&) const;



};
#endif // HEXDECIMAL_H
