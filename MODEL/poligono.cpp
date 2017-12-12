#include "poligono.h"

poligono::poligono(unsigned int nLati, std::string nome, QVector<punto> punti, colore* col) : numeroLati(nLati), nomeOggetto(nome){
    color=col->clone();
    coordinate=punti;
}

colore* poligono::getColore()const{
    return color;
}
