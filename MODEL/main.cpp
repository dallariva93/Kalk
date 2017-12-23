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

    Triangolo t(10, 15, Angolo(5));
    Triangolo p(6.6666,10,12.018);
/*
    p = p.cambiaBase(1);
    p = p.specchia();
    for(unsigned int i=0; i<t2.getLati().size(); ++i){
        std::cout<<"( "<<t2.getCoordinate()[i].getX()<<" , "<<t2.getCoordinate()[i].getY()<<")"<<std::endl;
//        std::cout<<"# "<<t2.getAngoli()[i].getAngolo()<<std::endl;
//        std::cout<<"* "<<t2.getLati()[i]<<std::endl;
    }*/

    /*Poligono& f =Triangolo::unisci(t,p);
    for(unsigned int i=0; i<f.getCoordinate().size();++i)
      std::cout<<"("<<f.getCoordinate()[i].getX()<<" , "<<f.getCoordinate()[i].getY()<<")"<<std::endl;
    */
    Poligono& f = t +p;
    for(unsigned int i=0; i<f.getCoordinate().size();++i)
      std::cout<<"--("<<f.getCoordinate()[i].getX()<<" , "<<f.getCoordinate()[i].getY()<<")"<<std::endl;

}

