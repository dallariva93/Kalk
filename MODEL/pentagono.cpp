#include "pentagono.h"
#include "triangolo.h"
#include <math.h>

Pentagono::Pentagono(double latoAB, double latoBC, double latoCD, double latoDE, double latoAE, const Angolo& a, const Angolo& b,
                     const Angolo& c, const Angolo& d, const Angolo& e, Colore* col) : Poligono(5,"pentagono",col){
    QVector<Punto> punti;
    punti.push_back(Punto::origine);    //coordinata A
    punti.push_back(Punto(latoAB,0));   //coordinata B
    Triangolo t1(latoAB, latoBC, b);
    double latoAC = t1.getLati()[1];
    Angolo alfa = t1.getAngoli()[2];
    punti.push_back( sen_cos(latoAC,alfa) );    //coordinata C
    Triangolo t2(latoAE, latoDE, e);
    double latoAD = t2.getLati()[1];
    Angolo beta = t2.getAngoli()[1];
    Angolo gamma = a.getAngolo() - beta.getAngolo();
    punti.push_back( sen_cos(latoAD,gamma) );    //coordinata D
    punti.push_back( sen_cos(latoAE,a) );    //coordinata E
    setPunti(punti);
}

double Pentagono::getArea() const {
    Triangolo t1(getLati()[0], getLati()[1], Punto::distanceTo(getCoordinate()[0], getCoordinate()[2]));
    Triangolo t2(getLati()[2], Punto::distanceTo(getCoordinate()[0], getCoordinate()[2]), Punto::distanceTo(getCoordinate()[0], getCoordinate()[3]));
    Triangolo t3(getLati()[3], getLati()[4], Punto::distanceTo(getCoordinate()[0], getCoordinate()[3]));
    return t1.getArea()+t2.getArea()+t3.getArea();
}

void Pentagono::estendi(double fattore){
    Pentagono  p(getLati()[0]*fattore, getLati()[1]*fattore, getLati()[2]*fattore, getLati()[3]*fattore, getLati()[4]*fattore,
            getAngoli()[0], getAngoli()[1], getAngoli()[2], getAngoli()[3], getAngoli()[4]);
    setPunti(p.getCoordinate());
}

Pentagono &Pentagono::cambiaBase(int n) const{
    QVector<double> lati=ordinaLati(getLati(),getLati()[n]);
    Pentagono temp(lati[0], lati[1], lati[2], lati[3], lati[4], getAngoli()[0], getAngoli()[1], getAngoli()[2], getAngoli()[3], getAngoli()[4]);
    return temp;
}

Poligono& Pentagono::operator+(const Poligono&) const{

}
