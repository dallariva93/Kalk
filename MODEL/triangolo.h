#ifndef TRIANGOLO_H
#define TRIANGOLO_H
#include "poligono.h"
#include "angolo.h"
#include "rgb.h"

class triangolo : public poligono{

public:
    triangolo(double, double, angolo, colore* col=new rgb());
    triangolo(double, angolo, angolo, colore* col=new rgb());
    triangolo(double, double, double, colore* col=new rgb());
    double getAltezza();
    double getArea();       //const perché da errore
};

#endif // TRIANGOLO_H
