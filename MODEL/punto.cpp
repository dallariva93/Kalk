#include "punto.h"
#include <cmath>

Punto::Punto():x(0),y(0){}

Punto::Punto(double xx, double yy):x(xx),y(yy){}

const Punto Punto::origine=Punto();

double Punto::getX()const{return x;}

double Punto::getY()const{return y;}

double Punto::distanceTo(const Punto& primo, const Punto& secondo){
    return sqrt(
                pow((secondo.getX()-primo.getX()),2)+
                pow((secondo.getY()-primo.getY()),2)
            );
}

Angolo Punto::angoloTraTrePunti(const Punto& A, const Punto& B, const Punto& C){
    double latoAB = distanceTo(A,B);
    double latoBC = distanceTo(B,C);
    double latoAC = distanceTo(A,C);
    double cos_a =(( pow(latoAC,2) + pow(latoAB,2) - pow(latoBC,2)) / (2*latoAB*latoAC)) ;
    return Angolo( acos(cos_a) *180/PI );
}

