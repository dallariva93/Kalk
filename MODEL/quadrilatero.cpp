#include "quadrilatero.h"
#include "triangolo.h"
#include "angolo.h"
#include "pentagono.h"

Quadrilatero::Quadrilatero() : Quadrilatero(10,10,10,10,Angolo(90),Angolo(90),Angolo(90),Angolo(90)){}

Quadrilatero::Quadrilatero(double latoAB, double latoBC, double latoCD, double latoAD, const Angolo& a, const Angolo& b, const Angolo& c, const Angolo& d, Colore* col, QString nome) : Poligono(4, nome, col){
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

Quadrilatero* Quadrilatero::clone() const{
    return new Quadrilatero(*this);
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

Quadrilatero& Quadrilatero::zoom(double fattore) const{
    return *(new Quadrilatero(getLati()[0]*fattore, getLati()[1]*fattore, getLati()[2]*fattore, getLati()[3]*fattore,
            getAngoli()[0], getAngoli()[1], getAngoli()[2], getAngoli()[3]));
}

Quadrilatero& Quadrilatero::cambiaBase(int n)const{
    QVector<double> lati = ordinaLati(getLati(),getLati()[n]);
    return *(new Quadrilatero(lati[0], lati[1], lati[2], lati[3],getAngoli()[0], getAngoli()[1], getAngoli()[2], getAngoli()[3],getColore()));
//eliminare garbage
}

Quadrilatero &Quadrilatero::specchia() const{
    QVector<Punto> vertici=getCoordinate();
    for(QVector<Punto>::iterator it=vertici.begin(); it<vertici.end(); ++it)
        it->invertiY();
    Quadrilatero& specchiato =*(new Quadrilatero(*this));
    specchiato.setPunti(vertici);
    return specchiato;
}

Poligono& Quadrilatero::unisci( const Poligono& pol)const{
    Colore& col = *(getColore()) + *(pol.getColore());
    QVector<Punto> coord;
    bool piatto=false;
    if(! ( getAngoli()[0].angPiatto(pol.getAngoli()[0]) ) ){
        coord.push_back(Punto::origine);
        piatto = true;
    }
    for(unsigned int i=pol.getCoordinate().size()-1; i>1; --i)
        coord.push_back( pol.getCoordinate()[i]);
    if(! ( getAngoli()[1].angPiatto(pol.getAngoli()[1]) ) )
        coord.push_back( getCoordinate()[1]);
    coord.push_back( getCoordinate()[2]);
    if(piatto)      coord.push_back( getCoordinate()[3]);
    else            coord.push_front( getCoordinate()[3]);
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
    else{   //coord.size()>5
        Triangolo& ecc = *(new Triangolo(10,10,10,new RGB(),"nonValido"));
        return ecc;
    }
}

Poligono& Quadrilatero::operator+(const Poligono& pol) const{
    double lato = latoComune(pol);
    int indice = indexLato(lato);
    Quadrilatero q = cambiaBase(indice);
    int index = pol.indexLato(lato);
    Poligono& p1 = pol.cambiaBase(index);
    p1 = p1.specchia();
    Poligono& poligono = q.unisci(p1); //garbage
    poligono.ruota(p1.getAngoli()[0]);
    return poligono;
}

void Quadrilatero::gira(){
    Angolo b_ad = 180 - getAngoli()[2].getAngolo();
    QVector<Punto> punti;
    punti.push_back(Punto(0,0));
    punti.push_back(Punto(getLati()[1],0));
    punti.push_back(Punto(  getLati()[1]+sen_cos(getLati()[2], b_ad).getX() ,
                            sen_cos(getLati()[2],b_ad).getY() ));
    punti.push_back(sen_cos(getLati()[0],getAngoli()[1]));
    setPunti(punti);
}
