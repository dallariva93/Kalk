#include "operandselector.h"
#include "MODEL/triangolo.h"
#include "MODEL/quadrilatero.h"
#include "MODEL/pentagono.h"
#include <QtAlgorithms>
#include "exception.h"

OperandSelector::~OperandSelector(){
    delete operando;
    delete selector;
    delete mainLayout;
    delete contenitore;
}

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
    connect(selector, SIGNAL(activated(QString)), this, SLOT(textChanged(QString)));
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
    aggiornaS();
}

void OperandSelector::addPoligono(QString p){
    selector->addItem(p);
    aggiornaS();
}

void OperandSelector::aggiornaS(){
    selector->setCurrentIndex(selector->count()-1);
}

Colore *OperandSelector::getColore(QString nome){
    return contenitore->getColore(nome);
}

bool OperandSelector::isPresent(QString nome){
    return selector->findText(nome)!=-1;
}

void OperandSelector::addColore(Colore *c){
    insertItem(c);
    aggiornaS();
}

void OperandSelector::calcolaPerimetro(){
    QString name = selector->currentText();
    Poligono* pol = contenitore->getPoligono(name);
    double pp = pol->getPerimetro();
    emit inviaPerimetro(pp);
}

void OperandSelector::calcolaArea(){
    QString name = selector->currentText();
    Poligono* pol = contenitore->getPoligono(name);
    double a = pol->getArea();
    emit inviaArea(a);
}

void OperandSelector::calcolaAngoli(){
    QString name = selector->currentText();
    QVector<Angolo> a;
    Poligono* pol = contenitore->getPoligono(name);
    a = pol->getAngoli();
    emit inviaAngoli(a);
}

void OperandSelector::calcolaLati(){
    QString name = selector->currentText();
    QVector<double> l;
    Poligono* pol =  contenitore->getPoligono(name) ;
    l = pol->getLati();
    emit inviaLati(l);
}

void OperandSelector::sommaOpUno(){
    QString name = selector->currentText();
    emit sommaUno(name);
}


void OperandSelector::calcolaSomma1(QString name1){
    QString name2 = selector->currentText();
    if(name1.startsWith("#")){
        Colore& col1 = *(contenitore->getColore(name1));
        if(name2.startsWith("#")){
            Colore& col2 = *(contenitore->getColore(name2));
            Colore& somma = col1 + col2;
            if(isPresent(somma.getHex()))
                throw AlreadyPresent("Il colore esiste già!");
            emit aggColore(&somma);
            emit(stampaSomma(somma.getHex()));
        }
        else{
            Poligono* pol2= (contenitore->getPoligono(name2))->clone();
            Colore & sommaC = col1 + *(pol2->getColore());
            QString name = QString(name1.remove("#")+"+"+pol2->getNome());
            if(isPresent(name))
                throw AlreadyPresent("Il poligono esiste già!");
            pol2->changeColor(sommaC);
            pol2->setNome(name);
            contenitore->addPoligono(pol2);
            selector->addItem(pol2->getNome());
            aggiornaS();
            emit insertPoligono(pol2->getNome());
            emit inseritoPoligono(pol2->getNome());
        }
    }
    else{
        Poligono& pol1 = *( (contenitore->getPoligono(name1))->clone());
        if(name2.startsWith("#")){
            Colore & c = *(contenitore->getColore(name2));
            Colore & sommaC = c + *(pol1.getColore());
            QString nome = QString(pol1.getNome()+"+"+name2.remove("#"));
            if(isPresent(nome))
                throw AlreadyPresent("Il poligono esiste già!");
            pol1.changeColor(sommaC);
            pol1.setNome(nome);
            contenitore->addPoligono(&pol1);
            selector->addItem(pol1.getNome());
            aggiornaS();
            emit insertPoligono(pol1.getNome());
            emit inseritoPoligono(pol1.getNome());
        }
        else{
            Poligono* pol1 = (contenitore->getPoligono(name1))->clone();
            Poligono* pol2 = (contenitore->getPoligono(name2))->clone();
            if(pol1->latoComune(*pol2)==0)
                throw WrongPolygon("Non esiste un lato in comune!");
            Poligono& pTot = *pol1 + *pol2;
            QString nome = QString(pol1->getNome()+"+"+pol2->getNome());
            if(isPresent(nome))
                throw AlreadyPresent("Il poligono esiste già!");
            pTot.setNome(nome);
            contenitore->addPoligono(&pTot);
            selector->addItem(pTot.getNome());
            aggiornaS();
            emit insertPoligono(pTot.getNome());
            emit inseritoPoligono(pTot.getNome());
        }
    }
}
void OperandSelector::calcolaSomma(QString name1)try{
    calcolaSomma1(name1);
}
catch(WrongPolygon){}
catch(MyException){}

