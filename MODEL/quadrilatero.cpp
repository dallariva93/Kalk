#include "quadrilatero.h"
#include "triangolo.h"
#include "angolo.h"
#include "pentagono.h"

/*  CONTROLLI DA FARE:
 * -    somma degli angoli = 360
*/
Quadrilatero::Quadrilatero() : Quadrilatero(10,10,10,10,Angolo(90),Angolo(90),Angolo(90),Angolo(90)){}

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

Quadrilatero &Quadrilatero::specchia() const{
    QVector<Punto> vertici=getCoordinate();
    for(QVector<Punto>::iterator it=vertici.begin(); it<vertici.end(); ++it)
        it->invertiY();
    Quadrilatero& specchiato =*(new Quadrilatero(*this));
    specchiato.setPunti(vertici);
    return specchiato;
}

Poligono& Quadrilatero::unisci(const Quadrilatero& q, const Poligono& pol){
    QVector<Punto> coord;
    if((q.getAngoli()[0] + pol.getAngoli()[0] ) != Angolo(180) )
        coord.push_back(Punto::origine);
    for(unsigned int i=pol.getCoordinate().size()-1; i>1; --i)
        coord.push_back( pol.getCoordinate()[i]);
    if((q.getAngoli()[1] + pol.getAngoli()[1]) != Angolo(180))
        coord.push_back( q.getCoordinate()[1]);
    coord.push_back( q.getCoordinate()[2]);
    coord.push_back( q.getCoordinate()[3]);
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
        return *(new Triangolo()); //tanto per compilare qua capire che fare in questo caso
    }
}

Poligono& Quadrilatero::operator+(const Poligono& pol) const{
    double lato = latoComune(pol);
    int indice = indexLato(lato);
    Quadrilatero q = cambiaBase(indice);
    int index = pol.indexLato(lato);
    Poligono& p1 = pol.cambiaBase(index);
    p1 = p1.specchia();
    return unisci(q, p1);
}
