#include "operandselector.h"
#include "MODEL/triangolo.h"
#include "MODEL/quadrilatero.h"
#include "MODEL/pentagono.h"

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

//    connect(selector,SIGNAL(currentTextChanged(QString)), this, SLOT(textChanged(QString)));
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
}

void OperandSelector::addPoligono(QString p){
    selector->addItem(p);
}

Colore *OperandSelector::getColore(QString nome){
    return contenitore->getColore(nome);
}

bool OperandSelector::isPresent(QString nome)
{
    return selector->findText(nome)!=-1;
}

void OperandSelector::addColore(Colore *c){
    insertItem(c);
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

void OperandSelector::sommaOpUno(){     //emette un segnale col nome dell'operando corrente
    QString name = selector->currentText();
    emit sommaUno(name);
}

void OperandSelector::calcolaSomma(QString name1){
    QString name2 = selector->currentText();
    if(name1.contains("#")){
        Colore& col1 = *(contenitore->getColore(name1));
        if(name2.contains("#")){
            Colore& col2 = *(contenitore->getColore(name2));
            Colore& somma = col1 + col2;
            emit aggColore(&somma);
            emit(stampaSomma(somma.getHex()));
        }
        else{
            Poligono* pol2= (contenitore->getPoligono(name2))->clone();
            Colore & sommaC = col1 + *(pol2->getColore());
            pol2->changeColor(sommaC);
            QString name = QString(name1.remove("#")+"+"+pol2->getNome());
            pol2->setNome(name);
            contenitore->addPoligono(pol2);
            selector->addItem(pol2->getNome());     //ho inserito solo il nome
            emit insertPoligono(pol2->getNome());
            emit inseritoPoligono(pol2->getNome());
        }
    }
    else{
        Poligono& pol1 = *( (contenitore->getPoligono(name1))->clone());
        if(name2.contains("#")){
            Colore & c = *(contenitore->getColore(name2));
            Colore & sommaC = c + *(pol1.getColore());
            pol1.changeColor(sommaC);
            QString nome = QString(pol1.getNome()+"+"+name2.remove("#"));
            pol1.setNome(nome);
            contenitore->addPoligono(&pol1);
            selector->addItem(pol1.getNome());
            emit insertPoligono(pol1.getNome());
            emit inseritoPoligono(pol1.getNome());  //per farlo vedere subito appena schiaccia +
        }
        else{
            Poligono* pol1 = (contenitore->getPoligono(name1))->clone();
            Poligono* pol2 = (contenitore->getPoligono(name2))->clone();
            Poligono& pTot = *pol1 + *pol2;
            QString nome = QString(pol1->getNome()+"+"+pol2->getNome());
            pTot.setNome(nome);
            contenitore->addPoligono(&pTot);
            selector->addItem(pTot.getNome());
            emit insertPoligono(pTot.getNome());
            emit inseritoPoligono(pTot.getNome());
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
    Colore& col2 = *(contenitore->getColore(name2));
    Colore& sottraggo = col1 - col2;
    emit aggColore(&sottraggo);
    emit(stampaSottrazione(sottraggo.getHex()));
}

void OperandSelector::moltiplicazioneOpUno(){
    QString name = selector->currentText();
    emit moltiplicazioneUno(name);
}

void OperandSelector::calcolaMoltiplicazione(QString name1){
    QString name2 = selector->currentText();
    Colore& col1 = *(contenitore->getColore(name1));
    Colore& col2 = *(contenitore->getColore(name2));
    Colore& molt = col1 * col2;
    emit aggColore(&molt);
    emit(stampaMoltiplicazione(molt.getHex()));
}

void OperandSelector::divisioneOpUno(){
    QString name = selector->currentText();
    emit divisioneUno(name);
}

void OperandSelector::calcolaDivisione(QString name1){
    QString name2 = selector->currentText();
    Colore& col1 = *(contenitore->getColore(name1));
    Colore& col2 = *(contenitore->getColore(name2));
    Colore& div = col1 / col2;
    emit aggColore(&div);
    emit(stampaDivisione(div.getHex()));
}

void OperandSelector::textChanged(QString text){
   emit changeButton(text);
}

void OperandSelector::activeButtonUno(QString opUno){
    QString opDue = selector->currentText();
    if(opUno.contains("#")){
        if(opDue.contains("#"))
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
    if(opDue.contains("#")){
        if(opUno.contains("#"))
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
