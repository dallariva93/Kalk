#include "pentagoncreator.h"
#include <QLineEdit>

PentagonCreator::PentagonCreator(QWidget *parent) : QWidget(parent)
{
    QSize size(500,200);
    setMaximumSize(size);
    setMinimumSize(size);

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
    colori= new QComboBox;
    colori->addItem(QString("colori"));

    connect(radio1, SIGNAL(clicked(bool)), this, SLOT(formRegolare(bool)));
    connect(radio2, SIGNAL(clicked(bool)), this, SLOT(formIrregolare(bool)));

    choiceLayout = new QVBoxLayout;
    choiceLayout->addWidget(radio1);
    choiceLayout->addWidget(radio2);

    formLayout = new QGridLayout;
    formLayout->addWidget(latoA,0,0);
    formLayout->addWidget(lato1,0,1);
    formLayout->addWidget(colore,0,2);
    formLayout->addWidget(colori,0,3);


    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(choiceLayout);
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(saveButton);
    setLayout(mainLayout);
}

void PentagonCreator::refreshFormWidget()
{
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


}

void PentagonCreator::formIrregolare(bool)
{
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

    formLayout->addWidget(latoA,0,0);
    formLayout->addWidget(lato1,0,1);
    formLayout->addWidget(latoB,0,2);
    formLayout->addWidget(lato2,0,3);
    formLayout->addWidget(latoC,0,4);
    formLayout->addWidget(lato3,0,5);
    formLayout->addWidget(latoD,0,6);
    formLayout->addWidget(lato4,0,7);
    formLayout->addWidget(latoE,1,0);
    formLayout->addWidget(lato5,1,1);
    formLayout->addWidget(angoloA,1,2);
    formLayout->addWidget(angolo1,1,3);
    formLayout->addWidget(angoloB,1,4);
    formLayout->addWidget(angolo2,1,5);
    formLayout->addWidget(angoloC,1,6);
    formLayout->addWidget(angolo3,1,7);
    formLayout->addWidget(angoloD,2,0);
    formLayout->addWidget(angolo4,2,1);
    formLayout->addWidget(angoloE,2,2);
    formLayout->addWidget(angolo5,2,3);
    formLayout->addWidget(colore,2,4);
    formLayout->addWidget(colori,2,5);

    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(saveButton);

}

void PentagonCreator::formRegolare(bool)
{
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

    formLayout->addWidget(latoA,0,0);
    formLayout->addWidget(lato1,0,1);
    formLayout->addWidget(colore,0,2);
    formLayout->addWidget(colori,0,3);

    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(saveButton);
}