void OperandSelector::sottrazioneOpUno(){
    QString name = selector->currentText();
    emit sottrazioneUno(name);
}

void OperandSelector::calcolaSottrazione1(QString name1){
    QString name2 = selector->currentText();
    Colore& col1 = *(contenitore->getColore(name1));
    Colore& col2 = *(contenitore->getColore(name2));
    Colore& sottraggo = col1 - col2;
    if(isPresent(sottraggo.getHex()))
        throw AlreadyPresent("Il colore esiste già!");
    emit aggColore(&sottraggo);
    emit(stampaSottrazione(sottraggo.getHex()));
}
void OperandSelector::calcolaSottrazione(QString name1)try{
    calcolaSottrazione1(name1);
}
catch(MyException){}

void OperandSelector::moltiplicazioneOpUno(){
    QString name = selector->currentText();
    emit moltiplicazioneUno(name);
}

void OperandSelector::calcolaMoltiplicazione1(QString name1){
    QString name2 = selector->currentText();
    Colore& col1 = *(contenitore->getColore(name1));
    Colore& col2 = *(contenitore->getColore(name2));
    Colore& molt = col1 * col2;
    if(isPresent(molt.getHex()))
        throw AlreadyPresent("Il colore esiste già!");
    emit aggColore(&molt);
    emit(stampaMoltiplicazione(molt.getHex()));
}
void OperandSelector::calcolaMoltiplicazione(QString name1)try{
    calcolaMoltiplicazione1(name1);
}
catch(MyException){}

void OperandSelector::divisioneOpUno(){
    QString name = selector->currentText();
    emit divisioneUno(name);
}

void OperandSelector::calcolaDivisione1(QString name1){
    QString name2 = selector->currentText();
    Colore& col1 = *(contenitore->getColore(name1));
    Colore& col2 = *(contenitore->getColore(name2));
    Colore& div = col1 / col2;
    if(isPresent(div.getHex()))
        throw AlreadyPresent("Il colore esiste già!");
    emit aggColore(&div);
    emit(stampaDivisione(div.getHex()));
}
void OperandSelector::calcolaDivisione(QString name1)try{
    calcolaDivisione1(name1);
}
catch(MyException){}

void OperandSelector::textChanged(QString text){
   emit changeButton(text);
}

void OperandSelector::activeButtonUno(QString opUno){
    QString opDue = selector->currentText();
    if(opUno.startsWith("#")){
        if(opDue.startsWith("#"))
            emit abilitaBottCol();
        else
            emit abSoloSomma();
    }
    else{
        emit inseritoPoligono(opUno);
        emit abilitaBottPol();
    }
}

void OperandSelector::activeButtonDue(QString opDue){
    QString opUno = selector->currentText();
    if(opDue.startsWith("#")){
        if(opUno.startsWith("#"))
            emit abilitaBottCol();
        else{
            emit abSoloSomma();
        }
    }
    else{
        emit inseritoPoligono(opDue);
        emit abilitaBottPol();
    }
}

void OperandSelector::scalaOpUno1(QString in){
    QString opUno = selector->currentText();
    Poligono* pol = contenitore->getPoligono(opUno);
    Poligono& pScal = pol->zoom(in.toDouble());
    pScal.setNome(opUno+"_inScala("+in+")");
    if(isPresent(pScal.getNome()))
        throw AlreadyPresent("Il poligono risultante è già esistente!");
    pScal.setColore(pol->getColore());
    contenitore->addPoligono(&pScal);
    selector->addItem(pScal.getNome());
    aggiornaS();
    emit insertPoligono(pScal.getNome());
}
void OperandSelector::scalaOpUno(QString in)try{
    scalaOpUno1(in);
}
catch(AlreadyPresent){}

void OperandSelector::ruotaOpUno(){
    QString opUno = selector->currentText();
    Poligono* pol = contenitore->getPoligono(opUno);
    pol->gira();
    emit inseritoPoligono(pol->getNome());
}
