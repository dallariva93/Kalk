#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include "drawarea.h"
#include "dataarea.h"
#include "polygoncreator.h"
#include "colorcreator.h"
#include "operandselector.h"
#include "boxbutton.h"

class Window : public QWidget{
    Q_OBJECT
public:
    PolygonCreator *creatorP;
    ColorCreator *creatorC;
    DrawArea *areaP;
    DataArea *areaD;
    OperandSelector *operandoUno;
    OperandSelector *operandoDue;
    BoxButtons *pulsanti;
    QComboBox* colori;
    Container* contenitore;
    QHBoxLayout *areaLayout;
    QHBoxLayout *creatorLayout;
    QHBoxLayout *operandLayout;
    QVBoxLayout *mainLayout;
    QVBoxLayout *colorCButtonsLayout;

public:
    Window(QWidget *parent = 0);

signals:
    void disegnaPoligono(Poligono*);

public slots:
    void acquisisciPoligono(QString);
    void hoPoligono(Poligono*);
};

#endif // WINDOW_H
