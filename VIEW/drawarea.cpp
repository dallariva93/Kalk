#include "drawarea.h"
#include "QBoxLayout"
#include "pentagonoregolare.h"
#include<triangolo.h>
#include <rettangolo.h>




void DrawArea::sposta(Poligono* pol,double x, double y)
{
    QVector<Punto> puntiNuovi;
    for(int i=0; i<pol->getLati().size(); ++i)
    {
        Punto punto(pol->getCoordinate()[i].getX()+x, pol->getCoordinate()[i].getY()+y);
        puntiNuovi.push_back(punto);
    }
    pol->setPunti(puntiNuovi);
}



DrawArea::DrawArea(Poligono * pol):poligono(pol){
    QSize size(250,250);        //dimensione dell'area da disegno, se il poligono è più grande? PROBLEMA!
    setMaximumSize(size);
    setMinimumSize(size);

}  //non ho bisogno di copie profonde

void DrawArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(QPen(QString::fromStdString(poligono->getColore()->getHex())));
    painter.setBrush(QBrush(QColor(QString::fromStdString(poligono->getColore()->getHex()))));

    Poligono& poligonoDisegnato=poligono->specchia();
    //sposta(&poligonoDisegnato,10,10);
    //QPoint nuovaOrigine((poligono->getLati()[0]-250)/2);

    painter.translate((QPoint(-((poligono->getLati()[0]-250)/2),100)));
    painter.drawPolygon(poligonoDisegnato.toQPolygon());

}

