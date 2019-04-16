#include "hexdecimal.h"
#include "binary.h"
#include "octal.h"
#include "error.h"

Hexdecimal::Hexdecimal(){
    HexNumb="0";
    sgn=false;
    dim=HexNumb.size();
}

Hexdecimal::Hexdecimal(const int& n){
    *this=new Hexdecimal(toHex(n)->getNumber());
}

Hexdecimal::Hexdecimal(const QString& HN){
    HexNumb=HN;
    sgn=0;
    if((HexNumb[0]=='#')||(HexNumb[0]=='+'))
        HexNumb.remove(0,1);

    if(HexNumb[0]=='-'){ // check sign
        sgn=1;
        HexNumb.remove(0,1);
    }

    HexNumb=HexNumb.toUpper();
    int h=0;
    while(HexNumb[h]!=HexNumb[HexNumb.size()]){ //checks the HexNumb is correct with an iterator until the address of end
        if((HexNumb[h]<'0'||HexNumb[h]>'9')&&(HexNumb[h]<'A'||HexNumb[h]>'F'))
            throw new std::invalid_argument("Illegal hexdecimal number");
        h++;
    }
    while(HexNumb[0]=='0'){
        HexNumb.remove(0,1);
    }
    dim=HexNumb.length();
}

Hexdecimal::Hexdecimal(const Number& HN){
    *this = new Hexdecimal(HN.toTen());
}

Hexdecimal::Hexdecimal(const Number* HN){
    std::cout<<"Costruttore con Number* "<<'\n';
    *this = new Hexdecimal(HN->toTen());
}

Hexdecimal::Hexdecimal(const Hexdecimal& HN){
    *this=new Hexdecimal(HN.getNumber());
}
Hexdecimal::Hexdecimal(const Hexdecimal* HN){
    *this = new Hexdecimal(HN->getNumber());
}

Number* Hexdecimal::toHex(const int& n){
    bool sign=0;
    QString result="";
    int t = n;
    if(t<0){
        sign = 1;
        t=0-(t);
    }
    if(t==0){
        result.push_front('0');
    }
    while (t>0) {
        int pr = t%16;
        if(pr<=9){
            result.push_front(pr+'0');
        }else{
            result.push_front(pr-10+'A');
        }
        t=t/16;
    }
    if(sign){
        result.push_front("-");
    }
    return new Hexdecimal(result);
}
int Hexdecimal::toTen() const{
    QString HN=HexNumb;
    int result=0;
    int power=0;
    int dim=HN.size()-1;
    while(dim>=0){ //start conversion
        int t=HN[dim].digitValue();
        if(t==-1)
            t=HN[dim].toLatin1()-'A'+10;
        result = result + t*pow(16,power);
        dim--;
        power++;
        t=0;
    }
    if(sgn)
        result=0-result;
    return result;
}

QString Hexdecimal::getNumber() const{
    QString tmp=HexNumb;
    if(sgn)    //sign check
        tmp.push_front("-");
    return tmp;
}

void Hexdecimal::operator=(const Number* n){
    Hexdecimal(n->toTen());// costructor for int &
}
void Hexdecimal::operator=(const Number& n){
   Hexdecimal(n.toTen());// costructor for int &
}

void Hexdecimal::operator=(const int& n){
    Hexdecimal(toHex(n)->getNumber()); // costructor for int &
}

void Hexdecimal::operator=(const Hexdecimal* n){
    HexNumb = QString::fromStdString(n->HexNumb.toStdString()); //deep copy for QString
    sgn = n->sgn;
    dim = n->dim;
}

void Hexdecimal::operator=(const Hexdecimal& n){
    HexNumb = QString::fromStdString(n.HexNumb.toStdString()); //deep copy for QString
    sgn = n.sgn;
    dim = n.dim;
}

/**
 * @brief Hexdecimal::operator !
 * @return Hexdecimal* !this
 */

Number* Hexdecimal::operator !()const{
    QString fullF;
    int h=dim;
    while(h>0){
        fullF.push_back('F');
    }
    Hexdecimal tmp(fullF);
    Hexdecimal toReturn=tmp-abs(*this);
    toReturn.sgn=sgn;
    return new Hexdecimal(toReturn);
}

/**
 * @brief Hexdecimal::operator +
 * @param n object Number
 * @return Hexdecimal*
 */

Number* Hexdecimal::operator +(const Number& n) const{
    Hexdecimal tmp(n.toTen());
    return (*this)+tmp;

}

/**
 * @brief Hexdecimal::operator +
 * @param n object Number
 * @return Hexdecimal*
 */

