#include "rgb.h"
#include<iostream>
#include "triangolo.h"
#include "quadrilatero.h"
#define PI 3.14159265

int main(){
/*
    angolo p(90), q(45);
    triangolo t(10,p,q);
    std::cout<<t.getCoordinate()[2].getX()<<" "<<t.getCoordinate()[2].getY()<<std::endl;

    angolo p1(45), q1(45);
    triangolo o(10,p1,q1);
    std::cout<<o.getCoordinate()[2].getX()<<" "<<o.getCoordinate()[2].getY()<<std::endl;
*/

   // cout<<acos(0)*180/PI<<endl;
/*
 *     angolo p(44.415);
    triangolo t(10,7,p);
punto a(0,0), b(6.96362,0.712767);
    std::cout<<punto::distanceTo(a,b)<<"  lato ac"<<std::endl;
    std::cout<<t.getCoordinate()[2].getX()<<" "<<t.getCoordinate()[2].getY()<<std::endl;
*/
/*
    triangolo t(10, 15, angolo(5));
    QVector<double> lati= t.getLati();
    for(int i=0; i<lati.size(); i++){
        std::cout<<lati[i]<<std::endl;
    }

    std::cout<<t.getArea();
  */
    /*
    punto a(0,0), b(10,0), c(0,10);
    std::cout<<punto::angoloTraTrePunti(a,b,c).getAngolo();
*/
    quadrilatero q(10,10,10,10,angolo(),angolo(),angolo(),angolo());
    QVector<double> lati= q.getLati();
    for(int i=0; i<lati.size(); i++){
        std::cout<<lati[i]<<std::endl;
    }

}

