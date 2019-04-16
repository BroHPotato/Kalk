#include "colour.h"

Colour::Colour(const QString& _r,const QString _g, const QString _b){
    if(_r.size()>2 || _g.size()>2 ||_b.size()>2){
        throw new std::invalid_argument("Illegal colour definition");
    }
    try{
        R=new Hexdecimal(_r);
        G=new Hexdecimal(_g);
        B=new Hexdecimal(_b);
    }catch (const std::invalid_argument e){
        std::string common_error="Illegal hexdecimal number";
        if(e.what()==common_error)
            throw new std::invalid_argument("Illegal colour definition");
        else
            throw e;
    }
}

Colour::Colour(const Colour& c){
        R=c.R;
        G=c.G;
        B=c.B;
}

Colour::Colour(const int& _r,const int& _g, const int& _b){
    if(_r>255 || _g>255 ||_b>255){
        throw new std::invalid_argument("Illegal colour definition");
    }
    R=new Hexdecimal(_r);
    G=new Hexdecimal(_g);
    B=new Hexdecimal(_b);
}

Colour::Colour(const QString& c){
    int pos=2;
    if(c[0]=='#'){
        if(c.size()>7)
            throw new std::invalid_argument("Illegal colour definition");
        else
            pos++;
    }
    else {
        if(c.size()>6)
            throw new std::invalid_argument("Illegal colour definition");
    }
    QString _r = c.left(pos);
    QString _g = c.mid(pos,2);
    QString _b = c.right(2);
    Colour(_r,_g,_b);

}

Colour* Colour::operator+(const Colour& c) const{
    Hexdecimal tR = R+c.R;
    Hexdecimal tG = G+c.G;
    Hexdecimal tB = B+c.B;
    if(tR.toTen()>255)
        tR=new Hexdecimal("FF");
    if(tG.toTen()>255)
        tG=new Hexdecimal("FF");
    if(tB.toTen()>255)
        tB=new Hexdecimal("FF");
    return new Colour(tR.getNumber(),tG.getNumber(),tB.getNumber());
}

Colour* Colour::operator-(const Colour& c) const{
    Hexdecimal tR = R-c.R;
    Hexdecimal tG = G-c.G;
    Hexdecimal tB = B-c.B;
    if(tR.toTen()<0)
        tR=new Hexdecimal("00");
    if(tG.toTen()<0)
        tG=new Hexdecimal("00");
    if(tB.toTen()<0)
        tB=new Hexdecimal("00");
    return new Colour(tR.getNumber(),tG.getNumber(),tB.getNumber());
}

Colour* Colour::operator!() const{
    return new Colour((!R)->getNumber(),(!G)->getNumber(),(!B)->getNumber());
}

QVector<Colour*> Colour::triPalette(const Colour& c, const int& dist) {
    QVector<Colour*> r;
    r[0]= new Colour(c);
    r[1]= new Colour(c.G.toTen()-dist,c.R.toTen()-dist,c.B.toTen()-dist);
    r[2]= new Colour(c.R.toTen()-dist,c.B.toTen()-dist,c.G.toTen()-dist);
    return r;
}

QVector<Colour*> Colour::quadPalett(const Colour &c){
    QVector<Colour*> r;
    r=triPalette(c);
    r[3]=new Colour(c.B.toTen(),c.R.toTen(),c.G.toTen());
    return r;
}
