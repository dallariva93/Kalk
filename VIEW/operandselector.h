#ifndef OPERANDSELECTOR_H
#define OPERANDSELECTOR_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>
#include "MODEL/poligono.h"

class OperandSelector : public QWidget{
    Q_OBJECT
private:
    QLabel *operando;
    QComboBox *selector;
    QHBoxLayout *mainLayout;

public:
    OperandSelector(QWidget *parent = 0);
    Poligono& Operando1Corrente();

signals:

public slots:


};

#endif // OPERANDSELECTOR_H
