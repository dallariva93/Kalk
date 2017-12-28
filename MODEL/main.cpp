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
    /*
    QApplication colorbox(argc,argv);
    ColorCreator col;
    col.show();
    return colorbox.exec();
    *//*
    Colore* colore=new RGB(0,0,0);
    Triangolo t(100,70, Angolo(80), colore);
    Quadrato q(100);

    QApplication colorbox(argc,argv);
    DrawArea col(&(t+q));
    col.show();
    return colorbox.exec();
*/
}

