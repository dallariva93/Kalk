#include "pentagoncreator.h"
#include <QLineEdit>
#include "exception.h"


PentagonCreator::~PentagonCreator()
{
    delete radio1;
    delete radio2;

    delete lato1;
    delete lato2;
    delete lato3;
    delete lato4;
    delete lato5;
    delete angolo1;
    delete angolo2;
    delete angolo3;
    delete angolo4;
    delete angolo5;
    delete nome;

    delete latoA;
    delete latoB;
    delete latoC;
    delete latoD;
    delete latoE;
    delete angoloA;
    delete angoloB;
    delete angoloC;
    delete angoloD;
    delete angoloE;
    delete labelNome;

    delete colore;

    delete saveButton;
    delete mainLayout;
    delete choiceLayout;
    delete colorLayout;
    delete formLayout;
    delete colori;

}

PentagonCreator::PentagonCreator(OperandSelector *sel, QWidget *parent) : QWidget(parent), selettore(sel){
    QSize size(400,350);
    setMaximumSize(size);

    colori=new QComboBox;

    radio1 = new QRadioButton(tr("Costruisco un pentagono regolare"),this);
    radio2 = new QRadioButton(tr("Costruisco un pentagono irregolare"),this);
    radio1->setChecked(true);   //setto di default radio1

    lato1 = new QLineEdit(this);
    lato2 = new QLineEdit(this);
    lato3 = new QLineEdit(this);
    lato4 = new QLineEdit(this);
    lato5 = new QLineEdit(this);
    angolo1 = new QLineEdit(this);
    angolo2 = new QLineEdit(this);
    angolo3 = new QLineEdit(this);
    angolo4 = new QLineEdit(this);
    angolo5 = new QLineEdit(this);
    nome = new QLineEdit(this);

    lato2->setVisible(false);
    lato3->setVisible(false);
    lato4->setVisible(false);
    lato5->setVisible(false);

    angolo1->setVisible(false);
    angolo2->setVisible(false);
    angolo3->setVisible(false);
    angolo4->setVisible(false);
    angolo5->setVisible(false);

    latoA = new QLabel(tr("Lato A:"));
    latoB = new QLabel(tr("Lato B:"));
    latoC= new QLabel(tr("Lato C:"));
    latoD= new QLabel(tr("Lato D:"));
    latoE= new QLabel(tr("Lato E:"));
    angoloA = new QLabel(tr("Angolo:"));
    angoloB = new QLabel(tr("Angolo:"));
    angoloC = new QLabel(tr("Angolo:"));
    angoloD = new QLabel(tr("Angolo:"));
    angoloE = new QLabel(tr("Angolo:"));
    colore = new QLabel(tr("Colore:"));
    labelNome = new QLabel(tr("Nome:"));

    latoB->setVisible(false);
    latoC->setVisible(false);
    latoD->setVisible(false);
    latoE->setVisible(false);
    angoloA->setVisible(false);
    angoloB->setVisible(false);
    angoloC->setVisible(false);
    angoloD->setVisible(false);
    angoloE->setVisible(false);

    saveButton = new QPushButton(tr("Crea"), this);

    connect(radio1, SIGNAL(clicked()), this, SLOT(formRegolare()));
    connect(radio2, SIGNAL(clicked()), this, SLOT(formIrregolare()));
    connect(saveButton, SIGNAL(clicked()),this, SLOT(creaPentagono()));

    choiceLayout = new QVBoxLayout;
    choiceLayout->addWidget(radio1);
    choiceLayout->addWidget(radio2);

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

void PentagonCreator::refreshFormWidget(){
    formLayout->removeWidget(lato1);
    formLayout->removeWidget(lato2);
    formLayout->removeWidget(lato3);
    formLayout->removeWidget(lato4);
    formLayout->removeWidget(lato5);
    formLayout->removeWidget(latoD);
    formLayout->removeWidget(latoA);
    formLayout->removeWidget(latoB);
    formLayout->removeWidget(latoC);
    formLayout->removeWidget(latoE);
    formLayout->removeWidget(angolo1);
    formLayout->removeWidget(angolo2);
    formLayout->removeWidget(angoloA);
    formLayout->removeWidget(angoloB);
    formLayout->removeWidget(angolo3);
    formLayout->removeWidget(angolo4);
    formLayout->removeWidget(angolo5);
    formLayout->removeWidget(angoloC);
    formLayout->removeWidget(angoloD);
    formLayout->removeWidget(angoloE);
    formLayout->removeWidget(colore);
    formLayout->removeWidget(nome);
    formLayout->removeWidget(labelNome);

    delete lato1;
    delete lato2;
    delete lato3;
    delete lato4;
    delete lato5;
    delete latoA;
    delete latoB;
    delete latoC;
    delete latoD;
    delete latoE;
    delete angolo1;
    delete angolo2;
    delete angolo3;
    delete angolo4;
    delete angolo5;
    delete angoloA;
    delete angoloB;
    delete angoloC;
    delete angoloD;
    delete angoloE;
    delete colore;
    delete labelNome;
    delete nome;

    lato1 = new QLineEdit(this);
    lato2 = new QLineEdit(this);
    lato3 = new QLineEdit(this);
    lato4 = new QLineEdit(this);
    lato5 = new QLineEdit(this);
    angolo1 = new QLineEdit(this);
    angolo2 = new QLineEdit(this);
    angolo3 = new QLineEdit(this);
    angolo4 = new QLineEdit(this);
    angolo5 = new QLineEdit(this);
    nome = new QLineEdit(this);
    latoA = new QLabel(tr("Lato A:"));
    latoB = new QLabel(tr("Lato B:"));
    latoC= new QLabel(tr("Lato C:"));
    latoD= new QLabel(tr("Lato D:"));
    latoE= new QLabel(tr("Lato E:"));
    angoloA = new QLabel(tr("Angolo:"));
    angoloB = new QLabel(tr("Angolo:"));
    angoloC = new QLabel(tr("Angolo:"));
    angoloD = new QLabel(tr("Angolo:"));
    angoloE = new QLabel(tr("Angolo:"));
    colore = new QLabel(tr("Colore:"));
    labelNome = new QLabel(tr("Nome:"));
}

Pentagono *PentagonCreator::buildPentagono()
{
    Colore*c;
    colori->count()==0 ? c=new RGB() : c=selettore->getColore(colori->currentText())->clone();
    Pentagono* pent;

    if(radio1->isChecked()){    //il colore lo prendo dal contenitore, passando dal nome che ho qua, arrivando in selettore, matchando il nome su contenitore e ritornando il colore
        if(!lato1->text().toDouble() || nome->text().isEmpty())
            throw SyntaxError("I lati e gli angoli accettano solo valori numerici. \n Inoltre i Form non possono essere vuoti.");
        if(nome->text().startsWith("#"))
            throw SyntaxError("Il nome non può iniziare con il carattere #");
        if(selettore->isPresent(nome->text()))
            throw AlreadyPresent("Nome già presente!");
        pent = new Pentagono(lato1->text().toDouble(),c,nome->text());
    }
    else{
        if(!checkValidity())
            throw SyntaxError("I lati e gli angoli accettano solo valori numerici. \n Inoltre i Form non possono essere vuoti.");
        if(nome->text().startsWith("#"))
            throw SyntaxError("Il nome non può iniziare con il carattere #");
        if(selettore->isPresent(nome->text()))
            throw AlreadyPresent("Nome già presente!");
        pent = new Pentagono(lato1->text().toDouble(), lato2->text().toDouble(), lato3->text().toDouble(), lato4->text().toDouble(), lato5->text().toDouble(),
                             Angolo(angolo1->text().toDouble()), Angolo(angolo2->text().toDouble()), Angolo(angolo3->text().toDouble()), Angolo(angolo4->text().toDouble()),
                             Angolo(angolo5->text().toDouble()), c, nome->text());
    }
    if(!pent->checkConvexity()){
        delete pent;
        throw WrongPolygon("Pentagono Concavo");
    }
    return pent;
}

bool PentagonCreator::checkValidity()
{
    if(!lato1->text().toDouble() || !lato2->text().toDouble() || !lato3->text().toDouble() || !lato4->text().toDouble()
        || !lato5->text().toDouble() || !angolo1->text().toDouble() || !angolo2->text().toDouble() || !angolo3->text().toDouble()
            || !angolo4->text().toDouble() || !angolo5->text().toDouble() || nome->text().isEmpty() )
        return false;
    return true;

}

void PentagonCreator::inserisciColore(QIcon icona, QString nome)
{
    colori->addItem(icona, nome);
}

void PentagonCreator::formIrregolare(){
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
    lato5->setVisible(true);
    latoE->setVisible(true);

    angolo1->setVisible(true);
    angoloA->setVisible(true);
    angolo2->setVisible(true);
    angoloB->setVisible(true);
    angolo3->setVisible(true);
    angoloC->setVisible(true);
    angolo4->setVisible(true);
    angoloD->setVisible(true);
    angolo5->setVisible(true);
    angoloE->setVisible(true);

    connect(saveButton, SIGNAL(clicked()),this, SLOT(creaPentagono()));

    formLayout->addWidget(latoA,0,0);
    formLayout->addWidget(lato1,0,1);
    formLayout->addWidget(latoB,0,2);
    formLayout->addWidget(lato2,0,3);
    formLayout->addWidget(latoC,0,4);
    formLayout->addWidget(lato3,0,5);
    formLayout->addWidget(latoD,1,0);
    formLayout->addWidget(lato4,1,1);
    formLayout->addWidget(latoE,1,2);
    formLayout->addWidget(lato5,1,3);
    formLayout->addWidget(angoloA,1,4);
    formLayout->addWidget(angolo1,1,5);
    formLayout->addWidget(angoloB,2,0);
    formLayout->addWidget(angolo2,2,1);
    formLayout->addWidget(angoloC,2,2);
    formLayout->addWidget(angolo3,2,3);
    formLayout->addWidget(angoloD,2,4);
    formLayout->addWidget(angolo4,2,5);
    formLayout->addWidget(angoloE,3,0);
    formLayout->addWidget(angolo5,3,1);
    formLayout->addWidget(colore,3,2);
    formLayout->addWidget(colori,3,3);
    formLayout->addWidget(labelNome,3,4);
    formLayout->addWidget(nome,3,5);

    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(saveButton);
}

void PentagonCreator::formRegolare(){
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
    lato5->setVisible(false);
    latoE->setVisible(false);

    angolo1->setVisible(false);
    angoloA->setVisible(false);
    angolo2->setVisible(false);
    angoloB->setVisible(false);
    angolo3->setVisible(false);
    angoloC->setVisible(false);
    angolo4->setVisible(false);
    angoloD->setVisible(false);
    angolo5->setVisible(false);
    angoloE->setVisible(false);

    connect(saveButton, SIGNAL(clicked()),this, SLOT(creaPentagono()));

    formLayout->addWidget(latoA,0,0);
    formLayout->addWidget(lato1,0,1);
    formLayout->addWidget(colore,0,2);
    formLayout->addWidget(colori,0,3);
    formLayout->addWidget(labelNome,0,4);
    formLayout->addWidget(nome,0,5);

    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(saveButton);
}

void PentagonCreator::creaPentagono()try{
    Pentagono *pent = buildPentagono();
    selettore->insertItem(pent);
    emit selettore->insertPoligono(pent->getNome());
    emit selettore->inseritoPoligono(pent->getNome());
}
catch(EmptyField){}
catch(SyntaxError){}
catch(MyException){}
