#ifndef QUADRILATERO_H
#define QUADRILATERO_H
#include "poligono.h"
#include "angolo.h"
#include "rgb.h"

class Quadrilatero : public Poligono{

public:
    Quadrilatero(double, double, double, double, const Angolo&, const Angolo&, const Angolo&, const Angolo&, Colore* col=new RGB()); //quadrato
    double getArea() const;
    void ruota();
    virtual void estendi(double);
    Quadrilatero &cambiaBase(int)const;
    Poligono& operator+(const Poligono&) const;
    Quadrilatero& specchia()const;

};

#endif // QUADRILATERO_H
