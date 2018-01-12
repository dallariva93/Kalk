#ifndef OPERANDSELECTOR_H
#define OPERANDSELECTOR_H

#include "MODEL/poligono.h"
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVector>

class OperandSelector : public QWidget{
    Q_OBJECT
private:
    QLabel *operando;
    QComboBox *selector;
    QHBoxLayout *mainLayout;

public:
    OperandSelector(QString numero, QWidget *parent = 0);
    Poligono& operando1Corrente(QString);

signals:

public slots:


};

#endif // OPERANDSELECTOR_H
