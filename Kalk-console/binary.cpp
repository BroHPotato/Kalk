#include "binary.h"

Binary::Binary(const QString& n){
  int i=0;
  bool minimal=false;
  sign=0;
  if(n.size()>32) throw new std::overflow_error("too long");
  if(n.isEmpty()) throw new std::invalid_argument("Illegal binary number");
  if(n[0]=='+' || n[0]=='-'){
    if (n[0]=='-')
        sign=1;
    ++i;
  }
  for (; i<n.size(); ++i) {
    if (n[i]!='0' && n[i]!='1') throw new std::invalid_argument("Illegal binary number");
    if (n[i]!='0' || minimal || i==n.size()-1){
      minimal=true;
      mod+=n[i];
    }
  }
}

Binary::Binary(const Number& n){
    Binary(n.toTen());
}

Binary::Binary(const int& n){
    Binary* temp=toBin(n);
    sign=temp->sign;
    mod=temp->mod;
}

Binary* Binary::toBin(const int& n){
  QString bin;
  int bit=1;
  int t=n;
  QChar sign='+';
  if (n<0){ sign='-'; t=-n;}//set sign(default =0)
  for (int c=t; c>=pow(2, bit); ++bit);//calculate the length in bit
  for (int i=1; i<bit; ++i){//translation in binary
    if ((t-pow(2, bit-i))>=0){ bin+='1'; t-=pow(2, bit-i);}
    else bin+='0';
  }
  if (t==1) bin+='1';
  else bin+='0';
  return new Binary(sign+bin);
}

QString Binary::getNumber() const{
  if(sign==0)
    return '+'+mod;
  return '-'+mod;
}

int Binary::toTen() const{
  int temp=0;
  for (int i=0; i<mod.size(); ++i) {
    if(mod[i]=='1')
      temp+=pow(2, (mod.size()-i-1));
  }
  if(sign==1)
    temp=-temp;
  return temp;
}
/*
Number* Binary::toHex() const{
  return new Hexdecimal(this->toTen());
}

Number* Binary::toOct() const{
  QString temp;
  QString cut=mod;
  QString oct;
  int sum;
  while(!cut.isEmpty()){
    sum=0;
    temp=cut.remove(cut.size()-4, 3);
    for (int i=temp.size()-1; i>=0; --i) {
      if(temp[i]=='1')
        sum+=pow(2, (temp.size()-i-1));
    }
    oct=sum+oct;
  }
  if (sign==1)  oct='-'+oct;
  else  oct='+'+oct;
  return new Octal(oct);
}

Number* Binary::toBin() const{
  return new Binary(*this);
}
*/
Number* Binary::operator+(const Number& n) const{
  Binary b(n.toTen());
  QChar s;
  if (sign==b.sign) {//concordi
    if (sign==0)  s='+';//set sign
    else  s='-';
    if (mod.size()>=b.mod.size())  return new Binary(s+sum(b.mod, mod));
    else    return new Binary(s+sum(mod, b.mod));
  } else {
    if (mod.size()>=b.mod.size()) {
        if (sign==0)  s='+';//set sign
        else  s='-';
        return new Binary(s+dif(b.mod, mod));
    } else {
        if (b.sign==0)  s='+';//set sign
        else  s='-';
      return new Binary(s+dif(mod, b.mod));
    }
  }
}

Number* Binary::operator-(const Number& n) const{
  Binary b(n.toTen());
  QChar s;
  if (sign==b.sign) {//concordi
    if (mod.size()>=b.mod.size()) {
        if (sign==0)  s='+';//set sign
        else  s='-';
      return new Binary(s+dif(b.mod, mod));
    } else {
        if (b.sign==0)  s='+';//set sign
        else  s='-';
      return new Binary(s+dif(mod, b.mod));
    }
  } else {
    if (sign==0)  s='+';//set sign
    else s='-';
    if (mod.size()>=b.mod.size())  return new Binary(s+sum(b.mod, mod));
    else  return new Binary(s+sum(mod, b.mod));
    }
}

Number* Binary::operator*(const Number& n) const{
  Binary b(n.toTen());
  QString molt=mod;
  QChar s;
  QString temp;
  if(sign==b.sign)  s='+';
  else s='-';
  for (int i=b.mod.size()-1; i>=0; --i){
    if (b.mod[i]=='1'){
      if (temp.size()<molt.size())  temp=sum(temp, molt);
      else  temp=sum(molt, temp);
    }
    molt.append('0');
  }
  return new Binary(s+temp);
}

Number* Binary::operator/(const Number& n) const{
  Binary b(n.toTen());
  if (b.mod=="0") throw new std::domain_error("divide by 0");
  int count=0;
  Number* a1= new Binary(mod);
  Binary a2(b.mod);
  if (*a1<a2) return new Binary(0);
  else
  for (; *a1>=a2; ++count)
    a1=(*a1-a2);
  if(sign!=b.sign)  count=-count;
  return new Binary(count);
}

