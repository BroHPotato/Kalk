#ifndef BINARY_H
#define BINARY_H

#include "number.h"
#include <QString>
#include <QMap>
#include <cmath>
#include <iostream>

class Binary: public Number{
public:
  //di classe
    Binary(const QString& n="0");//DONE
    Binary(const Number& n);//DONE
    Binary(const int& n);//DONE
    static Binary* toBin(const int& n);//DONE
  //ereditate
    virtual QString getNumber() const;//DONE
    virtual int toTen() const;//DONE
    /*virtual Number* toHex() const;//DONE
    virtual Number* toOct() const;//DONE
    virtual Number* toBin() const;//DONE*/
    virtual Number* operator+(const Number& n) const;//DONE
    virtual Number* operator-(const Number& n) const;//DONE
    virtual Number* operator*(const Number& n) const;//DONE
    virtual Number* operator/(const Number& n) const;//DONE
    virtual Number* operator%(const Number& n) const;//DONE
    virtual Number* operator!() const;//DONE
    virtual void operator=(const Number& n);//DONE
    virtual void operator=(const int& n);//DONE//operatore nuovo
    virtual bool operator<(const Number& n)const;//DONE
    virtual bool operator<=(const Number& n)const;//DONE
    virtual bool operator>=(const Number& n)const;//DONE
    virtual bool operator>(const Number& n)const;//DONE
    virtual bool operator==(const Number& n)const;//DONE
    virtual bool operator!=(const Number& n)const;//DONE
    virtual void stdo() const;//DONE
private:
    QString mod;
    bool sign;//0=+, 1=-
    static QString sum(QString l1, QString l2);
    static QString dif(QString l1, QString l2);
    void minimal();
};

#endif // BINARY_H
