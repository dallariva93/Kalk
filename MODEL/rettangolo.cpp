#include "rettangolo.h"

Rettangolo::Rettangolo(double latoMaggiore, double latoMinore, Colore* col):
    Quadrilatero(latoMaggiore, latoMinore, latoMaggiore,latoMinore, Angolo::angoloRetto, Angolo::angoloRetto, Angolo::angoloRetto, Angolo::angoloRetto, col){}

double Rettangolo::getArea()const{
    return Punto::distanceTo(Punto::origine,getCoordinate()[1]) *
           Punto::distanceTo(getCoordinate()[1],getCoordinate()[2]);
}

double Rettangolo::getPerimetro()const{
    return 2 * (Punto::distanceTo(Punto::origine,getCoordinate()[1]) +
                Punto::distanceTo(getCoordinate()[1],getCoordinate()[2]));
}


void Rettangolo::ruotaSuUnLato(double lato)
{
    Quadrilatero::ruotaSuUnLato(lato);
}
