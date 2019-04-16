#ifndef VIEW_H
#define VIEW_H

#include "base.h"
#include "tastierino.h"
#include "lcd.h"

#include <QWidget>

class view : public QWidget
{
    Q_OBJECT
public:
    explicit view(QWidget *parent = NULL);

signals:

public slots:
    void addInput0();
    void addInput1();
    void addInput2();
    void addInput3();
    void addInput4();
    void addInput5();
    void addInput6();
    void addInput7();
    void addInput8();
    void addInput9();
    void addInputA();
    void addInputB();
    void addInputC();
    void addInputD();
    void addInputE();
    void addInputF();

    void InputPlus();
    void InputMinus();
    void InputMolt();
    void InputDiv();
    void InputRest();
    void InputNot();
    void InputRes();
    void InputDel();

    void inputBin();
    void inputOct();
    void inputTen();
    void inputHex();
    void inputCol();
private:
    tastierino* tast;
    lcd* screen;
    QString* input;
};

#endif // VIEW_H
