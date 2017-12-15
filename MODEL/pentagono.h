#ifndef PENTAGONO_H
#define PENTAGONO_H
#include "poligono.h"
#include "angolo.h"

class pentagono : public poligono{
public:
    pentagono(double, colore* col=new rgb());
/*
    pentagono(double, double, double, double, double, const angolo&, const angolo&, const angolo&, const angolo&, colore* col=new rgb());
    pentagono(double, double, double, double, double, colore* col=new rgb());
    pentagono(double, double, double, double, const angolo&, const angolo&, const angolo&, colore* col=new rgb());
*/
        double getArea() const;
};

#endif // PENTAGONO_H
