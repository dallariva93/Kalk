#include "triangolo.h"
#include <cmath>
#include<QVector>
#include "quadrilatero.h"
#include "pentagono.h"
#include "VIEW/exception.h"

Triangolo::Triangolo() : Triangolo(10,10,10) {}

Triangolo::Triangolo(double latoAB, double latoAC, const Angolo& a, Colore* col, QString nome) : Poligono(3, nome, col) {
    QVector<Punto> punti;
    punti.push_back(Punto::origine);
    punti.push_back(Punto(latoAB,0));
    punti.push_back(sen_cos(latoAC,a));
    setPunti(punti);
}

Triangolo::Triangolo(double latoAB, const Angolo& a, const Angolo& b, Colore* col, QString nome) : Poligono(3, nome, col) {
    Angolo c = 180 -a.getAngolo() -b.getAngolo();
    QVector<Punto> punti;
    punti.push_back(Punto::origine);
    punti.push_back(Punto(latoAB,0));
    double latoAC = ( latoAB * b.seno() ) / c.seno();
    punti.push_back(sen_cos(latoAC, a));
    setPunti(punti);
}

Triangolo::Triangolo(double latoAB, double latoBC, double latoAC, Colore* col, QString nome) : Poligono(3, nome, col) {
    double cos_a =(( pow(latoAC,2) + pow(latoAB,2) - pow(latoBC,2)) / (2*latoAB*latoAC)) ;
    Angolo a = acos(cos_a)*180/PI;
    QVector<Punto> punti;
    punti.push_back(Punto::origine);
    punti.push_back(Punto(latoAB,0));
    punti.push_back(sen_cos(latoAC,a));
    setPunti(punti);
}

Triangolo* Triangolo::clone() const{
    return new Triangolo(*this);
}

double Triangolo::getAltezza() const{
    return Punto::distanceTo( getCoordinate()[2] , Punto( getCoordinate()[2].getX() , 0 ) );
}

double Triangolo::getArea() const{
    double p=getPerimetro()/2;
    return sqrt(p*(p-getLati()[0])*(p-getLati()[1])*(p-getLati()[2]));
}

void Triangolo::estendi(double fattore){
    Triangolo temp(getLati()[0]*fattore, getLati()[1]*fattore, getLati()[2]*fattore);
    setPunti(temp.getCoordinate());
}

Triangolo& Triangolo::zoom(double fattore) const{
    return *(new Triangolo(getLati()[0]*fattore, getLati()[1]*fattore, getLati()[2]*fattore));
}

Triangolo &Triangolo::cambiaBase(int n)const {
    QVector<double> lati=ordinaLati(this->getLati(), getLati()[n]);
    return *(new Triangolo(lati[0],lati[1],lati[2],getColore()));
}

Triangolo &Triangolo::specchia() const{
    QVector<Punto> vertici=getCoordinate();
    for(QVector<Punto>::iterator it=vertici.begin(); it<vertici.end(); ++it)
        it->invertiY();
    Triangolo& t =*(new Triangolo(*this));
    t.setPunti(vertici);
    return t;
}

Poligono& Triangolo::unisci(const Poligono& pol)const{
    Colore& col = *(getColore()) + *(pol.getColore());
    QVector<Punto> coord;
    bool piatto=false;      //per riordinare i lati quando ho degli angoli piatti
    if(! ( getAngoli()[0].angPiatto(pol.getAngoli()[0]) ) ){
        coord.push_back(Punto::origine);    //angolo != da 180
        piatto=true;
    }
    for(unsigned int i=pol.getCoordinate().size()-1; i>1; --i)
        coord.push_back( pol.getCoordinate()[i]);
    if(! ( getAngoli()[1].angPiatto(pol.getAngoli()[1]) ) )
        coord.push_back( getCoordinate()[1]);
    if(piatto)     coord.push_back( getCoordinate()[2]);
    else            coord.push_front( getCoordinate()[2]);
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

Poligono& Triangolo::operator+(const Poligono& pol) const{
    double lato = latoComune(pol);
    int indice = indexLato(lato);
    Triangolo t1 = cambiaBase(indice);
    int index = pol.indexLato(lato);
    Poligono& p1 = pol.cambiaBase(index);
    Poligono& tmp = p1;
    p1 = p1.specchia();
    Poligono& poligono = t1.unisci(p1);
    poligono.ruota(p1.getAngoli()[0]);
    delete &p1;
    return poligono;
}

void Triangolo::gira(){
    QVector<Punto> punti;
    punti.push_back(Punto::origine);
    punti.push_back(Punto(getLati()[1],0));
    punti.push_back(sen_cos(getLati()[0],getAngoli()[1]));
    setPunti(punti);
}


