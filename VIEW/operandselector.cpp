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

void OperandSelector::addColore(Colore *c){
    insertItem(c);
}
/*
void OperandSelector::selectedOp(){     //emette un segnale col nome dell'operando corrente
    QString name = selector->currentText();
    std::cout<<" name="<<name.toStdString()<<std::endl;
    emit inviaNome(name);

}*/

void OperandSelector::calcolaPerimetro(){
    QString name = selector->currentText();
    if(name.compare("#"))  //allora è un colore
        std::cout<<"lancerà una eccezione xk non posso calcolare il perimetro dato il colore"<<std::endl;
    //std::cout<<" name="<<name.toStdString()<<std::endl;
    double pp=123.456;

/*  //  DA AGGIUNGERE QUESTA PARTE QUANDO ABBIAMO I POLIGONI NEL SELECTOR

    Poligono& pol = *( contenitore->getPoligono(name) );
    double pp = pol.getPerimetro();
*/
    emit inviaPerimetro(pp);
}








