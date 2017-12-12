#include "triangolo.h"
#include "angolo.h"
#include <math.h>


triangolo::triangolo(double latoA, double latoB, angolo c, colore* col) : poligono(3, "triangolo", col) {
    QVector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(latoA,0));
    double x = latoB * cos(c.getAngolo());
    double y = latoB * sin(c.getAngolo());
    punti.push_back(punto(x,y));
    setPunti(punti);
}

triangolo::triangolo(double latoA, angolo b, angolo c, colore* col) : poligono(3, "triangolo", col) {
    angolo a = 180-b.getAngolo()-c.getAngolo();
    double latoC = (latoA * sin(b.getAngolo())) / sin(a.getAngolo());
    QVector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(latoA,0));
    double x= latoC * cos(b.getAngolo());
    double y= latoC * sin(b.getAngolo());
    punti.push_back(punto(x,y));
    setPunti(punti);
//   angolo a=180-b-c;
//    double latoB=( latoA * sin(b) ) / sin(a);
//    double latoC=( latoA * sin(c) ) / sin(a);
}

triangolo::triangolo(double latoA, double latoB, double latoC, colore* col){
    double cos_a = ( pow(latoA,2) + pow(latoB,2) + pow(latoC,2) ) / 2*latoB*latoC ;

}
/*
double triangolo::getArea()const{

}*/
double triangolo::getPerimetro(){
    QVector<punto> coord=this->getCoordinate();
    return  punto::distanceTo(coord[0],coord[1])+
            punto::distanceTo(coord[1],coord[2])+
            punto::distanceTo(coord[0],coord[2]);
}


