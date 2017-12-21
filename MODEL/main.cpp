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
/*    Triangolo t(10,6.666,Angolo(90));
    for(unsigned int i=0; i<t.getCoordinate().size(); ++i){
        std::cout<<"( "<<t.getCoordinate()[i].getX()<<" , "<<t.getCoordinate()[i].getY()<<" )"<<std::endl;
    }
    Triangolo p = t.specchia();
    for(unsigned int i=0; i<p.getCoordinate().size(); ++i){
        std::cout<<"( "<<p.getCoordinate()[i].getX()<<" , "<<p.getCoordinate()[i].getY()<<" )"<<std::endl;
    }
    */
    Triangolo t(10,15,Angolo(5));
    Triangolo p = t.cambiaBase(2);
    for(unsigned int i=0; i<t.getCoordinate().size(); ++i){
        std::cout<<"( "<<t.getCoordinate()[i].getX()<<" , "<<t.getCoordinate()[i].getY()<<" )"<<std::endl;
    }
    for(unsigned int i=0; i<p.getCoordinate().size(); ++i){
        std::cout<<"( "<<p.getCoordinate()[i].getX()<<" , "<<p.getCoordinate()[i].getY()<<" )"<<std::endl;
    }
}

