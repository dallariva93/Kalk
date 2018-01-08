#include "trianglecreator.h"
#include <iostream>

TriangleCreator::TriangleCreator(QWidget *parent) : QWidget(parent){
    setWindowTitle("Triangle!");      //titolo finestra

    QSize size(500,150);
    setMaximumSize(size);
    setMinimumSize(size);

    radio1 = new QRadioButton(tr("Costruisco dato due lati e angolo compreso."),this);
    radio2 = new QRadioButton(tr("Costruisco dato un lato e due angoli adiacenti."),this);
    radio3 = new QRadioButton(tr("Costruisco dato i tre lati."),this);
    radio1->setChecked(true);   //setto di default radio1



    lato1 = new QLineEdit(this);
    lato2 = new QLineEdit(this);
    lato3 = new QLineEdit(this);
    angolo1 = new QLineEdit(this);
    angolo2 = new QLineEdit(this);

    lato1->setMinimumWidth(1);

    lato3->setVisible(false);
    angolo2->setVisible(false);


    latoA = new QLabel(tr("Lato A:"));
    latoB = new QLabel(tr("Lato B:"));
    latoC= new QLabel(tr("Lato C:"));
    angoloA = new QLabel(tr("Angolo:"));
    angoloB = new QLabel(tr("Angolo:"));
    colore = new QLabel(tr("Colore:"));

    angoloB->setVisible(false);
    latoC->setVisible(false);

    saveButton = new QPushButton(tr("Crea"), this);
    colori= new QComboBox;
    colori->addItem(QString("colori"));
    //ciclo che riempe colori con tutti i colori creati


    connect(radio1, SIGNAL(clicked(bool)), this, SLOT(dueLatiUnAngolo(bool)));
    connect(radio2, SIGNAL(clicked(bool)), this, SLOT(dueAngoliUnLato(bool)));
    connect(radio3, SIGNAL(clicked(bool)), this, SLOT(treLati(bool)));
    //connect per il pulsante crea

    choiceLayout = new QVBoxLayout;
    choiceLayout->addWidget(radio1);
    choiceLayout->addWidget(radio2);
    choiceLayout->addWidget(radio3);

    formLayout = new QHBoxLayout;
    formLayout->addWidget(latoA);
    formLayout->addWidget(lato1);
    formLayout->addWidget(latoB);
    formLayout->addWidget(lato2);
    formLayout->addWidget(latoC);
    formLayout->addWidget(lato3);
    formLayout->addWidget(angoloA);
    formLayout->addWidget(angolo1);
    formLayout->addWidget(angoloB);
    formLayout->addWidget(angolo2);
    formLayout->addWidget(colore);
    formLayout->addWidget(colori);


    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(choiceLayout);
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(saveButton);
    setLayout(mainLayout);

}

void TriangleCreator::refreshFormWidget()
{
    formLayout->removeWidget(lato1);
    formLayout->removeWidget(lato2);
    formLayout->removeWidget(lato3);
    formLayout->removeWidget(latoA);
    formLayout->removeWidget(latoB);
    formLayout->removeWidget(latoC);
    formLayout->removeWidget(angolo1);
    formLayout->removeWidget(angolo2);
    formLayout->removeWidget(angoloA);
    formLayout->removeWidget(angoloB);

    delete lato1;
    delete lato2;
    delete lato3;
    delete latoA;
    delete latoB;
    delete latoC;
    delete angolo1;
    delete angolo2;
    delete angoloA;
    delete angoloB;

    lato1 = new QLineEdit(this);
    lato2 = new QLineEdit(this);
    lato3 = new QLineEdit(this);
    angolo1 = new QLineEdit(this);
    angolo2 = new QLineEdit(this);
    latoA = new QLabel(tr("Lato A:"));
    latoB = new QLabel(tr("Lato B:"));
    latoC= new QLabel(tr("Lato C:"));
    angoloA = new QLabel(tr("Angolo:"));
    angoloB = new QLabel(tr("Angolo:"));

}


void TriangleCreator::dueLatiUnAngolo(bool)
{
    refreshFormWidget();
    delete formLayout;
    mainLayout->removeWidget(saveButton);
    delete saveButton;
    saveButton=new QPushButton(tr("Crea"), this);
    formLayout=new QHBoxLayout;

    lato1->setVisible(true);
    latoA->setVisible(true);
    lato2->setVisible(true);
    latoB->setVisible(true);
    lato3->setVisible(false);
    latoC->setVisible(false);

    angolo1->setVisible(true);
    angoloA->setVisible(true);
    angolo2->setVisible(false);
    angoloB->setVisible(false);

    formLayout->addWidget(latoA);
    formLayout->addWidget(lato1);
    formLayout->addWidget(latoB);
    formLayout->addWidget(lato2);
    formLayout->addWidget(angoloA);
    formLayout->addWidget(angolo1);
    formLayout->addWidget(colore);
    formLayout->addWidget(colori);

    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(saveButton);

}

void TriangleCreator::dueAngoliUnLato(bool a)
{
    refreshFormWidget();
    delete formLayout;
    mainLayout->removeWidget(saveButton);
    delete saveButton;
    saveButton=new QPushButton(tr("Crea"), this);
    formLayout=new QHBoxLayout;

    lato1->setVisible(true);
    latoA->setVisible(true);
    lato2->setVisible(false);
    latoB->setVisible(false);
    lato2->setVisible(false);
    latoB->setVisible(false);

    angolo1->setVisible(true);
    angoloA->setVisible(true);
    angolo2->setVisible(true);
    angoloB->setVisible(true);

    formLayout->addWidget(latoA);
    formLayout->addWidget(lato1);
    formLayout->addWidget(angoloA);
    formLayout->addWidget(angolo1);
    formLayout->addWidget(angoloB);
    formLayout->addWidget(angolo2);
    formLayout->addWidget(colore);
    formLayout->addWidget(colori);
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(saveButton);
}

void TriangleCreator::treLati(bool)
{

    refreshFormWidget();
    delete formLayout;
    mainLayout->removeWidget(saveButton);
    delete saveButton;
    saveButton=new QPushButton(tr("Crea"), this);
    formLayout=new QHBoxLayout;

    lato1->setVisible(true);
    latoA->setVisible(true);
    lato2->setVisible(true);
    latoB->setVisible(true);
    lato2->setVisible(true);
    latoB->setVisible(true);

    angolo1->setVisible(false);
    angoloA->setVisible(false);
    angolo2->setVisible(false);
    angoloB->setVisible(false);

    formLayout->addWidget(latoA);
    formLayout->addWidget(lato1);
    formLayout->addWidget(latoB);
    formLayout->addWidget(lato2);
    formLayout->addWidget(latoC);
    formLayout->addWidget(lato3);
    formLayout->addWidget(colore);
    formLayout->addWidget(colori);
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(saveButton);

}
