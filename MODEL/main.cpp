#include "rgb.h"
#include<iostream>
#include "triangolo.h"
#include "quadrato.h"
#include "angolo.h"
#include "rettangolo.h"
#include "pentagono.h"
#include "quadrilatero.h"
#include "pentagonoregolare.h"
#define PI 3.14159265

int main(){
    Triangolo t(10,10,10);
    for(int i=0; i<3; i++)
    {
        std::cout<<t.getCoordinate()[i].getX()<<" "<<t.getCoordinate()[i].getY()<<std::endl;
    }
    t.ruota(Angolo(1));
    for(int i=0; i<3; i++)
    {
        std::cout<<t.getCoordinate()[i].getX()<<" "<<t.getCoordinate()[i].getY()<<std::endl;
    }
    std::cout<<Punto::angoloTraTrePunti(t.getCoordinate()[1],Punto::origine,Punto(10,0)).getAngolo();
}

