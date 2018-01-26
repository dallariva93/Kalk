#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent){
    QSize size(650,650);
    setMaximumSize(size);
    setMinimumSize(size);

    setFont(QFont("QFont::SansSerif	",9));

    creatorC=new ColorCreator;

    areaD=new DataArea;
    areaP=new DrawArea;

    contenitore=new Container;
    operandoUno = new OperandSelector("1",contenitore);
    operandoDue = new OperandSelector("2",contenitore);

    creatorP=new PolygonCreator(operandoUno);

    pulsanti = new BoxButtons;

    areaLayout = new QHBoxLayout;
    creatorLayout = new QHBoxLayout;
    operandLayout = new QHBoxLayout;
    colorCButtonsLayout = new QVBoxLayout;
    mainLayout = new QVBoxLayout;

    connect(creatorC,SIGNAL(inviaColore(Colore*)),operandoUno,SLOT(addColore(Colore*)));
    connect(creatorC,SIGNAL(inviaColore(Colore*)),operandoDue,SLOT(addColore(Colore*)));
    connect(creatorC,SIGNAL(inviaColore(Colore*)),creatorP,SLOT(addColore(Colore*)));

    connect(operandoUno, SIGNAL(insertPoligono(QString)),operandoDue, SLOT(addPoligono(QString)));//aggiorno il selettore 2 quando inserisco solo nel primo
    connect(operandoUno, SIGNAL(inseritoPoligono(QString)),this, SLOT(acquisisciPoligono(QString)));
    connect(this,SIGNAL(disegnaPoligono(Poligono*)),areaP, SLOT(settaPoligono(Poligono*)));

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

    connect(operandoUno, SIGNAL(disabilita()), pulsanti, SLOT(disabilitaBottoni()));
    connect(operandoUno, SIGNAL(riabilita()), pulsanti, SLOT(riabilitaBottoni()));

    connect(pulsanti,SIGNAL(trovaPerimetro()), operandoUno, SLOT(calcolaPerimetro()));
    connect(operandoUno,SIGNAL(inviaPerimetro(double)), areaD, SLOT(outputPerimetro(double)));

    connect(pulsanti,SIGNAL(trovaArea()), operandoUno, SLOT(calcolaArea()));
    connect(operandoUno,SIGNAL(inviaArea(double)), areaD, SLOT(outputArea(double)));

    connect(pulsanti,SIGNAL(trovaAngoli()), operandoUno, SLOT(calcolaAngoli()));
    connect(operandoUno,SIGNAL(inviaAngoli(QVector<Angolo>)), areaD, SLOT(outputAngoli(QVector<Angolo>)));

    connect(pulsanti,SIGNAL(trovaLati()), operandoUno, SLOT(calcolaLati()));
    connect(operandoUno,SIGNAL(inviaLati(QVector<double>)), areaD, SLOT(outputLati(QVector<double>)));

    connect(pulsanti,SIGNAL(trovaSomma()), operandoUno, SLOT(sommaOpUno()));
    connect(operandoUno, SIGNAL(sommaUno(QString)), operandoDue, SLOT(calcolaSomma(QString)));
    connect(operandoDue, SIGNAL(stampaSomma(QString)), areaD, SLOT(outputSomma(QString)));

    connect(pulsanti,SIGNAL(trovaSottrazione()), operandoUno, SLOT(sottrazioneOpUno()));
    connect(operandoUno, SIGNAL(sottrazioneUno(QString)), operandoDue, SLOT(calcolaSottrazione(QString)));
    connect(operandoDue, SIGNAL(stampaSottrazione(QString)), areaD, SLOT(outputSottrazione(QString)));

    connect(pulsanti,SIGNAL(trovaMoltiplicazione()), operandoUno, SLOT(moltiplicazioneOpUno()));
    connect(operandoUno, SIGNAL(moltiplicazioneUno(QString)), operandoDue, SLOT(calcolaMoltiplicazione(QString)));
    connect(operandoDue, SIGNAL(stampaMoltiplicazione(QString)), areaD, SLOT(outputMoltiplicazione(QString)));

    connect(pulsanti,SIGNAL(trovaDivisione()), operandoUno, SLOT(divisioneOpUno()));
    connect(operandoUno, SIGNAL(divisioneUno(QString)), operandoDue, SLOT(calcolaDivisione(QString)));
    connect(operandoDue, SIGNAL(stampaDivisione(QString)), areaD, SLOT(outputDivisione(QString)));

    connect(operandoDue, SIGNAL(aggColore(Colore*)), operandoUno, SLOT(addColore(Colore*)));
    connect(operandoDue, SIGNAL(aggColore(Colore*)), operandoDue, SLOT(addColore(Colore*)));
    connect(operandoDue, SIGNAL(aggColore(Colore*)), creatorP, SLOT(addColore(Colore*)));

}

void Window::acquisisciPoligono(QString text){
    emit disegnaPoligono(contenitore->getPoligono(text));
}

void Window::hoPoligono(Poligono* p){
    emit disegnaPoligono(p);
}
