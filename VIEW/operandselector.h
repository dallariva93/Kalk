#ifndef OPERANDSELECTOR_H
#define OPERANDSELECTOR_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>
#include "MODEL/poligono.h"
#include <QVector>

class OperandSelector : public QWidget{
    Q_OBJECT
private:
    QLabel *operando;
    QComboBox *selector;
    QHBoxLayout *mainLayout;
    QVector<Poligono*> selectorPolygon;
    QVector<Colore*> selectorColor;

public:
    OperandSelector(QString numero, QWidget *parent = 0);
    Poligono& Operando1Corrente(QString);

signals:

public slots:


};

#endif // OPERANDSELECTOR_H
