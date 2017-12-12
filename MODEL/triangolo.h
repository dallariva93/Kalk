#ifndef TRIANGOLO_H
#define TRIANGOLO_H
#include "poligono.h"
#include "angolo.h"

class triangolo : public poligono{

public:
    triangolo(double, double, angolo);  //valutare se sensato inizializzarli con valore di default
//    triangolo(double, angolo, angolo);
//    triangolo(double, double, double);
    double Area()const;
    double Perimetro()const;

};

#endif // TRIANGOLO_H
