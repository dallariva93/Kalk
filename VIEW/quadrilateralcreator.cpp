#include"VIEW/quadrilateralcreator.h"
#include<QLineEdit>
#include<iostream>
#include"exception.h"

QuadrilateralCreator::QuadrilateralCreator( OperandSelector *sel, QWidget *parent) : QWidget(parent), selettore(sel){

    QSize size(500,350);
    setMaximumSize(size);

    colori=new QComboBox;

    radio1 = new QRadioButton(tr("Costruisco un quadrato"),this);
    radio2 = new QRadioButton(tr("Costruisco un rettangolo"),this);
    radio3 = new QRadioButton(tr("Costruisco un quadrilatero irregolare"),this);
    radio1->setChecked(true);

    lato1 = new QLineEdit(this);
    lato2 = new QLineEdit(this);
    lato3 = new QLineEdit(this);
    lato4 = new QLineEdit(this);
    angolo1 = new QLineEdit(this);
    angolo2 = new QLineEdit(this);
    angolo3 = new QLineEdit(this);
    angolo4 = new QLineEdit(this);
    nome = new QLineEdit(this);

    lato2->setVisible(false);
    lato3->setVisible(false);
    lato4->setVisible(false);
    angolo1->setVisible(false);
    angolo2->setVisible(false);
    angolo3->setVisible(false);
    angolo4->setVisible(false);

    latoA = new QLabel(tr("Lato A:"));
    latoB = new QLabel(tr("Lato B:"));
    latoC= new QLabel(tr("Lato C:"));
    latoD= new QLabel(tr("Lato D:"));
    angoloA = new QLabel(tr("Angolo:"));
    angoloB = new QLabel(tr("Angolo:"));
    angoloC = new QLabel(tr("Angolo:"));
    angoloD = new QLabel(tr("Angolo:"));
    colore = new QLabel(tr("Colore:"));
    labelNome = new QLabel(tr("Nome:"));

    latoB->setVisible(false);
    latoC->setVisible(false);
    latoD->setVisible(false);
    angoloA->setVisible(false);
    angoloB->setVisible(false);
    angoloC->setVisible(false);
    angoloD->setVisible(false);

    saveButton = new QPushButton(tr("Crea"), this);

    connect(radio1, SIGNAL(clicked()), this, SLOT(formQuadrato()));
    connect(radio2, SIGNAL(clicked()), this, SLOT(formRettangolo()));
    connect(radio3, SIGNAL(clicked()), this, SLOT(formQuadrilatero()));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(creaQuadrilatero()));

    choiceLayout = new QVBoxLayout;
    choiceLayout->addWidget(radio1);
    choiceLayout->addWidget(radio2);
    choiceLayout->addWidget(radio3);

    formLayout = new QGridLayout;
    formLayout->addWidget(latoA,0,0);
    formLayout->addWidget(lato1,0,1);
    formLayout->addWidget(colore,0,2);
    formLayout->addWidget(colori,0,3);
    formLayout->addWidget(labelNome,0,4);
    formLayout->addWidget(nome,0,5);

    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(choiceLayout);
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(saveButton);
    setLayout(mainLayout);
}

void QuadrilateralCreator::inserisciColore(QIcon icona, QString nome){
    colori->addItem(icona, nome);
}

void QuadrilateralCreator::refreshFormWidget(){
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
    formLayout->removeWidget(colore);
    formLayout->removeWidget(labelNome);
    formLayout->removeWidget(nome);

    delete lato1;
    delete lato2;
    delete lato3;
    delete lato4;
    delete latoA;
    delete latoB;
    delete latoC;
    delete latoD;
    delete angolo1;
    delete angolo2;
    delete angolo3;
    delete angolo4;
    delete angoloA;
    delete angoloB;
    delete angoloC;
    delete angoloD;
    delete colore;
    delete nome;
    delete labelNome;

    lato1 = new QLineEdit(this);
    lato2 = new QLineEdit(this);
    lato3 = new QLineEdit(this);
    lato4 = new QLineEdit(this);
    angolo1 = new QLineEdit(this);
    angolo2 = new QLineEdit(this);
    angolo3 = new QLineEdit(this);
    angolo4 = new QLineEdit(this);
    latoA = new QLabel(tr("Lato A:"));
    latoB = new QLabel(tr("Lato B:"));
    latoC= new QLabel(tr("Lato C:"));
    latoD= new QLabel(tr("Lato D:"));
    angoloA = new QLabel(tr("Angolo:"));
    angoloB = new QLabel(tr("Angolo:"));
    angoloC = new QLabel(tr("Angolo:"));
    angoloD = new QLabel(tr("Angolo:"));
    colore = new QLabel(tr("Colore:"));
    nome = new QLineEdit(this);
    labelNome = new QLabel(tr("Nome:"));
}

