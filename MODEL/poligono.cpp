#include "poligono.h"

poligono::poligono(unsigned int nLati, std::string nome, colore* col, QVector<punto> punti) : numeroLati(nLati), nomeOggetto(nome){
    color=col->clone();
    coordinate=punti;
}

colore* poligono::getColore()const{
    return color;
}

void poligono::setPunti(const QVector<punto> coord){
    coordinate=coord;
}

QVector<punto> poligono::getCoordinate(){return coordinate;}
