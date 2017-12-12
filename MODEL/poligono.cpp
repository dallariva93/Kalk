#include "poligono.h"

poligono::poligono(unsigned int nLati, colore* col, std::string nome, QVector<punto> punti) : numeroLati(nLati), nomeOggetto(nome){
    color=col->clone();
    coordinate=punti;
}

colore* poligono::getColore()const{
    return color;
}
