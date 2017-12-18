#include "poligono.h"

poligono::poligono(unsigned int nLati, std::string nome, colore* col, QVector<punto> punti) : numeroLati(nLati), nomeOggetto(nome){
    color=col->clone();
    coordinate=punti;
}

colore* poligono::getColore() const{
    return color;
}

void poligono::setPunti(const QVector<punto> coord){
    coordinate=coord;
}

QVector<punto> poligono::getCoordinate() const{return coordinate;}

double poligono::getPerimetro() const{
    double perimetro=0;
    for(unsigned int i=0; i<numeroLati-1; ++i)
    {
        perimetro += punto::distanceTo(coordinate[i],coordinate[i+1]);
    }
   return perimetro += punto::distanceTo(coordinate.first(),coordinate.last());
}

QVector<double> poligono::getLati() const{
    QVector<double> lati;
    for(unsigned int i=0; i<numeroLati-1; ++i){
        lati.push_back(punto::distanceTo(coordinate[i], coordinate[i+1]));
    }
    lati.push_back(punto::distanceTo(coordinate.first(), coordinate.last()));
    return lati;
}

void poligono::ruota() {
//prova per poligono generico
    QVector<punto> q(numeroLati);
    q[0] = punto(0,0);
    q[1] = punto(getLati()[1], 0);

    QVector<double> angoli(numeroLati-2);
    if(numeroLati != 3)
    for(unsigned int i=3, j=0; i<numeroLati; ++i, j++){
        angolo b = punto::angoloTraTrePunti( getCoordinate()[i], getCoordinate()[1], getCoordinate()[2]);
        angoli[j] = b.getAngolo();
    }
    angoli[numeroLati-3] = punto::angoloTraTrePunti(getCoordinate()[0], getCoordinate()[1], getCoordinate()[2]).getAngolo();

    double x=0, y=0, lato=0;
    for(unsigned int i=3, j=0; i<numeroLati; ++i, ++j){
        x=0; y=0;
        lato = punto::distanceTo(getCoordinate()[1]/*B*/, getCoordinate()[i]);//lato Bx
        if(angoli[j] != 90){
            x = lato * cos(angoli[j] * PI/180);
            y = lato * sin(angoli[j] * PI/180);
        } else{ //se angolo==90
            x = 0;
            y = lato;
        }
        q[i-1]= punto(x,y);//punti da q[2]..a q[numeroLati]
    }
    lato = punto::distanceTo(getCoordinate()[0], getCoordinate()[1]);
    if(angoli[numeroLati-3] != 90){
        x = lato * cos(angoli[numeroLati-3] * PI/180);
        y = lato * sin(angoli[numeroLati-3] * PI/180);
    } else{ //se angolo==90
        x = 0;
        y = lato;
    }
    q[numeroLati-1] = punto(x,y);//punti da q[2]..a q[numeroLati]
    setPunti(q);
}
