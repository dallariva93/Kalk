#include "quadrato.h"

Quadrato::Quadrato(double lato, Colore* col):Quadrilatero(lato,lato,lato,lato,Angolo(90), Angolo(90), Angolo(90), Angolo(90), col){}

double Quadrato::getArea()const{
    return pow(Punto::distanceTo(Punto::origine,getCoordinate()[1]),2);
}

double Quadrato::getPerimetro()const{
    return 4*Punto::distanceTo(Punto::origine,getCoordinate()[1]);
}

void Quadrato::estendi(double fattore)
{
    Quadrato temp(getLati().first()*fattore);
    setPunti(temp.getCoordinate());
}
