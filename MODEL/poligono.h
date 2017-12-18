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
    virtual double getArea() const =0;
    virtual double getPerimetro() const;
    virtual void estendi(double)=0;       //meglio farla pura? da pensarci
    virtual colore* getColore() const;
    void setPunti(const QVector<punto>);
    QVector<punto> getCoordinate() const;
    QVector<double> getLati() const;

<<<<<<< HEAD
    void ruota();

=======
>>>>>>> 729ff05750d12a0e41dd3db226a0d3101a4c7802
};

#endif // POLIGONO_H
