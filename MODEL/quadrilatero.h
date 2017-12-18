#ifndef QUADRILATERO_H
#define QUADRILATERO_H
#include "poligono.h"
#include "angolo.h"
#include "rgb.h"

class quadrilatero : public poligono{
public:
    quadrilatero(double, colore* col=new rgb()); //quadrato
    quadrilatero(double, double, colore* col=new rgb()); //rettangolo
    quadrilatero(double, double, double, double, const angolo&, const angolo&, const angolo&, const angolo&, colore* col=new rgb()); //quadrato
    double getArea() const;
    void ruota();
};

#endif // QUADRILATERO_H
