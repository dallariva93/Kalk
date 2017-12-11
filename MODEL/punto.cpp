#include "punto.h"
#include "math.h"

punto::punto():x(0),y(0){}
punto::punto(int xx, int yy):x(xx),y(yy){}
int punto::getX()const{return x;}
int punto::getY()const{return y;}
double distanceTo(const punto& primo, const punto& secondo)
{return sqrt(
                pow((secondo.getX()-primo.getX()),2)+
                pow((secondo.getY()-primo.getY()),2)
            );
}
