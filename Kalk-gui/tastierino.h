#ifndef TASTIERINO_H
#define TASTIERINO_H

#include "base.h"

#include <QWidget>
#include <QPushButton>
#include <QButtonGroup>
#include <QRadioButton>

class tastierino : public QWidget
{
    Q_OBJECT
public:
    explicit tastierino(Base b = Base::Dec, QWidget *parent = NULL);

signals:

public slots:

private:
    QPushButton *button0;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;
    QPushButton *button7;
    QPushButton *button8;
    QPushButton *button9;
    QPushButton *buttonA;
    QPushButton *buttonB;
    QPushButton *buttonC;
    QPushButton *buttonD;
    QPushButton *buttonE;
    QPushButton *buttonF;

    QPushButton *buttonRes;
    QPushButton *buttonPlus;
    QPushButton *buttonMinus;
    QPushButton *buttonMolt;
    QPushButton *buttonDiv;
    QPushButton *buttonRest;
    QPushButton *buttonNot;
    QPushButton *buttonDel;

    QButtonGroup* group;
    QRadioButton *buttonBin;
    QRadioButton *buttonOct;
    QRadioButton *buttonTen;
    QRadioButton *buttonHex;
    QRadioButton *buttonCol;
};

#endif // TASTIERINO_H
