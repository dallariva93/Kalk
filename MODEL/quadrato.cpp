#include "quadrato.h"

quadrato::quadrato(double lato, colore* col):quadrilatero(lato,lato,lato,lato,angolo(90), angolo(90), angolo(90), angolo(90), col){}

double quadrato::getArea()const{
    return pow(punto::distanceTo(punto::origine,getCoordinate()[1]),2);
}

double quadrato::getPerimetro()const{
    return 4*punto::distanceTo(punto::origine,getCoordinate()[1]);
}

void quadrato::estendi(double fattore)
{
    quadrato temp(getLati().first()*fattore);
    setPunti(temp.getCoordinate());
}
