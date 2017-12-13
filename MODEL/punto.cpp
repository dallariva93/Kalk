#include "punto.h"
#include "math.h"

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
