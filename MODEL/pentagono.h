#ifndef PENTAGONO_H
#define PENTAGONO_H
#include "poligono.h"
#include "angolo.h"
#include "rgb.h"

class Pentagono : public Poligono{

public:
    Pentagono();
    Pentagono(double, double, double, double, double, const Angolo&, const Angolo&, const Angolo&,
              const Angolo&, const Angolo&, Colore* col=new RGB() );
    double getArea() const;
    virtual void estendi(double);
    Pentagono &cambiaBase(int)const;
    Pentagono& specchia()const;
    static Poligono& unisci(const Pentagono&, const Poligono&);
    Poligono& operator+(const Poligono&) const;
};

#endif // PENTAGONO_H
