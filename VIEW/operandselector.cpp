#include "operandselector.h"

OperandSelector::OperandSelector(QString numero, Container *con, QWidget *parent) : QWidget(parent), contenitore(con){
    QSize size(325,45);
    setMaximumSize(size);
    setMinimumSize(size);

    selector = new QComboBox;
    operando = new QLabel;
    operando->setText("Operando "+numero+":");
    mainLayout = new QHBoxLayout;
    mainLayout->addWidget(operando);
    mainLayout->addWidget(selector);
    setLayout(mainLayout);
}

void OperandSelector::insertItem(Colore *colore){
    contenitore->addColore(colore);
    QPixmap pmap(20,15);
    pmap.fill(colore->toQcolor());
    QIcon icon(pmap);
    selector->addItem(icon,colore->getHex());
}

void OperandSelector::insertItem(Poligono* poligono){
    contenitore->addPoligono(poligono);
    selector->addItem(poligono->getNome());
}

/*
 * Poligono& OperandSelector::operando1Corrente() const{
    int index = selector->currentIndex();
    QString name =  *selector;     //index corrisponde al valore numerico in ordine al QVector di poligoni???
    if(0 == name.indexOf('#'))  //è un colore
        return 0;
    else
        return ;
}
*/

void OperandSelector::selezionato(){
   // int index = selector->currentIndex();


//    for( QVector<Container*>::iterator it=contenitore->
}

void OperandSelector::addColore(Colore *c){
    insertItem(c);
}
