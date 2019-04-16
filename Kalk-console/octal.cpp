#include "octal.h"

Octal::Octal(const QString& n){
  int i=0;
  bool minimal=false;
  sign=0;
  if(n.size()>32) throw new std::overflow_error("too long");
  if(n.isEmpty()) throw new std::invalid_argument("Illegal octal number");
  if(n[0]=='+' || n[0]=='-'){
    if (n[0]=='-')  sign=1;
    ++i;
  }
  for (; i<n.size(); ++i) {
    if (n[i]<'0' || n[i]>'7') throw new std::invalid_argument("Illegal octal number");
    if (n[i]!='0' || minimal || i==n.size()-1){
      minimal=true;
      mod+=n[i];
    }
  }
}

Octal::Octal(const Number& n){
  Octal(n.toTen());
}

Octal::Octal(const int& n){
    Octal* temp=toOct(n);
    sign=temp->sign;
    mod=temp->mod;
}

Octal* Octal::toOct(const int& n){
  QString oct;
  int bit=1;
  int p=0;
  int t=n;
  QChar sign='+';
  if (n<0){ sign='-'; t=-n;}//set sign(default =0)
  for (int c=t; c+1>=pow(8, bit); ++bit);//calculate the length in bit
  for (int i=1; i<bit; ++i){//translation in octal
    if ((t-pow(8, bit-i))>=0){
        p=(pow(8, bit-i));
        oct+=(t/p)+'0';
        t=t%p;}
    else    oct+='0';
  }
  oct+=t+'0';
  return new Octal(sign+oct);
}

QString Octal::getNumber() const{
  if(sign==0)
    return '+'+mod;
  return '-'+mod;
}

int Octal::toTen() const{
    QMap<QChar, int> octm;
    octm['7']=7;
    octm['6']=6;
    octm['5']=5;
    octm['4']=4;
    octm['3']=3;
    octm['2']=2;
    octm['1']=1;
    octm['0']=0;
  int temp=0;
  for (int i=0; i<mod.size(); ++i) {
    if(mod[i]!='0')
      temp+=pow(8, (mod.size()-i-1))*octm.value(mod[i]);
  }
  if(sign==1)
    temp=-temp;
  return temp;
}
/*
Number* Octal::toHex() const{
    QMap<int, QString> hexdec;
    hexdec[15]="F";
    hexdec[14]="E";
    hexdec[13]="D";
    hexdec[12]="C";
    hexdec[11]="B";
    hexdec[10]="A";
    hexdec[9]="9";
    hexdec[8]="8";
    hexdec[7]="7";
    hexdec[6]="6";
    hexdec[5]="5";
    hexdec[4]="4";
    hexdec[3]="3";
    hexdec[2]="2";
    hexdec[1]="1";
    hexdec[0]="0";
    QMap<QChar, int> octm;
    octm['7']=7;
    octm['6']=6;
    octm['5']=5;
    octm['4']=4;
    octm['3']=3;
    octm['2']=2;
    octm['1']=1;
    octm['0']=0;
  QString temp;
  QString cut=mod;
  QString hex;
  int sum;
  while(!cut.isEmpty()){
    sum=0;
    temp=cut.remove(cut.size()-3, 2);
    for (int i=temp.size()-1; i>=0; --i) {
      if(temp[i]!='0')
        sum+=pow(2, (temp.size()-i-1))*octm.value(temp[i]);
    }
    hex=hexdec.value(sum)+hex;
  }
  if (sign==1)  hex='-'+hex;
  else  hex='+'+hex;
  return new Hexdecimal(hex);
}

Number* Octal::toOct() const{
  return new Octal(*this);
}

Number* Octal::toBin() const{
    QMap<QChar, int> octm;
    octm['7']=7;
    octm['6']=6;
    octm['5']=5;
    octm['4']=4;
    octm['3']=3;
    octm['2']=2;
    octm['1']=1;
    octm['0']=0;
  QString bin;
  QString temp;
  int n;
  for (int i=mod.size()-1; i>=0; --i){
    n=octm.value(mod[i]);
    for (int j=1; n>1; ++j){//translation in binary
      if ((n-pow(2, 3-j))>=0){ bin+='1'; n-=pow(2, 3-j);}
      else bin+='0';
    }
    if (n==1) bin+='1';
    else bin+='0';
    temp=bin+temp;
  }
  if (sign==1)  temp='-'+temp;
  else  temp='+'+temp;
  return new Binary(temp);
}
*/
Number* Octal::operator+(const Number& n) const{
  Octal b(n.toTen());
  QChar s;
  if(sign==b.sign){
    if (sign==0)  s='+';//set sign
    else s='-';
    if(mod.size()>=b.mod.size()) return new Octal(s+sum(mod, b.mod));
    else  return new Octal(s+sum(b.mod, mod));
  } else {
    if(mod.size()>=b.mod.size()) {
      if (b.sign==0)  s='+';//set sign
      else  s='-';
      return new Octal(s+dif(b.mod, mod));
    } else {
      if (b.sign==0)  s='+';//set sign
      else  s='-';
      return new Octal(s+dif(mod, b.mod));
    }
  }
}

