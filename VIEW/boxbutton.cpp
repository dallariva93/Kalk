#include "boxbutton.h"

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
    inputRuota = new QLineEdit(this);

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
    layout->addWidget(ruota,2,2);
    layout->addWidget(inputRuota,2,3);
    setLayout(layout);

}

