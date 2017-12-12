#include "triangolo.h"
#include "angolo.h"
#include <math.h>


triangolo::triangolo(double latoA, double latoB, angolo c, colore* col) : poligono(3, "triangolo", std::vector<punto> v(), col) {
    std::vector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(latoA,0));
    double x=cos(c.getAngolo());
    double y=sin(c.getAngolo());
    punti.push_back(punto(x,y));
}

triangolo::triangolo(double latoA, angolo b, angolo c) : poligono(3, ) {
    std::vector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(latoA,0));
    double x=cos(b.getAngolo());
    double y=sin(b.getAngolo());
    punti.push_back(punto(x,y));



    //calcolo latoB, latoC e angolo a
    double val=b;
//   angolo a=180-b-c;
//    double latoB=( latoA * sin(b) ) / sin(a);
//    double latoC=( latoA * sin(c) ) / sin(a);
}

triangolo::triangolo(double latoA, double latoB, double latoC){

}
*/
double triangolo::getArea()const{

}
double triangolo::getPerimetro()const{

}