Number* Octal::operator-(const Number& n) const{
  Octal b(n.toTen());
  QChar s;
  if(sign==b.sign){
    if (mod.size()>=b.mod.size()) {
        if (sign==0)  s='+';//set sign
        else  s='-';
      return new Octal(s+dif(mod, b.mod));
    } else {
      if (b.sign==0)  s='+';//set sign
      else  s='-';
      return new Octal(s+dif(b.mod, mod));
    }
  } else {
    if (sign==0)  s='+';//set sign
    else s='-';
    if(mod.size()>=b.mod.size()) return new Octal(s+sum(mod, b.mod));
    else  return new Octal(s+sum(b.mod, mod));
  }
}

Number* Octal::operator*(const Number& n) const{
    QMap<QChar, int> octm;
    octm['7']=7;
    octm['6']=6;
    octm['5']=5;
    octm['4']=4;
    octm['3']=3;
    octm['2']=2;
    octm['1']=1;
    octm['0']=0;
  Octal b(n.toTen());
  QString molt=mod;
  QString temp;
  QChar s;
  if(sign==b.sign)  s='+';
  else s='-';
  for (int i=b.mod.size()-1; i>=0; --i){
    for (int j=octm.value(b.mod[i]); j>0; --j) {
      if (temp.size()<molt.size())  temp=sum(molt, temp);
      else  temp=sum(temp, molt);
    }
    molt.append('0');
  }
  return new Octal(s+temp);
}

Number* Octal::operator/(const Number& n) const{
  Octal b(n.toTen());
  if (b.mod=="0") throw new std::domain_error("divide by 0");
  int count=0;
  Number* a1= new Octal(mod);
  Octal a2(b.mod);
  if (*a1<a2) return new Octal(0);
  else
  for (; *a1>=a2; ++count)
    a1=(*a1-a2);
  if(sign!=b.sign)  count=-count;
  return new Octal(count);
}

Number* Octal::operator%(const Number& n) const{
  Octal b(n.toTen());
  if (b.mod=="0") throw new std::domain_error("divide by 0");
  int count=0;
  Number* a1= new Octal(mod);
  Number* a3;
  Octal a2(b.mod);
  if (*a1<a2) return a1;
  else
  for (; *a1>=a2; ++count)
    a1=(*a1-a2);
  if(sign==1){
      a3=a1;
      a1=new Octal(-(a1->toTen()));
      delete a3;
  };
  return a1;
}
/*tested*/
Number* Octal::operator!() const{
    QMap<QChar, int> octm;
    octm['7']=7;
    octm['6']=6;
    octm['5']=5;
    octm['4']=4;
    octm['3']=3;
    octm['2']=2;
    octm['1']=1;
    octm['0']=0;
  QString temp;
  QChar s;
  for (int i=0; i<mod.size(); ++i){
    temp[i]=7-octm.value(mod[i])+'0';
  }
  if(sign)  s='-';
  else s='+';
  return new Octal(s+temp);
}

void Octal::operator=(const Number& n){
  Octal b(n.toTen());
  sign=b.sign;
  mod=b.mod;
}

void Octal::operator=(const int& n){
    Octal b(n);
    sign=b.sign;
    mod=b.mod;
}

bool Octal::operator<(const Number& n)const{
  Octal b(n.toTen());
  if (sign==1 && b.sign==0) return true;
  else if (sign==0 && b.sign==1)  return false;
  if(sign==0){
    if (mod.size()>b.mod.size()) return false;
    else if (mod.size()<b.mod.size()) return true;
    else {
      for (int i=mod.size()-1; i>=0; --i)
        if(mod[i]<b.mod[i])  return true;
        else if(mod[i]>b.mod[i])  return false;
      return false;
    }
  }
  else{
    if (mod.size()>b.mod.size()) return true;
    else if (mod.size()<b.mod.size()) return false;
    else {
      for (int i=mod.size()-1; i>=0; --i)
        if(mod[i]>b.mod[i])  return true;
        else if(mod[i]<b.mod[i])  return false;
      return false;
    }
  }
}

bool Octal::operator<=(const Number& n)const{
  Octal b(n.toTen());
  if (sign==1 && b.sign==0) return true;
  else if (sign==0 && b.sign==1)  return false;
  if(sign==0){
    if (mod.size()>b.mod.size()) return false;
    else if (mod.size()<b.mod.size()) return true;
    else {
      for (int i=mod.size()-1; i>=0; --i)
        if(mod[i]>b.mod[i])  return false;
        else if(mod[i]<b.mod[i])  return true;
      return true;
    }
  }
  else{
    if (mod.size()>b.mod.size()) return true;
    else if (mod.size()<b.mod.size()) return false;
    else {
      for (int i=mod.size()-1; i>=0; --i)
        if(mod[i]<b.mod[i])  return false;
        else if(mod[i]>b.mod[i])  return true;
      return true;
    }
  }
}

