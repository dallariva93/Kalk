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


#include<QApplication>
#include"../VIEW/colorcreator.h"
#include"../VIEW/drawarea.h"



int main(int argc, char* argv[]){
/*
    Triangolo t(10, 15, Angolo(5));
    Triangolo p(6.6666,10,12.018);

    Poligono& f = t +p;
    for(unsigned int i=0; i<f.getCoordinate().size();++i)
        std::cout<<"--("<<f.getCoordinate()[i].getX()<<" , "<<f.getCoordinate()[i].getY()<<")"<<std::endl;
        //--(0 , 0)--(0.000561578 , -6.6666)--(10 , 0)--(14.9429 , 1.30734)

    Quadrato q(10);
    Triangolo t(10,18.794,Angolo(120));

    Poligono& f=q+t;

    for(unsigned int i=0; i<f.getCoordinate().size();++i)
        std::cout<<"--("<<f.getCoordinate()[i].getX()<<" , "<<f.getCoordinate()[i].getY()<<")"<<std::endl;
        //--(0 , 0)--(-9.397 , -16.2761)--(10 , 0)--(10 , 10)--(-3.82857e-15 , 10)
*/


   /* Colore* colore=new RGB(0,0,0);
    Triangolo t(100,70, Angolo(120), colore);

    QApplication colorbox(argc,argv);
    DrawArea col(&t);
    col.show();
    return colorbox.exec();*/

    Angolo ret1(90), ret2(90);
    Triangolo p(10,15,ret1), t2(15,10,ret2);

    double a=p.getAngoli()[0].getAngolo()+p.getAngoli()[0].getAngolo();
    double z=179.9999999, x=180.0000001;
    if(z<a<x)
    std::cout<<p.getAngoli()[0].getAngolo()+p.getAngoli()[0].getAngolo();

}

