#include <number.h>
#include <binary.h>
#include <octal.h>
#include <hexdecimal.h>
#include <colour.h>
#include <iostream>
Number* default_costructor_string(char* _type,char* _content){
    switch (_type[0]) {
    case 'H':
        return new Hexdecimal(_content);
        break;
    case 'B':
        return new Binary(_content);
        break;
    case 'O':
        return new Octal(_content);
        break;
    }
    throw std::invalid_argument("Type interted is not valid");
}

Number* default_costructor_int(char* _type,char* _content){
    switch (_type[0]) {
    case 'H':
        return new Hexdecimal(_content);
        break;
    case 'B':
        return new Binary(_content);
        break;
    case 'O':
        return new Octal(_content);
        break;
    }
    throw std::invalid_argument("Type interted is not valid");
}

int main(int argc,char* argv[]) {
  Number* t1=default_costructor_string(argv[1],argv[2]);
  Number* t2=default_costructor_string(argv[4],argv[5]);
  Number* r;
  switch (argv[3][0]) {
  case '+':
        r=(*t1)+(*t2);
      break;
  case '-':
        r=(*t1)-(*t2);
      break;
  case 'x':
        r=(*t1)*(*t2);
      break;
  case '/':
        r=(*t1)/(*t2);
      break;
  case '%':
        r=(*t1)%(*t2);
      break;
  default:
      break;
  }

  std::cout<< r->toTen()<<'\n';
  return 0;
}
