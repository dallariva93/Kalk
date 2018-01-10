#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include "drawarea.h"
#include "dataarea.h"
#include "colorarea.h"
#include "polygoncreator.h"
#include "colorcreator.h"
#include "operandselector.h"

class Window : public QWidget
{
    Q_OBJECT
public:
    PolygonCreator *creatorP;
    ColorCreator *creatorC;
    DrawArea *areaP;
    DataArea *areaD;
    OperandSelector *operandoUno;
    OperandSelector *operandoDue;

    QHBoxLayout *areaLayout;
    QHBoxLayout *creatorLayout;
    QHBoxLayout *operandLayout;
    QVBoxLayout *mainLayout;

public:
    Window(QWidget *parent = 0);

signals:

public slots:
};

#endif // WINDOW_H
