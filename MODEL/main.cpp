#include "rgb.h"
#include<iostream>
#include "triangolo.h"
#include "quadrato.h"
#define PI 3.14159265

int main(){
/*
    angolo p(90), q(45);
    triangolo t(10,p,q);
    std::cout<<t.getCoordinate()[2].getX()<<" "<<t.getCoordinate()[2].getY()<<std::endl;
*//*
    angolo p(44.415);
    triangolo t(10,7,p);
punto a(0,0), b(6.96362,0.712767);
    std::cout<<punto::distanceTo(a,b)<<"  lato ac"<<std::endl;
    std::cout<<t.getCoordinate()[2].getX()<<" "<<t.getCoordinate()[2].getY()<<std::endl;
*//*
    triangolo t(10, 15, angolo(5));
    QVector<double> lati= t.getLati();
    for(int i=0; i<lati.size(); i++){
        std::cout<<lati[i]<<std::endl;
    }
  std::cout<<t.getArea();
*//*
    punto a(0,0), b(10,0), c(0,10);
    std::cout<<punto::angoloTraTrePunti(a,b,c).getAngolo();
*//*
    quadrilatero q(10,5.831,10,5.831,angolo(120.964),angolo(59.036),angolo(120.964),angolo(59.036));
    QVector<punto> lati= q.getCoordinate();
    for(int i=0; i<4; i++){
        std::cout<<lati[i].getX()<<"  -  "<<lati[i].getY()<<std::endl;
    }
*/
/*triangolo ruota!!
    triangolo t(10, 5.113, 15);

    QVector<double> latii= t.getLati();
    for(int i=0; i<latii.size(); i++){
        std::cout<<latii[i]<<std::endl;
    }

    t.ruota();

    QVector<double> lati= t.getLati();
    for(int i=0; i<lati.size(); i++){
        std::cout<<lati[i]<<std::endl;
    }

    t.ruota();

    QVector<double> lato= t.getLati();
    for(int i=0; i<lato.size(); i++){
        std::cout<<lato[i]<<std::endl;
    }
*/

    quadrilatero q(10,5,10,5,angolo(90),angolo(90),angolo(90),angolo(90));
    QVector<double> lati= q.getLati();
    for(int i=0; i<4; i++){
        std::cout<<"-- "<<lati[i]<<std::endl;
    }
    QVector<punto> latio= q.getCoordinate();
    for(int i=0; i<4; i++){
        std::cout<<latio[i].getX()<<"  -  "<<latio[i].getY()<<std::endl;
    }
    q.ruota();
    QVector<double> latii= q.getLati();
    for(int i=0; i<4; i++){
        std::cout<<"----- "<<latii[i]<<std::endl;
    }
    QVector<punto> lti= q.getCoordinate();
    for(int i=0; i<4; i++){
        std::cout<<lti[i].getX()<<"  -  "<<lti[i].getY()<<std::endl;
    }
}

