#ifndef NUMBER_H
#define NUMBER_H
#include <QString>
#include <QMap>
#include <QtMath>
#include <iostream>
class Number{

public:
    virtual void operator=(const Number& n) =0; //overloading standard operator = assigns values on the current object;
    virtual Number* operator+(const Number& n) const =0;//overloading standard operator + returns the result of a sum of two objects
    virtual Number* operator-(const Number& n) const =0;//overloading standard operator - returns the result of a subtraction of two objects
    virtual Number* operator*(const Number& n) const =0;//overloading standard operator * returns the result of a multiplication of two objects
    virtual Number* operator/(const Number& n) const =0;//overloading standard operator / returns the result of a division of two objects
    virtual Number* operator%(const Number& n) const =0;//overloading standard operator % returns the mod of a division of two objects
    virtual Number* operator!() const =0;//overloading standard operator ! returns the object logically negate
    virtual bool operator<(const Number& n)const =0;//overloading standard operator < returns true if the first object is lower than the second
    virtual bool operator<=(const Number& n)const =0;//overloading standard operator <= returns true if the first object is less than or equal to the second
    virtual bool operator>=(const Number& n)const =0;//overloading standard operator >= returns true if the first object is greater or equal to the second
    virtual bool operator>(const Number& n)const =0;//overloading standard operator > returns true if the first object is bigger than the second
    virtual bool operator==(const Number& n)const =0;//overloading standard operator == returns true if the first object is equal to the second
    /*virtual Number* toBin() const =0;//returns the conversion of the current object in Binary form
    virtual Number* toHex() const =0;//returns the conversion of the current object in Octal form
    virtual Number* toOct() const =0;//returns the conversion of the current object in Hexdecimal form*/
    virtual int toTen() const =0;//returns the conversion of the current object in base ten
    virtual QString getNumber() const =0;//returns QString with the current number base and sign
    virtual void stdo() const =0;//inject in std::ostream the getNumber QString;

};

#endif // NUMBER_H