Hexdecimal* Hexdecimal::operator+(const Hexdecimal& addend) const{
    if(sgn==addend.sgn){ // check concordant sign
        int i1=dim-1;
        int i2=addend.dim-1;
        QString result;
        int carry=0;
        int a1=0;
        int a2=0;
        while(!(i1==-1 && i2==-1)){ //check that both strings are ended
            if(i1>=0){
                a1 = HexNumb[i1].digitValue();
                if(a1==-1)// check that the character in i1 is a in hexdec for conversion
                    a1=HexNumb[i1].toLatin1()-'A'+10;
                i1--;
            }else{
                a1=0;
            }
            if(i2>=0){
                a2 = addend.HexNumb[i2].digitValue();
                if(a2==-1)// check that the character in i2 is a in hexdec for conversion
                    a2=addend.HexNumb[i2].toLatin1()-'A'+10;
                i2--;
            }else{
                a2=0;
            }
            int ps = a1+a2+carry;
            if(ps>=16){
                carry=1;
                ps-=16;}
            else{
                carry=0;
            }
            QChar c = ps+'0';
            if(ps>9){
                c=ps-10+'A';
            }
            result.push_front(c);
        }
        if(carry>0){
            QChar c = carry+'0';
            if(carry>9){
                c=carry-10+'A';
            }
            result.push_front(c);
        }
        if(sgn){
            result.push_front('-');
        }
        return new Hexdecimal(result);
    }else{
        Hexdecimal local;
        if(addend.sgn){
            local = addend;
            local.sgn = false;
            return *this-local;
        }else {
            local = this;
            local.sgn = false;
            return addend-local;
        }
    }
}

/**
 * @brief Hexdecimal::operator -
 * @param n object Number
 * @return Hexdecimal*
 */
Number* Hexdecimal::operator -(const Number& n) const{
    Hexdecimal tmp(n.toTen());
    return *this-tmp;
}

/**
 * @brief Hexdecimal::operator -
 * @param n object Number
 * @return Hexdecimal*
 */

Hexdecimal* Hexdecimal::operator-(const Hexdecimal& _subtr) const{
    if(sgn==_subtr.sgn){ // check concordant sign
        Hexdecimal min;
        Hexdecimal subtr;
        int i1=dim-1,i2=subtr.dim-1;
        bool changed= false;
        if(abs(*this)>abs(_subtr)){
            min=this;
            subtr=_subtr;
        }else if(*this==_subtr){
            return new Hexdecimal("0");
        }else{
            changed = true;
            min=_subtr;
            subtr=this;
        }
        i1=min.dim-1;
        i2=subtr.dim-1;
        QString result;
        int carry=0;
        int a1=0;
        int a2=0;
        while(!(i1==-1 && i2==-1)){ //check that both string are ended
            if(i1>=0){
                a1 = min.HexNumb[i1].digitValue();
                if(a1==-1)// check that the character in i1 is a in hexdec for conversion
                    a1=min.HexNumb[i1].toLatin1()-'A'+10;
                i1--;
            }else{
                a1=0;
            }
            if(i2>=0){
                a2 = subtr.HexNumb[i2].digitValue();
                if(a2==-1)// check that the character in i2 is a in hexdec for conversion
                    a2=subtr.HexNumb[i2].toLatin1()-'A'+10;
                i2--;
            }else{
                a2=0;
            }
            int ps = a1-a2-carry;
            if(ps<0){
                carry=1;
                ps+=16;
            }else{
                carry=0;
            }
            QChar c = ps+'0';
            if(ps>9){
                c=ps-10+'A';
            }
            result.push_front(c);
        }
        if(changed){
            if(!sgn){
                result.push_front('-');
            }
        }else{
            if(sgn){
                result.push_front('-');
            }
        }
        return new Hexdecimal(result);
    }else{
        Hexdecimal local;
        if(_subtr.sgn){
            local = this;
            local.sgn = true;
            return _subtr+local;
        }else {
            local = _subtr;
            local.sgn = true;
            return *this+local;
        }
    }
}
/**
 * @brief Hexdecimal::abs
 * @param HN
 * @return Hexdecimal number with the positive sign
 */
Hexdecimal Hexdecimal::abs(const Hexdecimal & HN){
    Hexdecimal _return(HN.HexNumb);
    return _return;
}

/**
 * @brief Hexdecimal::operator *
 * @param n object Number
 * @return Hexdecimal*
 */
Number* Hexdecimal::operator *(const Number& n) const{
    Hexdecimal tmp(n.toTen());
    return (*this)*tmp;
}

Hexdecimal* Hexdecimal::operator *(const Hexdecimal& factor) const{
    const Hexdecimal& local = *this;
    int i1=local.dim-1;
    int i2=factor.dim-1;
    Hexdecimal partial_sums=new Hexdecimal("0");
    int m=factor.toTen();
    while(m>0){ //check that both strings are ended
        partial_sums=partial_sums+local;
        m--;
    }
    partial_sums.sgn=(sgn!=factor.sgn);
    return new Hexdecimal(partial_sums);
}

/**
 * @brief Hexdecimal::operator /
 * @param n object Number
 * @return Hexdecimal*
 */
Number* Hexdecimal::operator /(const Number& n) const{
    Hexdecimal tmp(n.toTen());
    return *this/tmp;
}