QuadrilateralCreator::~QuadrilateralCreator(){
    delete  radio1;
    delete radio2;
    delete radio3;
    delete  lato1;
    delete lato2;
    delete lato3;
    delete lato4;
    delete latoA;
    delete latoB;
    delete latoC;
    delete latoD;
    delete angolo1;
    delete angolo2;
    delete angolo3;
    delete angolo4;
    delete nome;
    delete angoloA;
    delete angoloB;
    delete angoloC;
    delete angoloD;
    delete labelNome;
    delete colore;
    delete saveButton;
    delete mainLayout;
    delete choiceLayout;
    delete colorLayout;
    delete formLayout;
    delete colori;
}

Quadrilatero *QuadrilateralCreator::buildQuadrilatero(){
    Colore*c;
    colori->count()==0 ? c=new RGB() : c=selettore->getColore(colori->currentText())->clone();
    Quadrilatero *qu;
    if(radio1->isChecked()){    //quadrato
        if(!lato1->text().toDouble() || nome->text().isEmpty())
            throw SyntaxError("I lati e gli angoli accettano solo valori numerici. \nInoltre i Form non possono essere vuoti.");
        if(nome->text().startsWith("#"))
            throw SyntaxError("Il nome non può iniziare con il carattere #");
        if(selettore->isPresent(nome->text()))
            throw AlreadyPresent("Nome già presente!");
        qu = new Quadrato(lato1->text().toDouble(), c, nome->text());
    }
    else if(radio2->isChecked()){
        if(!lato1->text().toDouble() || nome->text().isEmpty())
            throw SyntaxError("I lati e gli angoli accettano solo valori numerici. \nInoltre i Form non possono essere vuoti.");
        if(nome->text().startsWith("#"))
            throw SyntaxError("Il nome non può iniziare con il carattere #");
        if(selettore->isPresent(nome->text()))
            throw AlreadyPresent("Nome già presente!");
        qu = new Quadrilatero(lato1->text().toDouble(), lato2->text().toDouble(), lato2->text().toDouble(), 90, 90, c, nome->text());
    }
    else{
        if(!checkValidity())
            throw SyntaxError("I lati e gli angoli accettano solo valori numerici. \nInoltre i Form non possono essere vuoti.");
        if(nome->text().startsWith("#"))
            throw SyntaxError("Il nome non può iniziare con il carattere #");
        if(selettore->isPresent(nome->text()))
            throw AlreadyPresent("Nome già presente!");
        qu = new Quadrilatero(lato1->text().toDouble(), lato2->text().toDouble(), lato2->text().toDouble(),
                              angolo1->text().toDouble(), angolo2->text().toDouble(), c, nome->text());
    }
    if(!qu->checkConvexity()){
        delete qu;
        throw WrongPolygon("Pentagono Concavo");
    }
    return qu;
}

bool QuadrilateralCreator::checkValidity()
{
    if(!lato1->text().toDouble() || !lato2->text().toDouble() || !lato3->text().toDouble() || !lato4->text().toDouble()
         || !angolo1->text().toDouble() || !angolo2->text().toDouble() || !angolo3->text().toDouble()
            || !angolo4->text().toDouble() || nome->text().isEmpty() )
        return false;
    return true;

}

void QuadrilateralCreator::formQuadrato(){
    refreshFormWidget();
    delete formLayout;
    mainLayout->removeWidget(saveButton);
    delete saveButton;
    saveButton=new QPushButton(tr("Crea"), this);
    formLayout=new QGridLayout;

    lato1->setVisible(true);
    latoA->setVisible(true);
    lato2->setVisible(false);
    latoB->setVisible(false);
    lato3->setVisible(false);
    latoC->setVisible(false);
    lato4->setVisible(false);
    latoD->setVisible(false);

    angolo1->setVisible(false);
    angoloA->setVisible(false);
    angolo2->setVisible(false);
    angoloB->setVisible(false);
    angolo3->setVisible(false);
    angoloC->setVisible(false);
    angolo4->setVisible(false);
    angoloD->setVisible(false);

    connect(saveButton, SIGNAL(clicked()), this, SLOT(creaQuadrilatero()));

    formLayout->addWidget(latoA,0,0);
    formLayout->addWidget(lato1,0,1);
    formLayout->addWidget(colore,0,2);
    formLayout->addWidget(colori,0,3);
    formLayout->addWidget(labelNome,0,4);
    formLayout->addWidget(nome,0,5);

    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(saveButton);
}

