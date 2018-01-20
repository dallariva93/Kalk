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
    //void inviaNome(QString);
    void inviaPerimetro(double);

public slots:
    void addColore(Colore*);
    //void selectedOp();     //slot che emette un segnale passando il nome di cosa è selezionato
    void calcolaPerimetro();

};

#endif // OPERANDSELECTOR_H
