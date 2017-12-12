#ifndef POLIGONO_H
#define POLIGONO_H
#include <QVector>
#include "punto.h"
#include "colore.h"

class poligono{
private:
    unsigned int numeroLati;
    colore* color;
    std::string nomeOggetto;
    QVector<punto> coordinate;

public:
    poligono(unsigned int, colore*, std::string, QVector<punto>);
    virtual double getArea()const=0;
    virtual double getPerimetro()const=0;
    virtual colore* getColore()const;
};

#endif // POLIGONO_H
