#include "tastierino.h"

tastierino::tastierino(Base b, QWidget *parent) : QWidget(parent)
{

    button0 = new QPushButton("0", this);
    button0->setGeometry(PON1, PON3, SN, SN);
    button1 = new QPushButton("1", this);
    button1->setGeometry(PON0, PON0, SN, SN);
    button2 = new QPushButton("2", this);
    button2->setGeometry(PON1, PON0, SN, SN);
    button3 = new QPushButton("3", this);
    button3->setGeometry(PON2, PON0, SN, SN);
    button4 = new QPushButton("4", this);
    button4->setGeometry(PON0, PON1, SN, SN);
    button5 = new QPushButton("5", this);
    button5->setGeometry(PON1, PON1, SN, SN);
    button6 = new QPushButton("6", this);
    button6->setGeometry(PON2, PON1, SN, SN);
    button7 = new QPushButton("7", this);
    button7->setGeometry(PON0, PON2, SN, SN);
    button8 = new QPushButton("8", this);
    button8->setGeometry(PON1, PON2, SN, SN);
    button9 = new QPushButton("9", this);
    button9->setGeometry(PON2, PON2, SN, SN);
    buttonA = new QPushButton("A", this);
    buttonA->setGeometry(POL0, PON0, SN, SN);
    buttonB = new QPushButton("B", this);
    buttonB->setGeometry(POL1, PON0, SN, SN);
    buttonC = new QPushButton("C", this);
    buttonC->setGeometry(POL2, PON0, SN, SN);
    buttonD = new QPushButton("D", this);
    buttonD->setGeometry(POL0, PON1, SN, SN);
    buttonE = new QPushButton("E", this);
    buttonE->setGeometry(POL1, PON1, SN, SN);
    buttonF = new QPushButton("F", this);
    buttonF->setGeometry(POL2, PON1, SN, SN);

    buttonPlus = new QPushButton("+", this);
    buttonPlus->setGeometry(POL0, PON2, SN, 2*SN);
    buttonMinus = new QPushButton("-", this);
    buttonMinus->setGeometry(POL1, PON2, SN, SN);
    buttonMolt = new QPushButton("*", this);
    buttonMolt->setGeometry(POL2, PON2, SN, SN);
    buttonDiv = new QPushButton("/", this);
    buttonDiv->setGeometry(POL2, PON3, SN, SN);
    buttonRest = new QPushButton("%", this);
    buttonRest->setGeometry(POL1, PON3, SN, SN);
    buttonNot = new QPushButton("!", this);
    buttonNot->setGeometry(POL3, PON1, SN, SN);
    buttonRes = new QPushButton("=", this);
    buttonRes->setGeometry(POL3, PON2, SN, 2*SN);
    buttonDel = new QPushButton("<-", this);
    buttonDel->setGeometry(POL3, PON0, SN, SN);

    buttonBin = new QRadioButton("Bin", this);
    buttonBin->setGeometry(POS0, PON0, SSX, SSY);
    buttonOct = new QRadioButton("Oct", this);
    buttonOct->setGeometry(POS0, PON1, SSX, SSY);
    buttonTen = new QRadioButton("Ten", this);
    buttonTen->setGeometry(POS0, PON2, SSX, SSY);
    buttonHex = new QRadioButton("Hex", this);
    buttonHex->setGeometry(POS0, PON3, SSX, SSY);
    buttonCol = new QRadioButton("Col", this);
    buttonCol->setGeometry(POS0, POL1, SSX, SSY);

    group = new QButtonGroup(this);
    group->addButton(buttonBin);
    group->addButton(buttonOct);
    group->addButton(buttonTen);
    group->addButton(buttonHex);
    group->addButton(buttonCol);

    connect(buttonBin, SIGNAL(clicked()), parent, SLOT(inputBin()));
    connect(buttonOct, SIGNAL(clicked()), parent, SLOT(inputOct()));
    connect(buttonTen, SIGNAL(clicked()), parent, SLOT(inputTen()));
    connect(buttonHex, SIGNAL(clicked()), parent, SLOT(inputHex()));
    connect(buttonCol, SIGNAL(clicked()), parent, SLOT(inputCol()));

    switch (b) {
    case Base::Bin:
        buttonBin->toggle();
        button2->setFlat(true);
        button2->setDisabled(true);
        button3->setFlat(true);
        button3->setDisabled(true);
        button4->setFlat(true);
        button4->setDisabled(true);
        button5->setFlat(true);
        button5->setDisabled(true);
        button6->setFlat(true);
        button6->setDisabled(true);
        button7->setFlat(true);
        button7->setDisabled(true);
        button8->setFlat(true);
        button8->setDisabled(true);
        button9->setFlat(true);
        button9->setDisabled(true);
        buttonA->setFlat(true);
        buttonA->setDisabled(true);
        buttonB->setFlat(true);
        buttonB->setDisabled(true);
        buttonC->setFlat(true);
        buttonC->setDisabled(true);
        buttonD->setFlat(true);
        buttonD->setDisabled(true);
        buttonE->setFlat(true);
        buttonE->setDisabled(true);
        buttonF->setFlat(true);
        buttonF->setDisabled(true);
        connect(button0, SIGNAL(clicked()), parent, SLOT(addInput0()));
        connect(button1, SIGNAL(clicked()), parent, SLOT(addInput1()));
        connect(buttonPlus, SIGNAL(clicked()), parent, SLOT(InputPlus()));
        connect(buttonMinus, SIGNAL(clicked()), parent, SLOT(InputMinus()));
        connect(buttonMolt, SIGNAL(clicked()), parent, SLOT(InputMolt()));
        connect(buttonDiv, SIGNAL(clicked()), parent, SLOT(InputDiv()));
        connect(buttonRest, SIGNAL(clicked()), parent, SLOT(InputRest()));
        connect(buttonNot, SIGNAL(clicked()), parent, SLOT(InputNot()));
        connect(buttonRes, SIGNAL(clicked()), parent, SLOT(InputRes()));
        connect(buttonDel, SIGNAL(clicked()), parent, SLOT(InputDel()));
        break;
    case Base::Oct:
        buttonOct->toggle();
        button8->setFlat(true);
        button8->setDisabled(true);
        button9->setFlat(true);
        button9->setDisabled(true);
        buttonA->setFlat(true);
        buttonA->setDisabled(true);
        buttonB->setFlat(true);
        buttonB->setDisabled(true);
        buttonC->setFlat(true);
        buttonC->setDisabled(true);
        buttonD->setFlat(true);
        buttonD->setDisabled(true);
        buttonE->setFlat(true);
        buttonE->setDisabled(true);
        buttonF->setFlat(true);
        buttonF->setDisabled(true);
        connect(button0, SIGNAL(clicked()), parent, SLOT(addInput0()));
        connect(button1, SIGNAL(clicked()), parent, SLOT(addInput1()));
        connect(button2, SIGNAL(clicked()), parent, SLOT(addInput2()));
        connect(button3, SIGNAL(clicked()), parent, SLOT(addInput3()));
        connect(button4, SIGNAL(clicked()), parent, SLOT(addInput4()));
        connect(button5, SIGNAL(clicked()), parent, SLOT(addInput5()));
        connect(button6, SIGNAL(clicked()), parent, SLOT(addInput6()));
        connect(button7, SIGNAL(clicked()), parent, SLOT(addInput7()));
        connect(buttonPlus, SIGNAL(clicked()), parent, SLOT(InputPlus()));
        connect(buttonMinus, SIGNAL(clicked()), parent, SLOT(InputMinus()));
        connect(buttonMolt, SIGNAL(clicked()), parent, SLOT(InputMolt()));
        connect(buttonDiv, SIGNAL(clicked()), parent, SLOT(InputDiv()));
        connect(buttonRest, SIGNAL(clicked()), parent, SLOT(InputRest()));
        connect(buttonNot, SIGNAL(clicked()), parent, SLOT(InputNot()));
        connect(buttonRes, SIGNAL(clicked()), parent, SLOT(InputRes()));
        connect(buttonDel, SIGNAL(clicked()), parent, SLOT(InputDel()));
        break;
    case Base::Dec:
        buttonTen->toggle();
        buttonA->setFlat(true);
        buttonA->setDisabled(true);
        buttonB->setFlat(true);
        buttonB->setDisabled(true);
        buttonC->setFlat(true);
        buttonC->setDisabled(true);
        buttonD->setFlat(true);
        buttonD->setDisabled(true);
        buttonE->setFlat(true);
        buttonE->setDisabled(true);
        buttonF->setFlat(true);
        buttonF->setDisabled(true);
        connect(button0, SIGNAL(clicked()), parent, SLOT(addInput0()));
        connect(button1, SIGNAL(clicked()), parent, SLOT(addInput1()));
        connect(button2, SIGNAL(clicked()), parent, SLOT(addInput2()));
        connect(button3, SIGNAL(clicked()), parent, SLOT(addInput3()));
        connect(button4, SIGNAL(clicked()), parent, SLOT(addInput4()));
        connect(button5, SIGNAL(clicked()), parent, SLOT(addInput5()));
        connect(button6, SIGNAL(clicked()), parent, SLOT(addInput6()));
        connect(button7, SIGNAL(clicked()), parent, SLOT(addInput7()));
        connect(button8, SIGNAL(clicked()), parent, SLOT(addInput8()));
        connect(button9, SIGNAL(clicked()), parent, SLOT(addInput9()));
        connect(buttonPlus, SIGNAL(clicked()), parent, SLOT(InputPlus()));
        connect(buttonMinus, SIGNAL(clicked()), parent, SLOT(InputMinus()));
        connect(buttonMolt, SIGNAL(clicked()), parent, SLOT(InputMolt()));
        connect(buttonDiv, SIGNAL(clicked()), parent, SLOT(InputDiv()));
        connect(buttonRest, SIGNAL(clicked()), parent, SLOT(InputRest()));
        connect(buttonNot, SIGNAL(clicked()), parent, SLOT(InputNot()));
        connect(buttonRes, SIGNAL(clicked()), parent, SLOT(InputRes()));
        connect(buttonDel, SIGNAL(clicked()), parent, SLOT(InputDel()));
        break;
    case Base::Hex:
        buttonHex->toggle();
        connect(button0, SIGNAL(clicked()), parent, SLOT(addInput0()));
        connect(button1, SIGNAL(clicked()), parent, SLOT(addInput1()));
        connect(button2, SIGNAL(clicked()), parent, SLOT(addInput2()));
        connect(button3, SIGNAL(clicked()), parent, SLOT(addInput3()));
        connect(button4, SIGNAL(clicked()), parent, SLOT(addInput4()));
        connect(button5, SIGNAL(clicked()), parent, SLOT(addInput5()));
        connect(button6, SIGNAL(clicked()), parent, SLOT(addInput6()));
        connect(button7, SIGNAL(clicked()), parent, SLOT(addInput7()));
        connect(button8, SIGNAL(clicked()), parent, SLOT(addInput8()));
        connect(button9, SIGNAL(clicked()), parent, SLOT(addInput9()));
        connect(buttonA, SIGNAL(clicked()), parent, SLOT(addInputA()));
        connect(buttonB, SIGNAL(clicked()), parent, SLOT(addInputB()));
        connect(buttonC, SIGNAL(clicked()), parent, SLOT(addInputC()));
        connect(buttonD, SIGNAL(clicked()), parent, SLOT(addInputD()));
        connect(buttonE, SIGNAL(clicked()), parent, SLOT(addInputE()));
        connect(buttonF, SIGNAL(clicked()), parent, SLOT(addInputF()));
        connect(buttonPlus, SIGNAL(clicked()), parent, SLOT(InputPlus()));
        connect(buttonMinus, SIGNAL(clicked()), parent, SLOT(InputMinus()));
        connect(buttonMolt, SIGNAL(clicked()), parent, SLOT(InputMolt()));
        connect(buttonDiv, SIGNAL(clicked()), parent, SLOT(InputDiv()));
        connect(buttonRest, SIGNAL(clicked()), parent, SLOT(InputRest()));
        connect(buttonNot, SIGNAL(clicked()), parent, SLOT(InputNot()));
        connect(buttonRes, SIGNAL(clicked()), parent, SLOT(InputRes()));
        connect(buttonDel, SIGNAL(clicked()), parent, SLOT(InputDel()));
        break;
    case Base::Col:
        buttonCol->toggle();
        buttonDiv->setFlat(true);
        buttonDiv->setDisabled(true);
        buttonMolt->setFlat(true);
        buttonMolt->setDisabled(true);
        buttonRest->setFlat(true);
        buttonRest->setDisabled(true);
        connect(button0, SIGNAL(clicked()), parent, SLOT(addInput0()));
        connect(button1, SIGNAL(clicked()), parent, SLOT(addInput1()));
        connect(button2, SIGNAL(clicked()), parent, SLOT(addInput2()));
        connect(button3, SIGNAL(clicked()), parent, SLOT(addInput3()));
        connect(button4, SIGNAL(clicked()), parent, SLOT(addInput4()));
        connect(button5, SIGNAL(clicked()), parent, SLOT(addInput5()));
        connect(button6, SIGNAL(clicked()), parent, SLOT(addInput6()));
        connect(button7, SIGNAL(clicked()), parent, SLOT(addInput7()));
        connect(button8, SIGNAL(clicked()), parent, SLOT(addInput8()));
        connect(button9, SIGNAL(clicked()), parent, SLOT(addInput9()));
        connect(buttonA, SIGNAL(clicked()), parent, SLOT(addInputA()));
        connect(buttonB, SIGNAL(clicked()), parent, SLOT(addInputB()));
        connect(buttonC, SIGNAL(clicked()), parent, SLOT(addInputC()));
        connect(buttonD, SIGNAL(clicked()), parent, SLOT(addInputD()));
        connect(buttonE, SIGNAL(clicked()), parent, SLOT(addInputE()));
        connect(buttonF, SIGNAL(clicked()), parent, SLOT(addInputF()));
        connect(buttonPlus, SIGNAL(clicked()), parent, SLOT(InputPlus()));
        connect(buttonMinus, SIGNAL(clicked()), parent, SLOT(InputMinus()));
        connect(buttonNot, SIGNAL(clicked()), parent, SLOT(InputNot()));
        connect(buttonRes, SIGNAL(clicked()), parent, SLOT(InputRes()));
        connect(buttonDel, SIGNAL(clicked()), parent, SLOT(InputDel()));
        break;
    }
}
