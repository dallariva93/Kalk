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
/*
    Quadrilatero p(10,10,10,10,Angolo(90),Angolo(90),Angolo(90),Angolo(90));
    for(unsigned int i=0; i<p.getCoordinate().size(); ++i){
        std::cout<<"( "<<p.getCoordinate()[i].getX()<<" , "<<p.getCoordinate()[i].getY()<<" )"<<std::endl;
    }
    Triangolo p(10,12.018,6.66665);
    for(unsigned int i=0; i<p.getCoordinate().size(); ++i){
        std::cout<<"( "<<p.getCoordinate()[i].getX()<<" , "<<p.getCoordinate()[i].getY()<<" )"<<std::endl;
    }
*/

    Pentagono p(10,6,6.346,15,3,Angolo(150),Angolo(110),Angolo(130.131),Angolo(79.886),Angolo(70));
    for(unsigned int i=0; i<p.getCoordinate().size(); ++i){
        std::cout<<"( "<<p.getCoordinate()[i].getX()<<" , "<<p.getCoordinate()[i].getY()<<" )"<<std::endl;
    }


}

