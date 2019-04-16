#include "view.h"
#include "tastierino.h"

view::view(QWidget *parent) : QWidget(parent)
{
    tast = new tastierino(Base::Dec, this);
    input = new QString();
}

void view::addInput0(){
    *input+='0';
    std::cout<<input->toStdString()<<'\n';
}
void view::addInput1(){
    *input+='1';
    std::cout<<input->toStdString()<<'\n';
}
void view::addInput2(){
    *input+='2';
    std::cout<<input->toStdString()<<'\n';
}
void view::addInput3(){
    *input+='3';
    std::cout<<input->toStdString()<<'\n';
}
void view::addInput4(){
    *input+='4';
    std::cout<<input->toStdString()<<'\n';
}
void view::addInput5(){
    *input+='5';
    std::cout<<input->toStdString()<<'\n';
}
void view::addInput6(){
    *input+='6';
    std::cout<<input->toStdString()<<'\n';
}
void view::addInput7(){
    *input+='7';
    std::cout<<input->toStdString()<<'\n';
}
void view::addInput8(){
    *input+='8';
    std::cout<<input->toStdString()<<'\n';
}
void view::addInput9(){
    *input+='9';
    std::cout<<input->toStdString()<<'\n';
}
void view::addInputA(){
    *input+='A';
    std::cout<<input->toStdString()<<'\n';
}
void view::addInputB(){
    *input+='B';
    std::cout<<input->toStdString()<<'\n';
}
void view::addInputC(){
    *input+='C';
    std::cout<<input->toStdString()<<'\n';
}
void view::addInputD(){
    *input+='D';
    std::cout<<input->toStdString()<<'\n';
}
void view::addInputE(){
    *input+='E';
    std::cout<<input->toStdString()<<'\n';
}
void view::addInputF(){
    *input+='F';
    std::cout<<input->toStdString()<<'\n';
}

void view::InputPlus(){
  //*input=*input+'+';
  //std::cout<<input->toStdString()<<'\n';
}
void view::InputMinus(){
  //*input=*input+'-';
  //std::cout<<input->toStdString()<<'\n';
}
void view:: InputMolt(){
  //*input=*input+'*';
  //std::cout<<input->toStdString()<<'\n';
}
void view::InputDiv(){
  //*input=*input+'/';
  //std::cout<<input->toStdString()<<'\n';
}
void view::InputRest(){
  //*input=*input+'%';
  //std::cout<<input->toStdString()<<'\n';
}
void view::InputNot(){
  //*input=*input+'!';
  //std::cout<<input->toStdString()<<'\n';
}
void view::InputRes(){
  //*input=*input+'=';
  //std::cout<<input->toStdString()<<'\n';
}
void view::InputDel(){
    input->resize(input->size()-1);
    std::cout<<input->toStdString()<<'\n';
}

void view::inputBin(){
    delete tast;
    delete input;
    tast = new tastierino(Base::Bin, this);
    input = new QString();
    tast->show();
}
void view::inputOct(){
    delete tast;
    delete input;
    tast = new tastierino(Base::Oct, this);
    input = new QString();
    tast->show();
}
void view::inputTen(){
    delete tast;
    delete input;
    tast = new tastierino(Base::Dec, this);
    input = new QString();
    tast->show();
}
void view::inputHex(){
    delete tast;
    delete input;
    tast =  new tastierino(Base::Hex, this);
    input = new QString();
    tast->show();
}
void view::inputCol(){
    delete tast;
    delete input;
    tast = new tastierino(Base::Col, this);
    input = new QString();
    tast->show();
}
