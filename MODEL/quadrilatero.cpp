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

void quadrilatero::ruota() {
//prova per poligono generico
    //SISTEMARE ANGOLI RETTI DI MERDA!!!!!
    QVector<punto> q(4);
    q[0] = punto(0,0);
    q[1] = punto(getLati()[1], 0);

    QVector<angolo> angoli(4-2);
    if(4 != 3)
    for(unsigned int i=3, j=0; i<4; ++i, j++){
        angolo b = punto::angoloTraTrePunti( getCoordinate()[i], getCoordinate()[1], getCoordinate()[2]);
        angoli[j] = b;
std::cout<<"**A**"<<angoli[j].getAngolo()<<std::endl;
    }
    angoli[4-3] = punto::angoloTraTrePunti(getCoordinate()[0], getCoordinate()[1], getCoordinate()[2]).getAngolo();

    double x=0, y=0, lato=0;
    for(unsigned int i=3, j=0; i<4; ++i, ++j){
        x=0; y=0;
        lato = punto::distanceTo(getCoordinate()[1]/*B*/, getCoordinate()[i]);//lato Bx
 //   std::cout<<"**"<<lato<<std::endl;
        if(angoli[j] != angolo(90)){
            x = lato * cos(angoli[j].getAngolo() * PI/180);
            y = lato * sin(angoli[j].getAngolo() * PI/180);
        } else{ //se angolo==90
            x = 0;
            y = lato;
        }
        q[i-1]= punto(x,y);//punti da q[2]..a q[numeroLati]
    }
    lato = punto::distanceTo(getCoordinate()[0], getCoordinate()[1]);
    std::cout<<"*<<*"<<lato<<std::endl<<std::endl<<std::endl<<std::endl;

    std::cout<<"******"<<angoli[1].getAngolo()<<"x"<<std::endl;
    if(angolo(90)==angoli[4-3]){
        std::cout<<"AAAAAAAAAAAAAA";
        x = 0;
        y = lato;
    }else{
        std::cout<<"kjgbgk";
        x = lato * cos(angoli[4-3].getAngolo() * PI/180);
        y = lato * sin(angoli[4-3].getAngolo() * PI/180);
    }
    q[4-1] = punto(x,y);//punti da q[2]..a q[numeroLati]
    setPunti(q);
}
