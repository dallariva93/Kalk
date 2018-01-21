#ifndef PENTAGONO_H
#define PENTAGONO_H
#include "poligono.h"
#include "angolo.h"
#include "rgb.h"

class Pentagono : public Poligono{
private:
    static const Angolo angoloInterno;
public:
    Pentagono();
    Pentagono(double, double, double, double, double, const Angolo&, const Angolo&, const Angolo&,
              const Angolo&, const Angolo&, Colore* col=new RGB(), QString nome="Pentagono" );
    Pentagono(double, Colore* col=new RGB(), QString nome="Pentagono");
    double getArea() const;
    virtual void estendi(double);
    Pentagono& zoom(double) const;
    Pentagono &cambiaBase(int)const;
    Pentagono& specchia()const;
    Poligono& unisci(const Poligono&) const;
    Poligono& operator+(const Poligono&) const;
};

#endif // PENTAGONO_H
