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



DrawArea::DrawArea(Poligono * pol):poligono(pol){}  //non ho bisogno di copie profonde

void DrawArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::SolidLine);

    Poligono& poligonoDisegnato=poligono->specchia();
    sposta(&poligonoDisegnato,150,300);

    painter.drawPolygon(poligonoDisegnato.toQPolygon());

}

