#include "drawarea.h"
#include "QBoxLayout"
#include "MODEL/triangolo.h"
#include "MODEL/rettangolo.h"

void DrawArea::sposta(Poligono* pol,double x, double y){
    QVector<Punto> puntiNuovi;
    for(int i=0; i<pol->getLati().size(); ++i){
        Punto punto(pol->getCoordinate()[i].getX()+x, pol->getCoordinate()[i].getY()+y);
        puntiNuovi.push_back(punto);
    }
    pol->setPunti(puntiNuovi);
}

void DrawArea::setPoligono(Poligono *pol){
    poligono=pol;
}

DrawArea::DrawArea(Poligono * pol):poligono(pol){
    QSize size(400,250);
    setMaximumSize(size);
    setMinimumSize(size);
    setStyleSheet("border: 1px solid grey; background-color: white;");    
}  //non ho bisogno di copie profonde

void DrawArea::paintEvent(QPaintEvent *event){
    if(poligono){
        double larghezza=0, altezza=0, valNeg=0, scala=0, spostaA=0, spostaB=0, puntoMinX=0;

        QPainter painter(this);
        painter.setPen(QPen(Qt::black));
        painter.setBrush(QBrush(QColor(poligono->getColore()->getHex())));

        for(int i=0; i<poligono->getCoordinate().size(); ++i){
            if(larghezza<poligono->getCoordinate()[i].getX())
                larghezza=poligono->getCoordinate()[i].getX();
            if(altezza<poligono->getCoordinate()[i].getY())
                altezza=poligono->getCoordinate()[i].getY();
            if(poligono->getCoordinate()[i].getX()<0 && valNeg>poligono->getCoordinate()[i].getX())
                valNeg=poligono->getCoordinate()[i].getX();
        }
        larghezza-=valNeg;
        larghezza>altezza ? scala=(200/larghezza) : scala=(150/altezza);

        QPolygonF p = (poligono->zoom(scala).specchia()).toQPolygon();
        for(int i=0; i<poligono->zoom(scala).getLati().size(); ++i){   //calcolo il punto minimo di X
            if(poligono->zoom(scala).getCoordinate()[i].getX() < puntoMinX)
                puntoMinX = poligono->zoom(scala).getCoordinate()[i].getX();
        }
        spostaA = (((400-(larghezza*scala))/2)-(puntoMinX));
        spostaB = (250-(altezza*scala))/2;
        painter.translate(spostaA,spostaB+(altezza*scala));
        painter.drawPolygon(p);
    }
}

void DrawArea::settaPoligono(Poligono *pol){
    setPoligono(pol);
    repaint();
}
