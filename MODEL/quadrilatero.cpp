#include "quadrilatero.h"
#include "triangolo.h"
#include "angolo.h"

/*  CONTROLLI DA FARE:
 * -    somma degli angoli = 360
*/

Quadrilatero::Quadrilatero(double lato, Colore* col) : Poligono(4, "quadrato", col) {
    QVector<Punto> punti;
    punti.push_back(Punto(0,0));
    punti.push_back(Punto(lato,0));
    punti.push_back(Punto(lato,lato));
    punti.push_back(Punto(0,lato));
    setPunti(punti);
}

Quadrilatero::Quadrilatero(double latoAB, double latoBC, Colore* col) : Poligono(4, "quadrato", col){
    QVector<Punto> punti;
    punti.push_back(Punto(0,0));
    punti.push_back(Punto(latoAB,0));
    punti.push_back(Punto(latoAB,latoBC));
    punti.push_back(Punto(0,latoBC));
    setPunti(punti);
}

Quadrilatero::Quadrilatero(double latoAB, double latoBC, double latoCD, double latoAD, const Angolo& a, const Angolo& b, const Angolo& c, const Angolo& d, Colore* col) : Poligono(4, "quadrato", col){
//   ANCORADA VERIFICARE!!
    //if(a+b+c+d>angolo(360))break;       //mettere eccezione
    double cx, cy, dx, dy;
    Angolo b_ad = 180 - b.getAngolo();
    QVector<Punto> punti;
    punti.push_back(Punto(0,0));
    punti.push_back(Punto(latoAB,0));
    if(b.getAngolo() != 90){
        cx = latoAB + ( latoBC * cos( b_ad.getAngolo() *PI/180));
        cy = latoBC * sin( b_ad.getAngolo() *PI/180);
    } else{
        cx = latoAB;
        cy = latoBC;
    }
    punti.push_back(Punto(cx,cy));
    if(a.getAngolo() != 90){
        dx = latoAD * cos( a.getAngolo() *PI/180);
        dy = latoAD * sin( a.getAngolo() *PI/180);
    } else {
        dx = 0;
        dy = latoAD;
    }
    punti.push_back(Punto(dx,dy));
    setPunti(punti);
}

/*
quadrilatero::quadrilatero(double latoA, double latoB, double latoC, double latoD, angolo a, angolo b, angolo c, colore* col){

}
*/
double Quadrilatero::getArea() const{
    Triangolo t1(getLati()[0], getLati()[1],Punto::distanceTo(getCoordinate()[0],getCoordinate()[2]));
    Triangolo t2(Punto::distanceTo(getCoordinate()[0],getCoordinate()[2]), getLati()[2], getLati()[3]);
    return t1.getArea()+t2.getArea();
}

