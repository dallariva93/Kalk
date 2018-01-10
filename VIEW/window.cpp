#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    QSize size(650,650);
    setMaximumSize(size);
    setMinimumSize(size);

    setFont(QFont("QFont::SansSerif	",9));

    creatorP=new PolygonCreator;
    creatorC=new ColorCreator;

    areaD=new DataArea;
    areaP=new DrawArea;

    operandoUno = new OperandSelector;
    operandoDue = new OperandSelector;

    areaLayout = new QHBoxLayout;
    creatorLayout = new QHBoxLayout;
    operandLayout = new QHBoxLayout;
    mainLayout = new QVBoxLayout;

    areaLayout->addWidget(areaP);
    areaLayout->addWidget(areaD);

    operandLayout->addWidget(operandoUno);
    operandLayout->addWidget(operandoDue);

    creatorLayout->addWidget(creatorP);
    creatorLayout->addWidget(creatorC);



    mainLayout->addLayout(areaLayout);
    mainLayout->addLayout(operandLayout);
    mainLayout->addLayout(creatorLayout);
    setLayout(mainLayout);

}

