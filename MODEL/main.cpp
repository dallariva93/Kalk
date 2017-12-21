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
<<<<<<< HEAD
=======
    Triangolo t(10,10,10);
    for(int i=0; i<3; i++)
    {
        std::cout<<t.getCoordinate()[i].getX()<<" "<<t.getCoordinate()[i].getY()<<std::endl;
    }
    t.ruota(Angolo(45));
    for(int i=0; i<3; i++)
    {
        std::cout<<t.getCoordinate()[i].getX()<<" "<<t.getCoordinate()[i].getY()<<std::endl;
    }
    std::cout<<Punto::angoloTraTrePunti(Punto(10,0),Punto::origine,t.getCoordinate()[1]).getAngolo();


>>>>>>> 955c0f26519897a19cc642733f850c75394e0331

}

