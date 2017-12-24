#include "pentagono.h"
#include "triangolo.h"
#include "quadrilatero.h"
#include <math.h>

Pentagono::Pentagono() : Pentagono(10,10,10,10,10,Angolo(108),Angolo(108),Angolo(108),Angolo(108),Angolo(108)){}

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
    return *(new Pentagono(lati[0], lati[1], lati[2], lati[3], lati[4], getAngoli()[0], getAngoli()[1], getAngoli()[2], getAngoli()[3], getAngoli()[4]));
//eliminare garbage
}

Pentagono &Pentagono::specchia() const
{
    QVector<Punto> vertici=getCoordinate();
    for(QVector<Punto>::iterator it=vertici.begin(); it<vertici.end(); ++it)
        it->invertiY();
    Pentagono& specchiato =*(new Pentagono(*this));
    specchiato.setPunti(vertici);
    return specchiato;
}

Poligono& Pentagono::unisci(const Pentagono& pe, const Poligono& pol){
    QVector<Punto> coord;
    if((pe.getAngoli()[0] + pol.getAngoli()[0] ) != Angolo(180) )
        coord.push_back(Punto::origine);
    for(unsigned int i=pol.getCoordinate().size()-1; i>1; --i)
        coord.push_back( pol.getCoordinate()[i]);
    if((pe.getAngoli()[1] + pol.getAngoli()[1]) != Angolo(180))
        coord.push_back( pe.getCoordinate()[1]);
    for(unsigned int i=2; i<pe.getCoordinate().size(); ++i)
        coord.push_back( pe.getCoordinate()[i]);
    if(coord.size() == 3){
        Triangolo& t = *(new Triangolo());
        t.setPunti(coord);
        return t;
    }
    else if(coord.size() == 4){
        Quadrilatero& q = *(new Quadrilatero());
        q.setPunti(coord);
        return q;
    }
    else if(coord.size() == 5){
        Pentagono& p = *(new Pentagono());
        p.setPunti(coord);
        return p;
    }
    else{   //coord.size()>5
        //poligono con più di 5 lati;
        return *(new Triangolo()); //tanto per compilare qua capire cge fare in questo caso
    }
}

Poligono& Pentagono::operator+(const Poligono& pol) const{
    double lato = latoComune(pol);
    int indice = indexLato(lato);
    Pentagono q = cambiaBase(indice);
    int index = pol.indexLato(lato);
    Poligono& p = pol.cambiaBase(index);
    p = p.specchia();
    return unisci(q, p);
}