bool Octal::operator>=(const Number& n)const{
  Octal b(n.toTen());
  if (sign==1 && b.sign==0) return false;
  else if (sign==0 && b.sign==1)  return true;
  if(sign==0){
    if (mod.size()>b.mod.size()) return true;
    else if (mod.size()<b.mod.size()) return false;
    else {
      for (int i=mod.size()-1; i>=0; --i)
        if(mod[i]>b.mod[i])  return true;
        else if(mod[i]<b.mod[i])  return false;
      return true;
    }
  }
  else{
    if (mod.size()>b.mod.size()) return false;
    else if (mod.size()<b.mod.size()) return true;
    else {
      for (int i=mod.size()-1; i>=0; --i)
        if(mod[i]<b.mod[i])  return true;
        else if(mod[i]>b.mod[i])  return false;
      return true;
    }
  }
}

bool Octal::operator>(const Number& n)const{
  Octal b(n.toTen());
  if (sign==1 && b.sign==0) return false;
  else if (sign==0 && b.sign==1)  return true;
  if(sign==0){
    if (mod.size()>b.mod.size()) return true;
    else if (mod.size()<b.mod.size()) return false;
    else {
      for (int i=mod.size()-1; i>=0; --i)
        if(mod[i]>b.mod[i])  return true;
        else if(mod[i]<b.mod[i])  return false;
      return false;
    }
  }
  else{
    if (mod.size()>b.mod.size()) return false;
    else if (mod.size()<b.mod.size()) return true;
    else {
      for (int i=mod.size()-1; i>=0; --i)
        if(mod[i]<b.mod[i])  return true;
        else if(mod[i]>b.mod[i])  return false;
      return false;
    }
  }
}

bool Octal::operator==(const Number& n)const{
  Octal b(n.toTen());
  if (mod.size()==b.mod.size() && sign==b.sign){
    for (int i=mod.size()-1; i>=0; --i)
      if(mod[i]!=b.mod[i])  return false;
    return true;
  } else  return false;
}

bool Octal::operator!=(const Number& n)const{
  Octal b(n.toTen());
  if (mod.size()==b.mod.size() && sign==b.sign){
    for (int i=mod.size()-1; i>=0; --i)
      if(mod[i]!=b.mod[i])  return true;
    return false;
  } else  return true;
}

void Octal::stdo() const{
  if (sign) std::cout << '-'+mod.toStdString()+'\n';
  std::cout << '+'+mod.toStdString()+'\n';
}

QString Octal::sum(QString s1, QString s2){//s1>=s2
    QMap<QChar, int> octm;
    octm['7']=7;
    octm['6']=6;
    octm['5']=5;
    octm['4']=4;
    octm['3']=3;
    octm['2']=2;
    octm['1']=1;
    octm['0']=0;
  QString ris;
  int a1;
  int a2;
  int temp=0;
  int rip=0;
  for (int i=s2.size()-1; i>=0; --i){
    a1=octm.value(s1[i+(s1.size()-s2.size())]);
    a2=octm.value(s2[i]);
    temp=a1+a2+rip;
    if (temp>7) {rip=temp/8; temp=temp%8;}
    else rip=0;
    ris=temp+'0'+ris;
  }
  for(int i= s1.size()-s2.size()-1; i>=0; --i){
    a1=octm.value(s1[i]);
    temp=a1+rip;
    if (temp>7) {rip=temp/8; temp=temp%8;}
    else rip=0;
    ris=temp+'0'+ris;
  }
  if(rip) ris=rip+'0'+ris;
  return ris;
}

QString Octal::dif(QString s1, QString s2){//s1>=s2
    QMap<QChar, int> octm;
    octm['7']=7;
    octm['6']=6;
    octm['5']=5;
    octm['4']=4;
    octm['3']=3;
    octm['2']=2;
    octm['1']=1;
    octm['0']=0;
  QString ris;
  int a1;
  int a2;
  int temp=0;
  int pre=0;
  for (int i=s2.size()-1; i>=0; --i){
    a1=octm.value(s1[i+(s1.size()-s2.size())]);
    a2=octm.value(s2[i]);
    temp=a1-a2-pre;
    if (temp<0) {pre=1; temp=temp+8;}
    else pre=0;
    ris=temp+'0'+ris;
  }
  for(int i= s1.size()-s2.size()-1; i>=0; --i){
    a1=octm.value(s1[i]);
    temp=a1-pre;
    if (temp<0) {pre=1; temp=temp+8;}
    else pre=0;
    ris=temp+'0'+ris;
  }
  return ris;
}

void Octal::minimal(){
  while(mod[0]=='0' && mod.size()!=1) mod.remove(0,1);
}
