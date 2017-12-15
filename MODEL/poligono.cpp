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
