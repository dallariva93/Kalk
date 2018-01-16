#include "trianglecreator.h"
#include <iostream>
TriangleCreator::TriangleCreator(QComboBox *col, QWidget *parent) :  QWidget(parent),colori(col){

   /* QSize size(450,350);
    setMaximumSize(size);*/



    radio1 = new QRadioButton(tr("Costruisco dato due lati e angolo compreso."),this);
    radio2 = new QRadioButton(tr("Costruisco dato un lato e due angoli adiacenti."),this);
    radio3 = new QRadioButton(tr("Costruisco dato i tre lati."),this);
    radio1->setChecked(true);   //setto di default radio1


    lato1 = new QLineEdit(this);
    lato2 = new QLineEdit(this);
    lato3 = new QLineEdit(this);
    angolo1 = new QLineEdit(this);
    angolo2 = new QLineEdit(this);
    nome = new QLineEdit(this);

    lato3->setVisible(false);
    angolo2->setVisible(false);


    latoA = new QLabel(tr("Lato A:"));
    latoB = new QLabel(tr("Lato B:"));
    latoC= new QLabel(tr("Lato C:"));
    angoloA = new QLabel(tr("Angolo:"));
    angoloB = new QLabel(tr("Angolo:"));
    colore = new QLabel(tr("Colore:"));
    labelNome = new QLabel(tr("Nome:"));

    angoloB->setVisible(false);
    latoC->setVisible(false);

    saveButton = new QPushButton(tr("Crea"), this);

    connect(radio1, SIGNAL(clicked()), this, SLOT(dueLatiUnAngolo()));
    connect(radio2, SIGNAL(clicked()), this, SLOT(dueAngoliUnLato()));
    connect(radio3, SIGNAL(clicked()), this, SLOT(treLati()));
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
    formLayout->addWidget(angoloA);
    formLayout->addWidget(angolo1);

    coloreNomeLayout = new QHBoxLayout;
    coloreNomeLayout->addWidget(colore);
    coloreNomeLayout->addWidget(colori);
    coloreNomeLayout->addWidget(labelNome);
    coloreNomeLayout->addWidget(nome);


    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(choiceLayout);
    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(coloreNomeLayout);
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


void TriangleCreator::dueLatiUnAngolo()
{
    refreshFormWidget();
     formLayout;
    mainLayout->removeWidget(saveButton);
    delete saveButton;
    saveButton=new QPushButton(tr("Crea"), this);

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

    formLayout = new QHBoxLayout;
    formLayout->addWidget(latoA);
    formLayout->addWidget(lato1);
    formLayout->addWidget(latoB);
    formLayout->addWidget(lato2);
    formLayout->addWidget(angoloA);
    formLayout->addWidget(angolo1);

    coloreNomeLayout = new QHBoxLayout;
    coloreNomeLayout->addWidget(colore);
    coloreNomeLayout->addWidget(colori);
    coloreNomeLayout->addWidget(labelNome);
    coloreNomeLayout->addWidget(nome);

    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(coloreNomeLayout);
    mainLayout->addWidget(saveButton);
    setLayout(mainLayout);

}

void TriangleCreator::dueAngoliUnLato()
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



    coloreNomeLayout = new QHBoxLayout;
    coloreNomeLayout->addWidget(colore);
    coloreNomeLayout->addWidget(colori);
    coloreNomeLayout->addWidget(labelNome);
    coloreNomeLayout->addWidget(nome);


    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(coloreNomeLayout);
    mainLayout->addWidget(saveButton);
    setLayout(mainLayout);
}

void TriangleCreator::treLati()
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

    coloreNomeLayout = new QHBoxLayout;
    coloreNomeLayout->addWidget(colore);
    coloreNomeLayout->addWidget(colori);
    coloreNomeLayout->addWidget(labelNome);
    coloreNomeLayout->addWidget(nome);


    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(coloreNomeLayout);
    mainLayout->addWidget(saveButton);
    setLayout(mainLayout);

}
