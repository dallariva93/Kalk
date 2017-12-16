#include "rettangolo.h"

rettangolo::rettangolo(double latoMinore, double latoMaggiore, colore* col):
    quadrilatero(latoMaggiore, latoMinore, latoMaggiore,latoMinore, angolo::angoloRetto, angolo::angoloRetto, angolo::angoloRetto, angolo::angoloRetto, col){}

double rettangolo::getArea()const{
    return punto::distanceTo(punto::origine,getCoordinate()[1]) *
           punto::distanceTo(getCoordinate()[1],getCoordinate()[2]);
}

double rettangolo::getPerimetro()const{
    return 2 * (punto::distanceTo(punto::origine,getCoordinate()[1]) +
                punto::distanceTo(getCoordinate()[1],getCoordinate()[2]));
}
