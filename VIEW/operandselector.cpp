#include "operandselector.h"

OperandSelector::OperandSelector(QString numero, QWidget *parent) : QWidget(parent){
    QSize size(325,45);
    setMaximumSize(size);
    setMinimumSize(size);

    selector = new QComboBox;
    operando = new QLabel;
    operando->setText("Operando "+numero+":");
    selector->insertItem(0,"operando1");

    mainLayout = new QHBoxLayout;
    mainLayout->addWidget(operando);
    mainLayout->addWidget(selector);
    setLayout(mainLayout);

}


Poligono& Operando1Corrente(){

}
