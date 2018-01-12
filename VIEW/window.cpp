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

    operandoUno = new OperandSelector("1");
    operandoDue = new OperandSelector("2");

    pulsanti = new BoxButtons;

    areaLayout = new QHBoxLayout;
    creatorLayout = new QHBoxLayout;
    operandLayout = new QHBoxLayout;
    colorCButtonsLayout = new QVBoxLayout;
    mainLayout = new QVBoxLayout;


    areaLayout->addWidget(areaP);
    areaLayout->addWidget(areaD);

    operandLayout->addWidget(operandoUno);
    operandLayout->addWidget(operandoDue);

    creatorLayout->addWidget(creatorP);

    colorCButtonsLayout->addWidget(creatorC);
    colorCButtonsLayout->addWidget(pulsanti);
    creatorLayout->addLayout(colorCButtonsLayout);


    mainLayout->addLayout(areaLayout);
    mainLayout->addLayout(operandLayout);
    mainLayout->addLayout(creatorLayout);
    setLayout(mainLayout);

}

