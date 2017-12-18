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
