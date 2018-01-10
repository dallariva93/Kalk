#include "colorarea.h"
#include <QPainter>
#include <MODEL/quadrato.h>
#include <VIEW/colorcreator.h>


ColorArea::ColorArea(Colore * col):colore(col)
{
    QSize size(250,250);        //dimensione dell'area da disegno, se il poligono è più grande? PROBLEMA!
    setMaximumSize(size);
    setMinimumSize(size);
}

void ColorArea::setColore(Colore* col)
{
    colore=col;
}

void ColorArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPolygon(QPolygon(250));
    Quadrato quadrato(250);
    painter.setBrush((QBrush(colore->toQcolor())));
    painter.drawPolygon(quadrato.toQPolygon());
}

void ColorArea::colorChanged(QString str)
{
    colore=new RGB(str.mid(1,2).toUInt(),str.mid(3,2).toUInt(),str.mid(5,2).toUInt());
}