void QuadrilateralCreator::formRettangolo(){
    refreshFormWidget();
    delete formLayout;
    mainLayout->removeWidget(saveButton);
    delete saveButton;
    saveButton=new QPushButton(tr("Crea"), this);
    formLayout=new QGridLayout;

    lato1->setVisible(true);
    latoA->setVisible(true);
    lato2->setVisible(true);
    latoB->setVisible(true);
    lato3->setVisible(false);
    latoC->setVisible(false);
    lato4->setVisible(false);
    latoD->setVisible(false);

    angolo1->setVisible(false);
    angoloA->setVisible(false);
    angolo2->setVisible(false);
    angoloB->setVisible(false);
    angolo3->setVisible(false);
    angoloC->setVisible(false);
    angolo4->setVisible(false);
    angoloD->setVisible(false);

    connect(saveButton, SIGNAL(clicked()), this, SLOT(creaQuadrilatero()));

    formLayout->addWidget(latoA,0,0);
    formLayout->addWidget(lato1,0,1);
    formLayout->addWidget(latoB,0,2);
    formLayout->addWidget(lato2,0,3);
    formLayout->addWidget(colore,1,0);
    formLayout->addWidget(colori,1,1);
    formLayout->addWidget(labelNome,1,2);
    formLayout->addWidget(nome,1,3);

    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(saveButton);
}

void QuadrilateralCreator::formQuadrilatero(){
    refreshFormWidget();
    delete formLayout;
    mainLayout->removeWidget(saveButton);
    delete saveButton;
    saveButton=new QPushButton(tr("Crea"), this);
    formLayout=new QGridLayout;

    lato1->setVisible(true);
    latoA->setVisible(true);
    lato2->setVisible(true);
    latoB->setVisible(true);
    lato3->setVisible(true);
    latoC->setVisible(true);
    lato4->setVisible(true);
    latoD->setVisible(true);

    angolo1->setVisible(true);
    angoloA->setVisible(true);
    angolo2->setVisible(true);
    angoloB->setVisible(true);
    angolo3->setVisible(true);
    angoloC->setVisible(true);
    angolo4->setVisible(true);
    angoloD->setVisible(true);

    connect(saveButton, SIGNAL(clicked()), this, SLOT(creaQuadrilatero()));

    formLayout->addWidget(latoA,0,0);
    formLayout->addWidget(lato1,0,1);
    formLayout->addWidget(latoB,0,2);
    formLayout->addWidget(lato2,0,3);
    formLayout->addWidget(latoC,0,4);
    formLayout->addWidget(lato3,0,5);
    formLayout->addWidget(latoD,1,0);
    formLayout->addWidget(lato4,1,1);
    formLayout->addWidget(angoloA,1,2);
    formLayout->addWidget(angolo1,1,3);
    formLayout->addWidget(angoloB,1,4);
    formLayout->addWidget(angolo2,1,5);
    formLayout->addWidget(angoloC,2,0);
    formLayout->addWidget(angolo3,2,1);
    formLayout->addWidget(angoloD,2,2);
    formLayout->addWidget(angolo4,2,3);
    formLayout->addWidget(labelNome,2,4);
    formLayout->addWidget(nome,2,5);

    colorLayout = new QHBoxLayout;
    colorLayout->addWidget(colore);
    colorLayout->addWidget(colori);

    mainLayout->addLayout(formLayout);
    mainLayout->addLayout(colorLayout);
    mainLayout->addWidget(saveButton);
}

void QuadrilateralCreator::creaQuadrilatero()try{
    Quadrilatero *qu=buildQuadrilatero();
    selettore->insertItem(qu);
    emit selettore->insertPoligono(qu->getNome());
    emit selettore->inseritoPoligono(qu->getNome());
}
catch (SyntaxError){}
catch (WrongPolygon){}
catch (AlreadyPresent){}
catch (MyException){}
