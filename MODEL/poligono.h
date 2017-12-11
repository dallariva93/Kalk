#ifndef POLIGONO_H
#define POLIGONO_H
#include <QVector>
#include "punto.h"
#include "colore.h"

class poligono
{
private:
    unsigned int numeroLati;
    colore* color;
    std::string nomeOggetto;
    QVector<punto> coordinate;

public:
    poligono(unsigned int nLati, colore* col, std::string nome, QVector<punto> punti);
    virtual double getArea()=0;
    virtual double getPerimetro()=0;
    virtual colore* getColore();
};

#endif // POLIGONO_H
