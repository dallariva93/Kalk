#include "quadrilatero.h"
#include "triangolo.h"
#include "angolo.h"

/*  CONTROLLI DA FARE:
 * -    somma degli angoli = 360
*/


Quadrilatero::Quadrilatero(double latoAB, double latoBC, double latoCD, double latoAD, const Angolo& a, const Angolo& b, const Angolo& c, const Angolo& d, Colore* col) : Poligono(4, "quadrato", col){
    //if(a+b+c+d>angolo(360))break;       //mettere eccezione
    double cx, cy, dx, dy;
    Angolo b_ad = 180 - b.getAngolo();
    QVector<Punto> punti;
    punti.push_back(Punto(0,0));
    punti.push_back(Punto(latoAB,0));
    punti.push_back(Punto(  latoAB+sen_cos(latoBC, b_ad).getX() ,
                            sen_cos(latoBC,b_ad).getY() ));
    punti.push_back(sen_cos(latoAD,a));
    setPunti(punti);
}

double Quadrilatero::getArea() const{
    Triangolo t1(getLati()[0], getLati()[1],Punto::distanceTo(getCoordinate()[0],getCoordinate()[2]));
    Triangolo t2(Punto::distanceTo(getCoordinate()[0],getCoordinate()[2]), getLati()[2], getLati()[3]);
    return t1.getArea()+t2.getArea();
}

void Quadrilatero::estendi(double fattore){
    Quadrilatero temp(getLati()[0]*fattore,getLati()[1]*fattore,getLati()[2]*fattore,getLati()[3]*fattore,getAngoli()[0], getAngoli()[1], getAngoli()[2], getAngoli()[3]);
    setPunti(temp.getCoordinate());
}

Quadrilatero& Quadrilatero::cambiaBase(int n)const{
    QVector<double> lati=ordinaLati(getLati(),getLati()[n]);
    return *(new Quadrilatero(lati[0], lati[1], lati[2], lati[3],getAngoli()[0], getAngoli()[1], getAngoli()[2], getAngoli()[3]));
//eliminare garbage
}

Poligono& Quadrilatero::operator+(const Poligono& p) const{}

Quadrilatero &Quadrilatero::specchia() const
{
    QVector<Punto> vertici=getCoordinate();
    for(QVector<Punto>::iterator it=vertici.begin(); it<vertici.end(); ++it)
        it->invertiY();
    Quadrilatero& specchiato =*(new Quadrilatero(*this));
    specchiato.setPunti(vertici);
    return specchiato;
}
