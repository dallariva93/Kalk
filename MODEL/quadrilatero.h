#ifndef QUADRILATERO_H
#define QUADRILATERO_H
#include "poligono.h"
#include "angolo.h"
#include "rgb.h"

class Quadrilatero : public Poligono{

public:
    Quadrilatero();
    Quadrilatero(double, double, double, double, const Angolo&, const Angolo&, const Angolo&, const Angolo&, Colore* col=new RGB()); //quadrato
    double getArea() const;
    void ruota();
    virtual void estendi(double);
    Quadrilatero &cambiaBase(int)const;
    Quadrilatero& specchia()const;
    static Poligono& unisci(const Quadrilatero&, const Poligono&);
    Poligono& operator+(const Poligono&) const;
};

#endif // QUADRILATERO_H
