#include "triangolo.h"
#include <cmath>
#include<QVector>
#include "quadrilatero.h"
#include "pentagono.h"

/*  fare i controlli
- somma angoli 180
- lato maggiore < somma degli altri due
- coorditate una (0,0) poi (_,0) e ultima (_,_) sempre!
- lato non negativi
*/
Triangolo::Triangolo() : Triangolo(10,10,10) {}

Triangolo::Triangolo(double latoAB, double latoAC, const Angolo& a, Colore* col) : Poligono(3, "triangolo", col) {
    QVector<Punto> punti;
    punti.push_back(Punto::origine);
    punti.push_back(Punto(latoAB,0));
    punti.push_back(sen_cos(latoAC,a));
    setPunti(punti);
}

Triangolo::Triangolo(double latoAB, const Angolo& a, const Angolo& b, Colore* col) : Poligono(3, "triangolo", col) {
    Angolo c = 180 -a.getAngolo() -b.getAngolo();
    QVector<Punto> punti;
    punti.push_back(Punto::origine);
    punti.push_back(Punto(latoAB,0));
    double latoAC = ( latoAB * sin(b.getAngolo()*PI/180) ) / sin(c.getAngolo()*PI/180);
    punti.push_back(sen_cos(latoAC, a));
    setPunti(punti);
}

Triangolo::Triangolo(double latoAB, double latoBC, double latoAC, Colore* col) : Poligono(3, "triangolo", col) {
    double cos_a =(( pow(latoAC,2) + pow(latoAB,2) - pow(latoBC,2)) / (2*latoAB*latoAC)) ;
    Angolo a = acos(cos_a)*180/PI;
    QVector<Punto> punti;
    punti.push_back(Punto::origine);
    punti.push_back(Punto(latoAB,0));
    punti.push_back(sen_cos(latoAC,a));
    setPunti(punti);
}

double Triangolo::getAltezza() const{
    QVector<Punto> vertice = getCoordinate();
    Punto alto;
    int i=0;
    bool top=false;
    while(!top && i<3){
        Punto p = vertice[i];
        if(p.getY()!=0){         //in questo modo controllo che prendo sempre il punto più alto che non sta nell' ascissa
            alto=p;
            top=true;
        }
        i++;
    }
    return Punto::distanceTo( alto , Punto( alto.getX() , 0 ) );
}

double Triangolo::getArea() const{
    double p=getPerimetro()/2;
    return sqrt(p*(p-getLati()[0])*(p-getLati()[1])*(p-getLati()[2]));
}

void Triangolo::estendi(double fattore){
    Triangolo temp(getLati()[0]*fattore, getLati()[1]*fattore, getLati()[2]*fattore);
    setPunti(temp.getCoordinate());
}

Triangolo &Triangolo::cambiaBase(int n)const {       //n != 0
    QVector<double> lati=ordinaLati(this->getLati(), getLati()[n]);
    return *(new Triangolo(lati[0],lati[1],lati[2]));               //eliminare garbage
}

Triangolo &Triangolo::specchia() const{
    QVector<Punto> vertici=getCoordinate();
    for(QVector<Punto>::iterator it=vertici.begin(); it<vertici.end(); ++it)
        it->invertiY();
    Triangolo& t =*(new Triangolo(*this));
    t.setPunti(vertici);
    return t;
}

Poligono& Triangolo::unisci(const Triangolo& t, const Poligono& pol){
    QVector<Punto> coord;
    if((t.getAngoli()[0] + pol.getAngoli()[0] ) != Angolo(180) )//PROBLEMA: Anche se la somma è 180 esegue l'if !!
        coord.push_back(Punto::origine);
    for(unsigned int i=pol.getCoordinate().size()-1; i>1; --i)
        coord.push_back( pol.getCoordinate()[i]);
    if((t.getAngoli()[1] + pol.getAngoli()[1]) != Angolo(180))
        coord.push_back( t.getCoordinate()[1]);
    coord.push_back( t.getCoordinate()[2]);
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

Poligono& Triangolo::operator+(const Poligono& pol) const{
    double lato = latoComune(pol);
    int indice = indexLato(lato);
    Triangolo t1 = cambiaBase(indice);
    int index = pol.indexLato(lato);
    Poligono& p1 = pol.cambiaBase(index);
    p1 = p1.specchia();
    return unisci(t1, p1);
}











