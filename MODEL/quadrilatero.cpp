#include "quadrilatero.h"
#include "triangolo.h"
#include "angolo.h"

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

quadrilatero::quadrilatero(double latoAB, double latoBC, colore* col) : poligono(4, "quadrato", col){
    QVector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(latoAB,0));
    punti.push_back(punto(latoAB,latoBC));
    punti.push_back(punto(0,latoBC));
    setPunti(punti);
}

quadrilatero::quadrilatero(double latoAB, double latoBC, double latoCD, double latoAD, const angolo& a, const angolo& b, const angolo& c, const angolo& d, colore* col) : poligono(4, "quadrato", col){
//   ANCORADA VERIFICARE!!
    //if(a+b+c+d>angolo(360))break;       //mettere eccezione
    double cx, cy, dx, dy;
    angolo b_ad = 180 - b.getAngolo();
    QVector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(latoAB,0));

    if(b.getAngolo() != 90){
        cx = latoAB + ( latoBC * cos( b_ad.getAngolo() *PI/180));
        cy = latoBC * sin( b_ad.getAngolo() *PI/180);
    } else{
        cx = latoAB;
        cy = latoBC;
    }
    punti.push_back(punto(cx,cy));

    if(a.getAngolo() != 90){
        dx = latoAD * cos( a.getAngolo() *PI/180);
        dy = latoAD * sin( a.getAngolo() *PI/180);
    } else {
        dx = 0;
        dy = latoAD;
    }
    punti.push_back(punto(dx,dy));

    setPunti(punti);
}

/*
quadrilatero::quadrilatero(double latoA, double latoB, double latoC, double latoD, angolo a, angolo b, angolo c, colore* col){

}
*/
double quadrilatero::getArea() const{
    triangolo t1(getLati()[0], getLati()[1],punto::distanceTo(getCoordinate()[0],getCoordinate()[2]));
    triangolo t2(punto::distanceTo(getCoordinate()[0],getCoordinate()[2]), getLati()[2], getLati()[3]);
    return t1.getArea()+t2.getArea();
}

