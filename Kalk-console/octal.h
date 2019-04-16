#ifndef OCTAL_H
#define OCTAL_H

#include "number.h"
#include <QString>
#include <QMap>
#include <cmath>


class Octal: public Number{
public:
  //di classe
  Octal(const QString& n="0");//DONE
  Octal(const Number& n);//DONE
  Octal(const int& n);//DONE
  static Octal* toOct(const int& n);//DONE

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
  virtual void operator=(const int& n);//DONE
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
    static QString sum(QString s1, QString s2);//DONE
    static QString dif(QString s1, QString s2);//DONE
    void minimal();//DONE
};

#endif // OCTAL_H
