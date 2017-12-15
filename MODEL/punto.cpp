#include "punto.h"
#include <cmath>


punto::punto():x(0),y(0){}

punto::punto(double xx, double yy):x(xx),y(yy){}

double punto::getX()const{return x;}

double punto::getY()const{return y;}

double punto::distanceTo(const punto& primo, const punto& secondo){
    return sqrt(
                pow((secondo.getX()-primo.getX()),2)+
                pow((secondo.getY()-primo.getY()),2)
            );
}

angolo punto::angoloTraTrePunti(const punto& A, const punto& B, const punto& C){
    double latoAB = distanceTo(A,B);
    double latoBC = distanceTo(B,C);
    double latoAC = distanceTo(A,C);
    double cos_a =(( pow(latoAC,2) + pow(latoAB,2) - pow(latoBC,2)) / (2*latoAB*latoAC)) ;
    return angolo( acos(cos_a)*180/PI );
}
