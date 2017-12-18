#ifndef TRIANGOLO_H
#define TRIANGOLO_H
#include "poligono.h"
#include "angolo.h"
#include "rgb.h"

class Triangolo : public Poligono{

public:
<<<<<<< HEAD
    triangolo(colore* col=new rgb());
    triangolo(double, double, const angolo&, colore* col=new rgb());
    triangolo(double, const angolo&, const angolo&, colore* col=new rgb());
    triangolo(double, double, double, colore* col=new rgb());
    double getAltezza() const;
    double getArea() const;
    void ruota();
=======
    Triangolo(double, double, const Angolo&, Colore* col=new RGB());
    Triangolo(double, const Angolo&, const Angolo&, Colore* col=new RGB());
    Triangolo(double, double, double, Colore* col=new RGB());
    double getAltezza() const;
    double getArea() const;
    void estendi(double);
    Triangolo ruota();
>>>>>>> 729ff05750d12a0e41dd3db226a0d3101a4c7802
};

#endif // TRIANGOLO_H
