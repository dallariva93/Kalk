#ifndef QUADRILATERO_H
#define QUADRILATERO_H
#include "poligono.h"
#include "angolo.h"
#include "rgb.h"

class Quadrilatero : public Poligono{
public:
    Quadrilatero(double, Colore* col=new RGB()); //quadrato
    Quadrilatero(double, double, Colore* col=new RGB()); //rettangolo
    Quadrilatero(double, double, double, double, const Angolo&, const Angolo&, const Angolo&, const Angolo&, Colore* col=new RGB()); //quadrato
    double getArea() const;
};

#endif // QUADRILATERO_H
