#include "pentagono.h"
#include "triangolo.h"
#include <math.h>

Pentagono::Pentagono(double latoAB, double latoBC, double latoCD, double latoDE, double latoAE, const Angolo& a, const Angolo& b,
                     const Angolo& c, const Angolo& d, const Angolo& e, Colore* col) : Poligono(5,"pentagono",col){
    double x=0, y=0, latoAD=0, latoAC=0;
    QVector<Punto> punti;
    punti.push_back(Punto::origine);    //coordinata A
    punti.push_back(Punto(0,latoAB));   //coordinata B
    Triangolo t1(latoAB, latoBC, b);
    latoAC = Punto::distanceTo(t1.getCoordinate()[1], t1.getCoordinate()[2]);
//problema angolo tre punti 120 o 021 angolo dovrebbe risultare uguale!!
    Angolo alfa = Punto::angoloTraTrePunti(t1.getCoordinate()[1], t1.getCoordinate()[2], t1.getCoordinate()[0]);
    punti.push_back( sen_cos(latoAC,alfa) );    //coordinata C
    Triangolo t2(latoAE, latoAB, a);
    latoAD = Punto::distanceTo(t2.getCoordinate()[1], t2.getCoordinate()[2]);
    Angolo gamma = Punto::angoloTraTrePunti(t2.getCoordinate()[0], t2.getCoordinate()[1], t2.getCoordinate()[2]);
    Angolo beta = 180 - gamma.getAngolo();
    punti.push_back( sen_cos(latoAD,beta) );    //coordinata D
    punti.push_back(t2.getCoordinate()[2]);    //coordinata E
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

void Pentagono::ruotaSuUnLato(double lato){
    QVector<double> lati=ordinaLati(this->getLati(),lato);
    Pentagono p(lati[0], lati[1], lati[2], lati[3], lati[4], getAngoli()[0], getAngoli()[1], getAngoli()[2], getAngoli()[3], getAngoli()[4]);
    setPunti(p.getCoordinate());
}

