#include <QPushButton>
#include "boxbutton.h"
#include"exception.h"

BoxButtons::BoxButtons(QWidget *parent) : QWidget(parent){

    QSize size(250,150);
    setMaximumSize(size);
    setMinimumSize(size);

    somma = new QPushButton("+",this);
    sottrazione = new QPushButton("-", this);
    moltiplicazione = new QPushButton("x", this);
    divisione = new QPushButton("%", this);
    perimetro = new QPushButton("2P", this);
    area = new QPushButton("Area", this);
    angoli = new QPushButton("Angoli", this);
    lati = new QPushButton("Lati", this);
    scala = new QPushButton("Scala", this);
    ruota = new QPushButton("Ruota", this);
    inputScala = new QLineEdit(this);

    perimetro->setEnabled(false);
    area->setEnabled(false);
    lati->setEnabled(false);
    angoli->setEnabled(false);
    somma->setEnabled(false);
    sottrazione->setEnabled(false);
    divisione->setEnabled(false);
    moltiplicazione->setEnabled(false);
    scala->setEnabled(false);
    ruota->setEnabled(false);

    layout=new QGridLayout;
    layout->addWidget(somma,0,0);
    layout->addWidget(sottrazione,0,1);
    layout->addWidget(moltiplicazione,1,0);
    layout->addWidget(divisione,1,1);
    layout->addWidget(perimetro,0,2);
    layout->addWidget(area,0,3);
    layout->addWidget(angoli,1,2);
    layout->addWidget(lati,1,3);
    layout->addWidget(scala,2,0);
    layout->addWidget(inputScala,2,1);
    layout->addWidget(ruota,2,3);
    setLayout(layout);

    connect(perimetro ,SIGNAL(clicked()), this, SLOT(getPerimetro()) );
    connect(area ,SIGNAL(clicked()), this, SLOT(getArea()) );
    connect(angoli ,SIGNAL(clicked()), this, SLOT(getAngoli()) );
    connect(lati ,SIGNAL(clicked()), this, SLOT(getLati()) );

    connect(somma, SIGNAL(clicked()), this, SLOT(getSomma()));
    connect(sottrazione, SIGNAL(clicked()), this, SLOT(getSottrazione()));
    connect(moltiplicazione, SIGNAL(clicked()), this, SLOT(getMoltiplicazione()));
    connect(divisione, SIGNAL(clicked()), this, SLOT(getDivisione()));

    connect(scala, SIGNAL(clicked()), this, SLOT(doScala()));
    connect(ruota, SIGNAL(clicked()), this, SLOT(doRuota()));
}

BoxButtons::~BoxButtons()
{
    delete somma;
    delete sottrazione;
    delete moltiplicazione;
    delete divisione;
    delete perimetro;
    delete area;
    delete angoli;
    delete lati;
    delete scala;
    delete ruota;
    delete inputScala;
    delete layout;
}

void BoxButtons::getPerimetro(){
    emit trovaPerimetro();
}

void BoxButtons::getArea(){
    emit trovaArea();
}

void BoxButtons::getAngoli(){
    emit trovaAngoli();
}

void BoxButtons::getLati(){
    emit trovaLati();
}

void BoxButtons::getSomma(){
    emit trovaSomma();
}

void BoxButtons::getSottrazione(){
    emit trovaSottrazione();
}

void BoxButtons::getMoltiplicazione(){
    emit trovaMoltiplicazione();
}

void BoxButtons::getDivisione(){
    emit trovaDivisione();
}

void BoxButtons::doScala1(){
    QString in = inputScala->displayText();
    if(in.isEmpty())    throw EmptyField("Campo vuoto!");
    if(!in.toDouble() || in.startsWith("+") || in.startsWith("-"))  throw SyntaxError("Input errato! \nSono accettati solo numeri.");
    emit trovaScala(in);
}
void BoxButtons::doScala()try{
    doScala1();
}
catch(EmptyField){}
catch(SyntaxError){}

void BoxButtons::doRuota(){
    emit faiRuota();
}

void BoxButtons::bottoniColori(){
    perimetro->setEnabled(false);
    area->setEnabled(false);
    lati->setEnabled(false);
    angoli->setEnabled(false);
    somma->setEnabled(true);
    sottrazione->setEnabled(true);
    divisione->setEnabled(true);
    moltiplicazione->setEnabled(true);
    scala->setEnabled(false);
    ruota->setEnabled(false);
}

void BoxButtons::bottoniPolig(){
    perimetro->setEnabled(true);
    area->setEnabled(true);
    lati->setEnabled(true);
    angoli->setEnabled(true);
    somma->setEnabled(true);
    sottrazione->setEnabled(false);
    divisione->setEnabled(false);
    moltiplicazione->setEnabled(false);
    scala->setEnabled(true);
    ruota->setEnabled(true);
}

void BoxButtons::bottSoloSomma(){
    perimetro->setEnabled(false);
    area->setEnabled(false);
    lati->setEnabled(false);
    angoli->setEnabled(false);
    somma->setEnabled(true);
    sottrazione->setEnabled(false);
    divisione->setEnabled(false);
    moltiplicazione->setEnabled(false);
    scala->setEnabled(false);
    ruota->setEnabled(false);
}
