#ifndef OPERANDSELECTOR_H
#define OPERANDSELECTOR_H

#include "MODEL/poligono.h"
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVector>
#include "MODEL/container.h"
#include "colorcreator.h"

class OperandSelector : public QWidget{
    Q_OBJECT
private:
    QLabel *operando;
    QComboBox *selector;        //contiene i nomi
    QHBoxLayout *mainLayout;
    Container* contenitore;     //contiene oggetti

public:
    OperandSelector(QString, Container*, QWidget *parent = 0);
    void insertItem(Colore*);
    void insertItem(Poligono*);
    Colore* getColore(QString);

signals:
    void inviaPerimetro(double);
    void inviaArea(double);
    void inviaAngoli(QVector<Angolo>);
    void inviaLati(QVector<double>);
    void sommaUno(QString);
    void stampaSomma(QString);
    void sottrazioneUno(QString);
    void stampaSottrazione(QString);
    void moltiplicazioneUno(QString);
    void stampaMoltiplicazione(QString);
    void divisioneUno(QString);
    void stampaDivisione(QString);
    void insertPoligono(QString);
    void inseritoPoligono(QString);
    void riabilita();
    void disabilita();

    void stampaSommaPoligono(Poligono*);

public slots:
    void addColore(Colore*);
    void calcolaPerimetro();
    void calcolaArea();
    void calcolaAngoli();
    void calcolaLati();
    void sommaOpUno();
    void calcolaSomma(QString);
    void sottrazioneOpUno();
    void calcolaSottrazione(QString);
    void moltiplicazioneOpUno();
    void calcolaMoltiplicazione(QString);
    void divisioneOpUno();
    void calcolaDivisione(QString);
    void addPoligono(QString);
    void textChanged(QString);
};

#endif // OPERANDSELECTOR_H
