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

    connect(selector,SIGNAL(currentTextChanged(QString)), this, SLOT(textChanged(QString)));
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

Colore *OperandSelector::getColore(QString nome){
    return contenitore->getColore(nome);
}

void OperandSelector::addColore(Colore *c){
    insertItem(c);
}

void OperandSelector::calcolaPerimetro(){
    QString name = selector->currentText();
    if(name.compare("#"))  //allora è un colore
        std::cout<<"lancerà una eccezione xk non posso calcolare il perimetro dato il colore"<<std::endl;
    Poligono* pol = contenitore->getPoligono(name);
    double pp = pol->getPerimetro();
    emit inviaPerimetro(pp);
}

void OperandSelector::calcolaArea(){
    QString name = selector->currentText();
    if(name.compare("#"))  //allora è un colore
        std::cout<<"pop-up"<<std::endl;
    Poligono* pol = contenitore->getPoligono(name);
    double a = pol->getArea();
    emit inviaArea(a);
}

void OperandSelector::calcolaAngoli(){
    QString name = selector->currentText();
    if(name.compare("#"))  //allora è un colore
        std::cout<<"pop-up angoli"<<std::endl;
    QVector<Angolo> a;
    Poligono* pol = contenitore->getPoligono(name);
    a = pol->getAngoli();
    emit inviaAngoli(a);
}

void OperandSelector::calcolaLati(){
    QString name = selector->currentText();
    if(name.compare("#"))  //allora è un colore
        std::cout<<"pop-up lati"<<std::endl;
    QVector<double> l;
    Poligono* pol =  contenitore->getPoligono(name) ;
    l = pol->getLati();
    emit inviaLati(l);
}

void OperandSelector::sommaOpUno(){     //emette un segnale col nome dell'operando corrente
    QString name = selector->currentText();
    emit sommaUno(name);
}

void OperandSelector::calcolaSomma(QString name1){
    QString name2 = selector->currentText();
    if(name1.compare("#")){  //allora operaore 1 è un colore
        Colore& col1 = *(contenitore->getColore(name1));   //colore operando 1
        if(name2.compare("#")){ //somma tra colori
            Colore& col2 = *(contenitore->getColore(name2));   //colore operando 2
            Colore& somma = col1 + col2;
            emit(stampaSomma(somma.getHex()));
        }
        else{
            std::cout<<"somma colore e poligono"<<std::endl;
        }
    }
    else{   //operatore 2 è un poligono
        Poligono& pol1 = *( contenitore->getPoligono(name1));   //colore operando 1
        if(name2.compare("#")){ //somma tra colori
            std::cout<<"somma poligono e colore"<<std::endl;
        }
        else{
            std::cout<<"somma poligoni"<<std::endl;
        }
    }
}

void OperandSelector::sottrazioneOpUno(){     //emette un segnale col nome dell'operando corrente
    QString name = selector->currentText();
    emit sottrazioneUno(name);
}

void OperandSelector::calcolaSottrazione(QString name1){
    QString name2 = selector->currentText();
    Colore& col1 = *(contenitore->getColore(name1));
    if(name1.compare("#") && name2.compare("#")){
        Colore& col2 = *(contenitore->getColore(name2));
        Colore& sottraggo = col1 - col2;
        emit(stampaSottrazione(sottraggo.getHex()));
    }
    else{
        std::cout<<"lancerà una eccezione non posso sottrarre poligoni"<<std::endl;
    }
}

void OperandSelector::moltiplicazioneOpUno(){
    QString name = selector->currentText();
    emit moltiplicazioneUno(name);
}

void OperandSelector::calcolaMoltiplicazione(QString name1){
    QString name2 = selector->currentText();
    Colore& col1 = *(contenitore->getColore(name1));
    if(name1.compare("#") && name2.compare("#")){
        Colore& col2 = *(contenitore->getColore(name2));
        Colore& molt = col1 * col2;
        emit(stampaMoltiplicazione(molt.getHex()));
    }
    else{
        std::cout<<"lancerà una eccezione non posso moltiplicare poligoni"<<std::endl;
    }
}

void OperandSelector::divisioneOpUno(){
    QString name = selector->currentText();
    emit divisioneUno(name);
}

void OperandSelector::calcolaDivisione(QString name1){
    QString name2 = selector->currentText();
    Colore& col1 = *(contenitore->getColore(name1));
    if(name1.compare("#") && name2.compare("#")){
        Colore& col2 = *(contenitore->getColore(name2));
        Colore& div = col1 / col2;
        emit(stampaDivisione(div.getHex()));
    }
    else{
        std::cout<<"lancerà una eccezione non posso dividere poligoni"<<std::endl;
    }
}

void OperandSelector::addPoligono(QString poligono){
    selector->addItem(poligono);
}

void OperandSelector::textChanged(QString text){
    if(!text.contains("#")){
        //std::cout<<text.toStdString();
        emit inseritoPoligono(text);
    }
}


