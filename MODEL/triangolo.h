#ifndef TRIANGOLO_H
#define TRIANGOLO_H
#include "poligono.h"
#include "angolo.h"

class Triangolo : public Poligono{

public:
    Triangolo(double, double, const Angolo&, Colore* col=new RGB());
    Triangolo(double, const Angolo&, const Angolo&, Colore* col=new RGB());
    Triangolo(double, double, double, Colore* col=new RGB());
    double getAltezza() const;
    double getArea() const;
    void estendi(double);
    Triangolo& cambiaBase(int) const;
    Triangolo& specchia()const;
    double latoComune(const Poligono& p) const;
    Poligono& operator+(const Poligono&) const;
};

#endif // TRIANGOLO_H
