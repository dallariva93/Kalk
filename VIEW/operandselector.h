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

signals:
    void inviaPerimetro(double);
    void inviaArea(double);
    void inviaAngoli(QVector<Angolo>);
    void inviaLati(QVector<double>);
    void sommaUno(QString);

public slots:
    void addColore(Colore*);
    void calcolaPerimetro();
    void calcolaArea();
    void calcolaAngoli();
    void calcolaLati();
    void sommaOpUno();
    void calcolaSomma(QString);
};

#endif // OPERANDSELECTOR_H
