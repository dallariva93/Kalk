#include "trianglecreator.h"

TriangleCreator::TriangleCreator(QWidget *parent) : QWidget(parent){
    setWindowTitle("Triangle!");      //titolo finestra

    resize(400,400);    //style da fare a parte

    QGroupBox *groupBox = new QGroupBox(tr("Selezionare in base ai dati a disposizione: "),this);

    QRadioButton *radio1 = new QRadioButton(tr("Costruisco dato due lati e angolo compreso."),this);
    QRadioButton *radio2 = new QRadioButton(tr("Costruisco dato un lato e due angoli adiacenti."),this);
    QRadioButton *radio3 = new QRadioButton(tr("Costruisco dato i tre lati."),this);
    radio1->setChecked(true);   //setto di default radio1

    QLineEdit* lato1 = new QLineEdit(this);
    QLineEdit* lato2 = new QLineEdit(this);
    QLineEdit* angolo1 = new QLineEdit(this);

    QLabel* latoA = new QLabel(tr("LatoA:"));
    QLabel* latoB = new QLabel(tr("LatoB:"));
    QLabel* angoloA = new QLabel(tr("Angolo:"));

    QPushButton* botton = new QPushButton(tr("Crea"), this);

    connect(radio1, SIGNAL(), this, SLOT());

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(radio1);
    vbox->addWidget(radio2);
    vbox->addWidget(radio3);
    //vbox->addStretch(1);
    vbox->addWidget(latoA);
    vbox->addWidget(lato1);
    vbox->addWidget(latoB);
    vbox->addWidget(lato2);
    vbox->addWidget(angoloA);
    vbox->addWidget(angolo1);
    vbox->addWidget(botton);
    groupBox->setLayout(vbox);
}
