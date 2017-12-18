#ifndef POLIGONO_H
#define POLIGONO_H
#include <QVector>
#include "punto.h"
#include "colore.h"
#include "rgb.h"

class Poligono{
private:
    unsigned int numeroLati;
    Colore* color;
    std::string nomeOggetto;
    QVector<Punto> coordinate;

public:
    Poligono(unsigned int, std::string, Colore*, QVector<Punto> punti=QVector<Punto>());
    virtual double getArea() const =0;
    virtual double getPerimetro() const;
    virtual void estendi(double)=0;       //meglio farla pura? da pensarci
    virtual Colore* getColore() const;
    void setPunti(const QVector<Punto>);
    QVector<Punto> getCoordinate() const;
    QVector<double> getLati() const;

};

#endif // POLIGONO_H
