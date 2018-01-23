#ifndef TRIANGOLO_H
#define TRIANGOLO_H
#include "poligono.h"
#include "angolo.h"

class Triangolo : public Poligono{

public:
    Triangolo();
    Triangolo(double, double, const Angolo&, Colore* col=new RGB(), QString nome="triangolo");
    Triangolo(double, const Angolo&, const Angolo&, Colore* col=new RGB(), QString nome="triangolo");
    Triangolo(double, double, double, Colore* col=new RGB(), QString nome="triangolo");

    double getAltezza() const;
    double getArea() const;
    void estendi(double);
    Triangolo& zoom(double) const;
    Triangolo& cambiaBase(int) const;
    Triangolo& specchia()const;
    Poligono& unisci(const Poligono&) const;
    Poligono& operator+(const Poligono&) const;
};

#endif // TRIANGOLO_H
