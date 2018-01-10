#include "drawarea.h"
#include "QBoxLayout"
#include "MODEL/pentagonoregolare.h"
#include "MODEL/triangolo.h"
#include "MODEL/rettangolo.h"




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



void DrawArea::setPoligono(Poligono *pol)
{
    poligono=pol;
}

DrawArea::DrawArea(Poligono * pol):poligono(pol){
    QSize size(450,250);        //dimensione dell'area da disegno, se il poligono è più grande? PROBLEMA!
    setMaximumSize(size);
    setMinimumSize(size);

}  //non ho bisogno di copie profonde

void DrawArea::paintEvent(QPaintEvent *event)
{
    if(poligono)
    {
        QPainter painter(this);
        painter.setPen(QPen(QString::fromStdString(poligono->getColore()->getHex())));
        painter.setBrush(QBrush(QColor(QString::fromStdString(poligono->getColore()->getHex()))));

        //sposta(&poligonoDisegnato,10,10);
        //QPoint nuovaOrigine((poligono->getLati()[0]-250)/2);

        double xTo0=0;
        double yTo0=0;
        double neg=0;
        for(int i=0; i<poligono->getCoordinate().size(); ++i)
        {

            if(xTo0<poligono->getCoordinate()[i].getX())
                xTo0=poligono->getCoordinate()[i].getX();

            if(yTo0<poligono->getCoordinate()[i].getY())
                yTo0=poligono->getCoordinate()[i].getY();
            if(poligono->getCoordinate()[i].getX()<0 && neg>poligono->getCoordinate()[i].getX())
                neg=poligono->getCoordinate()[i].getX();
        }
        xTo0-=neg;
        std::cout<<xTo0<<"-"<<yTo0<<"|";

        Poligono& poligonoDisegnato=poligono->specchia();
        double scaledxTo0=0;
        double scaledyTo0=0;

        if(xTo0>=250 || yTo0>=250)
        {
            double scala;
            xTo0>yTo0 ? scala=(250/xTo0)-0.1 : scala=(250/yTo0)-0.1;
           painter.scale(scala,scala);
           scaledxTo0=xTo0*(scala);
           scaledyTo0=yTo0*(scala);
           painter.setViewport(((250-scaledxTo0)/2),(250-scaledyTo0)/2,250,250);
        }
        else
        {
             painter.setViewport((250-xTo0)/2,(250-yTo0)/2,250,250);
        }

painter.translate(0,yTo0);
    std::cout<<scaledxTo0<<"-"<<scaledyTo0;



    painter.drawPolygon(poligonoDisegnato.toQPolygon());
}
}

