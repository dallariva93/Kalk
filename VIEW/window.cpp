#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent){
    QSize size(650,650);
    setMaximumSize(size);
    setMinimumSize(size);

    setFont(QFont("QFont::SansSerif	",9));

    creatorP=new PolygonCreator;
    creatorC=new ColorCreator;

    areaD=new DataArea;
    areaP=new DrawArea;

    Container* contenitore=new Container;
    operandoUno = new OperandSelector("1",contenitore);
    operandoDue = new OperandSelector("2",contenitore);

    pulsanti = new BoxButtons;

    areaLayout = new QHBoxLayout;
    creatorLayout = new QHBoxLayout;
    operandLayout = new QHBoxLayout;
    colorCButtonsLayout = new QVBoxLayout;
    mainLayout = new QVBoxLayout;

    connect(creatorC,SIGNAL(inviaColore(Colore*)),operandoUno,SLOT(addColore(Colore*)));
    connect(creatorC,SIGNAL(inviaColore(Colore*)),operandoDue,SLOT(addColore(Colore*)));
    connect(creatorC,SIGNAL(inviaColore(Colore*)),creatorP,SLOT(addColore(Colore*)));
    //connect(operandouno,SIGNAL(ottienicolore(Colore*)), polygoncreator::pentagoncreator, SLOT(creacolore(Colore*));



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

/*  area tentativi fede   */

    connect(pulsanti,SIGNAL(trovaPerimetro()), operandoUno, SLOT(calcolaPerimetro()));
    connect(operandoUno,SIGNAL(inviaPerimetro(double)), areaD, SLOT(outputPerimetro(double)));

    connect(pulsanti,SIGNAL(trovaArea()), operandoUno, SLOT(calcolaArea()));
    connect(operandoUno,SIGNAL(inviaArea(double)), areaD, SLOT(outputArea(double)));

    connect(pulsanti,SIGNAL(trovaAngoli()), operandoUno, SLOT(calcolaAngoli()));
    connect(operandoUno,SIGNAL(inviaAngoli(QVector<Angolo>)), areaD, SLOT(outputAngoli(QVector<Angolo>)));

    connect(pulsanti,SIGNAL(trovaLati()), operandoUno, SLOT(calcolaLati()));
    connect(operandoUno,SIGNAL(inviaLati(QVector<double>)), areaD, SLOT(outputLati(QVector<double>)));
//somma
    connect(pulsanti,SIGNAL(trovaSomma()), operandoUno, SLOT(sommaOpUno()));
    connect(operandoUno, SIGNAL(sommaUno(QString)), operandoDue, SLOT(calcolaSomma(QString)));

/*  area tentativi fede   */

}


