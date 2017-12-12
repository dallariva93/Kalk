#ifndef POLIGONO_H
#define POLIGONO_H
#include <QVector>
#include "punto.h"
#include "colore.h"
#include "rgb.h"

class poligono{
private:
    unsigned int numeroLati;
    colore* color;
    std::string nomeOggetto;
    QVector<punto> coordinate;

public:
    poligono(unsigned int, std::string, colore*, QVector<punto> punti=QVector<punto>());
    virtual double getArea()const=0;
    virtual double getPerimetro()const=0;
    virtual colore* getColore()const;
    void setPunti(const QVector<punto>);
    QVector<punto> getCoordinate();
};

#endif // POLIGONO_H
