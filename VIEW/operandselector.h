#ifndef OPERANDSELECTOR_H
#define OPERANDSELECTOR_H

#include "MODEL/poligono.h"
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>*/
#include <QVector>
#include <QMessageBox>
#include "MODEL/container.h"
#include "boxbutton.h"

class OperandSelector : public QWidget{
    Q_OBJECT
private:
    QLabel *operando;
    QComboBox *selector;        //contiene i nomi
    QHBoxLayout *mainLayout;
    Container* contenitore;     //contiene oggetti

public:
    ~OperandSelector();
    OperandSelector(QString, Container*, QWidget *parent = 0);
    void insertItem(Colore*);
    void insertItem(Poligono*);
    Colore* getColore(QString);
    bool isPresent(QString);
    void calcolaSomma1(QString);
    void calcolaSottrazione1(QString);
    void calcolaMoltiplicazione1(QString);
    void calcolaDivisione1(QString);


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
    void abilitaBottPol();
    void abilitaBottCol();
    void abSoloSomma();
    void changeButton(QString);
    void aggColore(Colore*);

    void polDaInserire(QString);
    void stampaSommaPoligono(Poligono*);

    void insertPolCol(QString);

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
    void activeButtonUno(QString);
    void activeButtonDue(QString);
    void scalaOpUno(QString);
    void ruotaOpUno();

    void textChanged(QString);

};

#endif // OPERANDSELECTOR_H
