#include "quadrilatero.h"
#include "triangolo.h"

/*  CONTROLLI DA FARE:
 * -    somma degli angoli = 360
*/

quadrilatero::quadrilatero(double lato, colore* col) : poligono(4, "quadrato", col) {
    QVector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(lato,0));
    punti.push_back(punto(lato,lato));
    punti.push_back(punto(0,lato));
    setPunti(punti);
}

quadrilatero::quadrilatero(double latoA, double latoB, colore* col) : poligono(4, "quadrato", col){
    QVector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(latoA,0));
    punti.push_back(punto(latoA,latoB));
    punti.push_back(punto(0,latoB));
    setPunti(punti);
}
/*
quadrilatero::quadrilatero(double latoA, double latoB, double latoC, double latoD, angolo a, angolo b, angolo c, colore* col){

}
*/
double quadrilatero::getArea(){
    triangolo t1(getLati()[0], getLati()[1],punto::distanceTo(getCoordinate()[0],getCoordinate()[2]));
    triangolo t2(punto::distanceTo(getCoordinate()[0],getCoordinate()[2]), getLati()[2], getLati()[3]);
    return t1.getArea()+t2.getArea();
}

