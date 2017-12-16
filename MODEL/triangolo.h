#ifndef TRIANGOLO_H
#define TRIANGOLO_H
#include "poligono.h"
#include "angolo.h"
#include "rgb.h"

class triangolo : public poligono{

public:
    triangolo(double, double, const angolo&, colore* col=new rgb());
    triangolo(double, const angolo&, const angolo&, colore* col=new rgb());
    triangolo(double, double, double, colore* col=new rgb());
    double getAltezza() const;
    double getArea() const;
    triangolo ruota();
};

#endif // TRIANGOLO_H