Number* Binary::operator%(const Number& n) const{
    Binary b(n.toTen());
    if (b.mod=="0") throw new std::domain_error("divide by 0");
    int count=0;
    Number* a1= new Binary(mod);
    Number* a3;
    Binary a2(b.mod);
    if (*a1<a2) return a1;
    else
    for (; *a1>=a2; ++count)
      a1=(*a1-a2);
    if(sign==1){
        a3=a1;
        a1=new Binary(-(a1->toTen()));
        delete a3;
    };
    return a1;
}

Number* Binary::operator!() const{
  QString temp;
  QChar s;
  for (int i=0; i<mod.size(); ++i){
    if (mod[i]=='1')    temp[i]='0';
    else    temp[i]='1';
  }
  if(sign)  s='-';
  else s='+';
  return new Binary(s+temp);
}

void Binary::operator=(const Number& n){
  Binary b(n.toTen());
  sign=b.sign;
  mod=b.mod;
}

void Binary::operator=(const int& n){
    Binary b(n);
    sign=b.sign;
    mod=b.mod;
}

bool Binary::operator<(const Number& n)const{
  Binary b(n.toTen());
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

bool Binary::operator<=(const Number& n)const{
  Binary b(n.toTen());
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

bool Binary::operator>=(const Number& n)const{
  Binary b(n.toTen());
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

bool Binary::operator>(const Number& n)const{
  Binary b(n.toTen());
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

bool Binary::operator==(const Number& n)const{
  Binary b(n.toTen());
  if (mod.size()==b.mod.size() && sign==b.sign){
    for (int i=mod.size()-1; i>=0; --i)
      if(mod[i]!=b.mod[i])  return false;
    return true;
  } else  return false;
}

bool Binary::operator!=(const Number& n)const{
  Binary b(n.toTen());
  if (mod.size()==b.mod.size() && sign==b.sign){
    for (int i=mod.size()-1; i>=0; --i)
      if(mod[i]!=b.mod[i])  return true;
    return false;
  } else  return true;
}

void Binary::stdo() const{
  if(sign) std::cout << '-'+mod.toStdString()+'\n';
  std::cout << '+'+mod.toStdString()+'\n';
}

QString Binary::sum(QString l1, QString l2){//lenght l1<= lenght l2 needed
  QString temp;
  QChar rest='0';
  for (int i=l1.size()-1; i>=0; --i){//scorro il più piccolo
    if ((l1[i]=='1' && l2[i+(l2.size()-l1.size())]=='1' && rest=='1') || (l1[i]=='1' && l2[i+(l2.size()-l1.size())]=='0' && rest=='0') || (l1[i]=='0' && l2[i+(l2.size()-l1.size())]=='1' && rest=='0') || (l1[i]=='0' && l2[i+(l2.size()-l1.size())]=='0' && rest=='1')) temp='1'+temp;//xor con resto
    else  temp='0'+temp;
    if((l1[i]=='1' && l2[i+(l2.size()-l1.size())]=='1' && rest=='0') || (l1[i]=='1' && l2[i+(l2.size()-l1.size())]=='0' && rest=='1') || (l1[i]=='0' && l2[i+(l2.size()-l1.size())]=='1' && rest=='1') || (l1[i]=='1' && l2[i+(l2.size()-l1.size())]=='1' && rest=='1'))  rest='1';//controllo il resto
    else rest='0';
  }
  for (int i=(l2.size()-l1.size())-1; i>=0; --i){//finisco di scorrere il più grande
    if ((l2[i]=='1' && rest=='0') || (l2[i]=='0' && rest=='1')) temp='1'+temp;
    else  temp='0'+temp;
    if (l2[i]=='1' && rest=='1') rest='1';//controllo il resto
    else rest='0';
  }
  if (rest=='1')  return '1'+temp;//controllo overflow
  return temp;
}

QString Binary::dif(QString l1, QString l2){//l1<=l2
  QString temp;
  QChar rest='0';
  for (int i=l1.size()-1; i>=0; --i){//scorro il più piccolo
    if ((l1[i]=='1' && l2[i+(l2.size()-l1.size())]=='1' && rest=='1') || (l1[i]=='1' && l2[i+(l2.size()-l1.size())]=='0' && rest=='0') || (l1[i]=='0' && l2[i+(l2.size()-l1.size())]=='1' && rest=='0') || (l1[i]=='0' && l2[i+(l2.size()-l1.size())]=='0' && rest=='1')) temp='1'+temp;//xor con resto
    else  temp='0'+temp;
    if ((l2[i+(l2.size()-l1.size())]=='0' && l1[i]=='1') || (l1[i]==l2[i+(l2.size()-l1.size())] && rest=='1')) rest='1';//controllo il prestito
    else rest='0';
  }
  for (int i=(l2.size()-l1.size())-1; i>=0; --i){//finisco di scorrere il più grande
    if ((l2[i]=='1' && rest=='0') || (l2[i]=='0' && rest=='1')) temp='1'+temp;
    else  temp='0' + temp;
    if (l2[i]=='0' && rest=='1') rest='1';//controllo il prestito
    else rest='0';
  }
  return temp;
}

void Binary::minimal(){
  while(mod[0]=='0' && mod.size()!=1) mod.remove(0,1);
}
