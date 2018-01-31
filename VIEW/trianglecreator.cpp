#include "trianglecreator.h"
#include <iostream>
#include"exception.h"
#include<QtAlgorithms>

TriangleCreator::TriangleCreator(OperandSelector *sel, QWidget *parent) : selettore(sel), QWidget(parent){

   /* QSize size(450,350);
    setMaximumSize(size);*/

    colori=new QComboBox;


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

    latoA = new QLabel(tr("Lato A:"));
    latoB = new QLabel(tr("Lato B:"));
    latoC= new QLabel(tr("Lato C:"));
    angoloA = new QLabel(tr("Angolo:"));
    angoloB = new QLabel(tr("Angolo:"));
    colore = new QLabel(tr("Colore:"));
    labelNome = new QLabel(tr("Nome:"));

    lato3->setVisible(false);
    angolo2->setVisible(false);
    angoloB->setVisible(false);
    latoC->setVisible(false);

    saveButton = new QPushButton(tr("Crea"), this);

    connect(radio1, SIGNAL(clicked()), this, SLOT(dueLatiUnAngolo()));
    connect(radio2, SIGNAL(clicked()), this, SLOT(dueAngoliUnLato()));
    connect(radio3, SIGNAL(clicked()), this, SLOT(treLati()));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(creaTriangolo()));


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

    dueLatiUnAngolo();

}

void TriangleCreator::refreshFormWidget(){
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

Triangolo *TriangleCreator::buildTriangolo()
{
    Colore*c;
    colori->count()==0 ? c=new RGB() : c=selettore->getColore(colori->currentText())->clone();
    Triangolo *tr;
    if(radio1->isChecked()){    //due lati e un angolo
        if(!lato1->text().toDouble() || !lato2->text().toDouble() || !angolo1->text().toDouble() || nome->text().isEmpty())
            throw SyntaxError("I lati e gli angoli accettano solo valori numerici. \nInoltre i Form non possono essere vuoti.");
        if(nome->text().startsWith("#"))
            throw SyntaxError("Il nome non può iniziare con il carattere #");
        if(angolo1->text().toDouble()>=180)
            throw WrongPolygon("Angolo > 180°");
        if(selettore->isPresent(nome->text()))
            throw AlreadyPresent("Nome già presente!");
        tr = new Triangolo(lato1->text().toDouble(), lato2->text().toDouble(), Angolo(angolo1->text().toDouble()), c, nome->text());
    }
    else if(radio2->isChecked()){   //due angoli e un lato
        if(!lato1->text().toDouble() || !angolo2->text().toDouble() || !angolo1->text().toDouble() || nome->text().isEmpty())
            throw SyntaxError("I lati e gli angoli accettano solo valori numerici. \nInoltre i Form non possono essere vuoti.");
        if(nome->text().startsWith("#"))
            throw SyntaxError("Il nome non può iniziare con il carattere #");
        if(angolo1->text().toDouble()>=180 || angolo2->text().toDouble()>=180)
            throw WrongPolygon("Angolo > 180°");
        if(selettore->isPresent(nome->text()))
            throw AlreadyPresent("Nome già presente!");
        tr = new Triangolo(lato1->text().toDouble(), Angolo(angolo1->text().toDouble()), Angolo(angolo2->text().toDouble()), c, nome->text());
    }
    else{   //tre lati
        if(!lato1->text().toDouble() || !lato2->text().toDouble() || !lato3->text().toDouble() || nome->text().isEmpty())
            throw SyntaxError("I lati e gli angoli accettano solo valori numerici. \nInoltre i Form non possono essere vuoti.");
        if(nome->text().startsWith("#"))
            throw SyntaxError("Il nome non può iniziare con il carattere #");
        QVector<double> lati;
        lati.push_back(lato1->text().toDouble());
        lati.push_back(lato2->text().toDouble());
        lati.push_back(lato3->text().toDouble());
        qSort(lati);
        if(lati[2]>=(lati[1]+lati[0]))
            throw WrongPolygon("L'ipotenusa deve essere minore della somma dei cateti");

        if(selettore->isPresent(nome->text()))
            throw AlreadyPresent("Nome già presente!");
        tr = new Triangolo(lato1->text().toDouble(), lato2->text().toDouble(), lato3->text().toDouble(),c, nome->text());
    }
    return tr;
}

void TriangleCreator::inserisciColore(QIcon icona, QString nome)
{
    colori->addItem(icona, nome);
}

void TriangleCreator::dueLatiUnAngolo(){
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

    connect(saveButton, SIGNAL(clicked()), this, SLOT(creaTriangolo()));

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

void TriangleCreator::dueAngoliUnLato(){
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

    connect(saveButton, SIGNAL(clicked()), this, SLOT(creaTriangolo()));

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

void TriangleCreator::treLati(){
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

    connect(saveButton, SIGNAL(clicked()), this, SLOT(creaTriangolo()));

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

void TriangleCreator::creaTriangolo()try{
    Triangolo* tr = buildTriangolo();
    selettore->insertItem(tr);
    emit selettore->insertPoligono(tr->getNome());
}
catch (WrongPolygon){}
catch (MyException){}