Hexdecimal* Hexdecimal::operator /(const Hexdecimal& divisor) const{
    Hexdecimal partial_subs=abs(*this);
    Hexdecimal ldivisor=abs(divisor);
    int a1=0;
    while(partial_subs>=ldivisor){
        a1++;
        partial_subs=partial_subs-ldivisor;
    }

    if(sgn!=divisor.sgn){
        int a=-a1;
        return new Hexdecimal(a);
    }else
        return new Hexdecimal(a1);
}

Number* Hexdecimal::operator%(const Number& n) const{
    Hexdecimal tmp(n.toTen());
    return *this%tmp;
}

Hexdecimal* Hexdecimal::operator%(const Hexdecimal& divisor) const{
    Hexdecimal partial_subs=abs(*this);
    Hexdecimal ldivisor=abs(divisor);
    int a1=0;
    while(partial_subs>=ldivisor){
        a1++;
        partial_subs=partial_subs-ldivisor;
    }
    QString result=partial_subs.getNumber();
    if(sgn!=divisor.sgn)
        result.push_front('-');
    return new Hexdecimal(result);
}

/**
 * @brief Hexdecimal::operator <
 * @param n
 * @return true if the Hexdecimal object value is less than Number object value
 */
bool Hexdecimal::operator<(const Number& n) const{
    Hexdecimal tmp(n.toTen());
    return *this<tmp;
}

/**
 * @brief Hexdecimal::operator <=
 * @param n
 * @return true if the Hexdecimal object value is less than or equal Number object value
 */
bool Hexdecimal::operator<=(const Number& n) const{
    Hexdecimal tmp(n.toTen());
    return *this<=tmp;
}

/**
 * @brief Hexdecimal::operator >=
 * @param n
 * @return true if the Hexdecimal object value is greater or equal Number object value
 */
bool Hexdecimal::operator>=(const Number& n) const{
    Hexdecimal tmp(n.toTen());
    return *this>=tmp;
}

/**
 * @brief Hexdecimal::operator >
 * @param n
 * @return true if the Hexdecimal object value is greater than Number object value
 */
bool Hexdecimal::operator>(const Number& n) const{
    Hexdecimal tmp(n.toTen());
    return *this>tmp;
}

/**
 * @brief Hexdecimal::operator ==
 * @param n
 * @return true if the Hexdecimal object value is equal Number object value
 */

bool Hexdecimal::operator==(const Number& n) const{
    Hexdecimal tmp(n.toTen());
    return *this==tmp;
}

/**
 * @brief Hexdecimal::operator <
 * @param n
 * @return true if the Hexdecimal object value is less than Hexdecimal object value
 */
bool Hexdecimal::operator<(const Hexdecimal& n) const{
    return (comparison(*this,n)=='<');
}

/**
 * @brief Hexdecimal::operator <=
 * @param n
 * @return true if the Hexdecimal object value is less than or equal Hexdecimal object value
 */
bool Hexdecimal::operator<=(const Hexdecimal& n) const{
    return (comparison(*this,n)=='<')^(comparison(*this,n)=='=');
}
/**
 * @brief Hexdecimal::operator >=
 * @param n
 * @return true if the Hexdecimal object value is graeter than or equal Hexdecimal object value
 */
bool Hexdecimal::operator>=(const Hexdecimal& n) const{
    return (comparison(*this,n)=='>')^(comparison(*this,n)=='=');
}
/**
 * @brief Hexdecimal::operator >
 * @param n
 * @return true if the Hexdecimal object value is greater than Hexdecimal object value
 */
bool Hexdecimal::operator>(const Hexdecimal& n) const{
    return (comparison(*this,n)=='>');
}
/**
 * @brief Hexdecimal::operator ==
 * @param n
 * @return true if the Hexdecimal object value is equal Hexdecimal object value
 */
bool Hexdecimal::operator==(const Hexdecimal& n) const{
    return (comparison(*this,n)=='=');
}


char Hexdecimal::comparison(const Hexdecimal& _l, const Hexdecimal& _r){
    char status='=';
    if(_l.sgn==_r.sgn){
        if(_l.sgn){
            Hexdecimal l=_l;
            Hexdecimal r=_r;
            //l.sgn=false;
            //r.sgn=false;
            status = comparison(r,l);
        }else{
            if(_l.dim==_r.dim){
                unsigned int iterator=0;
                while (iterator<_l.dim && status=='=') {
                    if(_l.HexNumb[iterator]==_r.HexNumb[iterator])
                        ++iterator;
                    else{
                        if(_l.HexNumb[iterator]>_r.HexNumb[iterator]){
                            status='>';
                        }else{
                            status='<';
                        }
                    }
                }
            }else{
                if(_l.dim>_r.dim)
                    status='>';
                else
                    status='<';
            }
        }

    }else{
        if(_l.sgn)
            status='<';
        else
            status='>';
    }
    return status;
}

void Hexdecimal::stdo() const{
    std::cout<<getNumber().toStdString();
}
