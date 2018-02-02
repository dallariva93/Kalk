#include "pentagono.h"
#include "triangolo.h"
#include "quadrilatero.h"
#include <math.h>
#include "VIEW/exception.h"

const Angolo Pentagono::angoloInterno= Angolo(108);

Pentagono::Pentagono() : Pentagono(10,10,10,10,Angolo(108),Angolo(108),Angolo(108)){}

Pentagono::Pentagono(double latoAB, double latoBC, double latoDE, double latoAE, const Angolo& a, const Angolo& b,
                      const Angolo& e, Colore* col, QString nome) : Poligono(5,nome,col){
    QVector<Punto> punti;
    punti.push_back(Punto::origine);
    punti.push_back(Punto(latoAB,0));
    Angolo b2 = 180-b.getAngolo();
    Triangolo t1(latoAB, latoBC, b2);
    punti.push_back(Punto(  (punti[1].getX()+(latoBC*b2.coseno()))  ,   (latoBC*b2.seno())));
    Triangolo t2(latoAE, latoDE, e);
    double latoAD = t2.getLati()[1];
    Angolo beta = t2.getAngoli()[1];
    Angolo gamma = a.getAngolo() - beta.getAngolo();
    punti.push_back( sen_cos(latoAD,gamma) );
    punti.push_back( sen_cos(latoAE,a) );
    setPunti(punti);
}

Pentagono::Pentagono(double lato, Colore* col, QString nome) :
    Pentagono(lato,lato,lato,lato,angoloInterno,angoloInterno,angoloInterno,col,nome){}

Pentagono* Pentagono::clone() const{
    return new Pentagono(*this);
}

double Pentagono::getArea() const {
    Triangolo t1(getLati()[0], getLati()[1], Punto::distanceTo(getCoordinate()[0], getCoordinate()[2]));
    Triangolo t2(getLati()[2], Punto::distanceTo(getCoordinate()[0], getCoordinate()[2]), Punto::distanceTo(getCoordinate()[0], getCoordinate()[3]));
    Triangolo t3(getLati()[3], getLati()[4], Punto::distanceTo(getCoordinate()[0], getCoordinate()[3]));
    return t1.getArea()+t2.getArea()+t3.getArea();
}

void Pentagono::estendi(double fattore){
    Pentagono  p(getLati()[0]*fattore, getLati()[1]*fattore, getLati()[3]*fattore, getLati()[4]*fattore,
            getAngoli()[0], getAngoli()[1], getAngoli()[4]);
    setPunti(p.getCoordinate());
}

Pentagono& Pentagono::zoom(double fattore) const{
    return *(new Pentagono(getLati()[0]*fattore, getLati()[1]*fattore, getLati()[3]*fattore, getLati()[4]*fattore,
            getAngoli()[0], getAngoli()[1], getAngoli()[4]));
}

Pentagono &Pentagono::cambiaBase(int n) const{
    QVector<double> lati=ordinaLati(getLati(),getLati()[n]);
    return *(new Pentagono(lati[0], lati[1], lati[3], lati[4], getAngoli()[0], getAngoli()[1], getAngoli()[2],getColore()));
}

Pentagono &Pentagono::specchia() const{
    QVector<Punto> vertici=getCoordinate();
    for(QVector<Punto>::iterator it=vertici.begin(); it<vertici.end(); ++it)
        it->invertiY();
    Pentagono& specchiato =*(new Pentagono(*this));
    specchiato.setPunti(vertici);
    return specchiato;
}

Poligono& Pentagono::unisci(const Poligono& pol)const{
    Colore& col = *(getColore()) + *(pol.getColore());
    QVector<Punto> coord;
    if(! ( getAngoli()[0].angPiatto(pol.getAngoli()[0]) ) )
        coord.push_back(Punto::origine);
    for(int i=pol.getCoordinate().size()-1; i>1; --i)
        coord.push_back( pol.getCoordinate()[i]);
    if(! ( getAngoli()[1].angPiatto(pol.getAngoli()[1]) ) )
        coord.push_back( getCoordinate()[1]);
    for(int i=2; i<getCoordinate().size(); ++i)
        coord.push_back( getCoordinate()[i]);
    if(coord.size() == 3){
        Triangolo& t = *(new Triangolo());
        t.setPunti(coord);
        t.setColore(& col);
        return t;
    }
    else if(coord.size() == 4){
        Quadrilatero& q = *(new Quadrilatero());
        q.setPunti(coord);
        q.setColore(& col);
        return q;
    }
    else if(coord.size() == 5){
        Pentagono& p = *(new Pentagono());
        p.setPunti(coord);
        p.setColore(& col);
        return p;
    }
    else{
        throw WrongPolygon("Il poligono ha più di cinque lati!");
    }
}

Poligono& Pentagono::operator+(const Poligono& pol) const{
    double lato = latoComune(pol);
    int indice = indexLato(lato);
    Pentagono q = cambiaBase(indice);
    int index = pol.indexLato(lato);
    Poligono& p = pol.cambiaBase(index);
    Poligono& tmp = p;
    p = p.specchia();
    Poligono& poligono = q.unisci(p);
    poligono.ruota(p.getAngoli()[0]);
    delete &p;
    delete &tmp;
    return poligono;
}

void Pentagono::gira(){
    QVector<Punto> punti;
    punti.push_back(Punto::origine);
    punti.push_back(Punto(getLati()[1],0));
    Angolo b2 = 180-getAngoli()[2].getAngolo();
    Triangolo t1(getLati()[1], getLati()[2], b2);
    punti.push_back(Punto(  (punti[1].getX()+(getLati()[2]*b2.coseno())), (getLati()[2]*b2.seno())));
    Triangolo t2(getLati()[0], getLati()[4], getAngoli()[0]);
    double latoAD = t2.getLati()[1];
    Angolo beta = t2.getAngoli()[1];
    Angolo gamma = (getAngoli()[1]).getAngolo() - beta.getAngolo();
    punti.push_back( sen_cos(latoAD,gamma) );
    punti.push_back( sen_cos(getLati()[0],getAngoli()[1]) );
    setPunti(punti);
}
