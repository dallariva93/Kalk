#include "pentagono.h"
#include "triangolo.h"
#include <math.h>

Pentagono::Pentagono(double latoAB, double latoBC, double latoCD, double latoDE, double latoAE, const Angolo& a, const Angolo& b,
                     const Angolo& c, const Angolo& d, const Angolo& e, Colore* col) : Poligono(5,"pentagono",col){
    double x, y;
    QVector<Punto> punti;
    punti.push_back(Punto::origine);    //coordinata A
    punti.push_back(Punto(0,latoAB));   //coordinata B

    Triangolo t1(latoAB, latoBC, b);
    punti.push_back(t1.getCoordinate()[2]);    //coordinata C

    Triangolo t2(latoAE, latoAB, a);
    double latoAD = Punto::distanceTo(t2.getCoordinate()[1], t2.getCoordinate()[2]);
    Angolo alfa = Punto::angoloTraTrePunti(t2.getCoordinate()[0], t2.getCoordinate()[1], t2.getCoordinate()[2]);
    Angolo beta = 180 - alfa.getAngolo();
    if(beta!=90){
        x = latoAD * cos(beta.getAngolo() * PI/180);
        y = latoAD * sin(beta.getAngolo() * PI/180);
    } else {
        x = 0; y = latoAD;
    }
    punti.push_back(Punto(x,y));    //coordinata D

    punti.push_back(t2.getCoordinate()[2]);    //coordinata E

    setPunti(punti);
}
double Pentagono::getArea() const{}


