#ifndef PENTAGONO_H
#define PENTAGONO_H
#include "poligono.h"
#include "angolo.h"

class Pentagono : public Poligono{
public:
    Pentagono(double, double, double, double, double, const Angolo&, const Angolo&, const Angolo&, const Angolo&, const Angolo&, Colore* col=new RGB());
    double getArea() const;
};

#endif // PENTAGONO_H
