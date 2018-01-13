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
    QComboBox *selector;
    QHBoxLayout *mainLayout;
    Container* contenitore;

public:
    OperandSelector(QString, Container*, QWidget *parent = 0);
    Poligono& operando1Corrente(QString);
    void insertItem(Colore*);
    void insertItem(Poligono*);

signals:

public slots:
    void addColore(Colore*);


};

#endif // OPERANDSELECTOR_H
