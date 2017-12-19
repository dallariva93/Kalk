#ifndef TRIANGOLO_H
#define TRIANGOLO_H
#include "poligono.h"
#include "angolo.h"
#include "rgb.h"

class Triangolo : public Poligono{

public:
    Triangolo(double, double, const Angolo&, Colore* col=new RGB());
    Triangolo(double, const Angolo&, const Angolo&, Colore* col=new RGB());
    Triangolo(double, double, double, Colore* col=new RGB());
    double getAltezza() const;
    double getArea() const;
    void estendi(double);
    void ruotaInModoFurbo(double);
};

#endif // TRIANGOLO_H
