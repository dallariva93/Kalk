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

    //connect(operando, SIGNAL(inviaOpUno(name)), operandoDue, SLOT(calcolaSommaDue(QString)));  //operando1 e operando2 vorrei
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

void OperandSelector::calcolaPerimetro(){
    QString name = selector->currentText();
    if(name.compare("#"))  //allora è un colore
        std::cout<<"lancerà una eccezione xk non posso calcolare il perimetro dato il colore"<<std::endl;
    //std::cout<<" name="<<name.toStdString()<<std::endl;
    double pp=123.456;

/*  //  DA AGGIUNGERE QUESTA PARTE QUANDO ABBIAMO I POLIGONI NEL SELECTOR

    Poligono* pol = contenitore->getPoligono(name);
    double pp = pol->getPerimetro();
*/
    emit inviaPerimetro(pp);
}

void OperandSelector::calcolaArea(){
    QString name = selector->currentText();
    if(name.compare("#"))  //allora è un colore
        std::cout<<"pop-up"<<std::endl;
    double a=987.654;
/*  //  DA AGGIUNGERE
    Poligono* pol = contenitore->getPoligono(name);
    double a = pol->getArea();
*/
    emit inviaArea(a);
}

void OperandSelector::calcolaAngoli(){
    QString name = selector->currentText();
    if(name.compare("#"))  //allora è un colore
        std::cout<<"pop-up angoli"<<std::endl;
    QVector<Angolo> a;
/*  //  DA AGGIUNGERE
    Poligono pol = contenitore->getPoligono(name);
    a = pol->getAngoli();
*/
    emit inviaAngoli(a);
}

void OperandSelector::calcolaLati(){
    QString name = selector->currentText();
    if(name.compare("#"))  //allora è un colore
        std::cout<<"pop-up lati"<<std::endl;
    QVector<double> l;
/*  //  DA AGGIUNGERE
    Poligono* pol =  contenitore->getPoligono(name) ;
    l = pol->getLati();
*/
    emit inviaLati(l);
}

void OperandSelector::sommaOpUno(){     //emette un segnale col nome dell'operando corrente
    QString name = selector->currentText();
    emit sommaUno(name);
}

void OperandSelector::calcolaSomma(QString name1){
    QString name2 = selector->currentText();
    std::cout<<" name op 1 ="<<name1.toStdString()<<"    name op 2 ="<<name2.toStdString()<<std::endl;
    if(name1.compare("#")){  //allora operaore 1 è un colore
        Colore* col1 = contenitore->getColore(name1);   //colore operando 1


        std::cout<<"DDDDDD "<<col1->getHex().toStdString()<<std::endl;
        /*   if(name2.compare("#")){ //somma tra colori
            std::cout<<"somma colori"<<std::endl;
            Colore* col2 = contenitore->getColore(name2);   //colore operando 2
            Colore& somma = *col1 + *col2;
            std::cout<<"somma="<<(somma.getHex()).toStdString()<<std::endl;
        }
        else{
            std::cout<<"somma colore e poligono"<<std::endl;
        }
    }
    else{   //operatore 2 è un poligono
        Poligono& col1 = *( contenitore->getPoligono(name1));   //colore operando 1
        if(name2.compare("#")){ //somma tra colori
            std::cout<<"somma poligono e colore"<<std::endl;

        }
        else{
            std::cout<<"somma poligoni"<<std::endl;
        }
        */
    }

}


