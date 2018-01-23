#ifndef QUADRILATERO_H
#define QUADRILATERO_H
#include "poligono.h"
#include "angolo.h"
#include "rgb.h"

class Quadrilatero : public Poligono{

public:
    Quadrilatero();
    Quadrilatero(double, double, double, double, const Angolo&, const Angolo&, const Angolo&, const Angolo&, Colore* col=new RGB(), QString nome="quadrilatero"); //quadrato
    double getArea() const;
    void ruota();
    virtual void estendi(double);
    Quadrilatero& zoom(double) const;
    Quadrilatero &cambiaBase(int)const;
    Quadrilatero& specchia()const;
    Poligono& unisci(const Poligono&) const;
    Poligono& operator+(const Poligono&) const;
};

#endif // QUADRILATERO_H
