#include"punto.h"
#include "poligono.h"

Poligono::Poligono(unsigned int nLati, std::string nome, Colore* col, QVector<Punto> punti) : numeroLati(nLati), nomeOggetto(nome){
    color=col->clone();
    coordinate=punti;
}

Colore* Poligono::getColore() const{
    return color;
}

void Poligono::setPunti(const QVector<Punto> coord){
    coordinate=coord;
}

QVector<Punto> Poligono::getCoordinate() const{return coordinate;}

double Poligono::getPerimetro() const{
    double perimetro=0;
    for(unsigned int i=0; i<numeroLati-1; ++i)
    {
        perimetro += Punto::distanceTo(coordinate[i],coordinate[i+1]);
    }
   return perimetro += Punto::distanceTo(coordinate.first(),coordinate.last());
}

QVector<double> Poligono::getLati() const{
    QVector<double> lati;
    for(unsigned int i=0; i<numeroLati-1; ++i){
        lati.push_back(Punto::distanceTo(coordinate[i], coordinate[i+1]));
    }
    lati.push_back(Punto::distanceTo(coordinate.first(), coordinate.last()));
    return lati;
}

void Poligono::ruota() {
//prova per poligono generico
    QVector<Punto> q(numeroLati);
    q[0] = Punto(0,0);
    q[1] = Punto(getLati()[1], 0);

    QVector<double> angoli(numeroLati-2);
    if(numeroLati != 3)
    for(unsigned int i=3, j=0; i<numeroLati; ++i, j++){
        Angolo b = Punto::angoloTraTrePunti( getCoordinate()[i], getCoordinate()[1], getCoordinate()[2]);
        angoli[j] = b.getAngolo();
    }
    angoli[numeroLati-3] = Punto::angoloTraTrePunti(getCoordinate()[0], getCoordinate()[1], getCoordinate()[2]).getAngolo();

    double x=0, y=0, lato=0;
    for(unsigned int i=3, j=0; i<numeroLati; ++i, ++j){
        x=0; y=0;
        lato = Punto::distanceTo(getCoordinate()[1]/*B*/, getCoordinate()[i]);//lato Bx
        if(angoli[j] != 90){
            x = lato * cos(angoli[j] * PI/180);
            y = lato * sin(angoli[j] * PI/180);
        } else{ //se angolo==90
            x = 0;
            y = lato;
        }
        q[i-1]= Punto(x,y);//punti da q[2]..a q[numeroLati]
    }
    lato = Punto::distanceTo(getCoordinate()[0], getCoordinate()[1]);
    if(angoli[numeroLati-3] != 90){
        x = lato * cos(angoli[numeroLati-3] * PI/180);
        y = lato * sin(angoli[numeroLati-3] * PI/180);
    } else{ //se angolo==90
        x = 0;
        y = lato;
    }
    q[numeroLati-1] = Punto(x,y);//punti da q[2]..a q[numeroLati]
    setPunti(q);

}
