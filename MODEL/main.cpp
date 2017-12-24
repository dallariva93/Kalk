#include "rgb.h"
#include <iostream>
#include "triangolo.h"
#include "quadrato.h"
#include "angolo.h"
#include "rettangolo.h"
#include "pentagono.h"
#include "quadrilatero.h"
#include "pentagonoregolare.h"
#define PI 3.14159265

int main(){
/*
    Triangolo t(10, 15, Angolo(5));
    Triangolo p(6.6666,10,12.018);

    Poligono& f = t +p;
    for(unsigned int i=0; i<f.getCoordinate().size();++i)
      std::cout<<"--("<<f.getCoordinate()[i].getX()<<" , "<<f.getCoordinate()[i].getY()<<")"<<std::endl;
*/

    Quadrato q(10);
    Triangolo t(10,18.794,Angolo(120));

    Poligono& f=q+t;

    for(unsigned int i=0; i<f.getCoordinate().size();++i)
      std::cout<<"--("<<f.getCoordinate()[i].getX()<<" , "<<f.getCoordinate()[i].getY()<<")"<<std::endl;

}

