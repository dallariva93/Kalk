#include "operandselector.h"

OperandSelector::OperandSelector(QWidget *parent) : QWidget(parent)
{
    QSize size(325,45);
    setMaximumSize(size);
    setMinimumSize(size);

    selector = new QComboBox;
    operando = new QLabel;
    operando->setText("Operando: ");
    selector->insertItem(0,"operando1");

    mainLayout = new QHBoxLayout;
    mainLayout->addWidget(operando);
    mainLayout->addWidget(selector);
    setLayout(mainLayout);

}

