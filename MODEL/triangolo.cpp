#include "triangolo.h"
#include <cmath>

/*  fare i controlli
- somma angoli 180
- lato maggiore < somma degli altri due
- coorditate una (0,0) poi (_,0) e ultima (_,_) sempre!
- lato non negativi
*/
Triangolo::Triangolo(double latoAB, double latoAC, const Angolo& a, Colore* col) : Poligono(3, "triangolo", col) {
    QVector<Punto> punti;
    punti.push_back(Punto(0,0));
    punti.push_back(Punto(latoAB,0));
    double x=0;
    if(a.getAngolo()!=0)    x = latoAC * cos((a.getAngolo() *PI/180));
    double y = latoAC * sin(a.getAngolo() *PI/180);
    punti.push_back(Punto(x,y));
    setPunti(punti);
}

Triangolo::Triangolo(double latoAB, const Angolo& a, const Angolo& b, Colore* col) : Poligono(3, "triangolo", col) {
    Angolo c = 180 -a.getAngolo() -b.getAngolo();
    QVector<Punto> punti;
    punti.push_back(Punto(0,0));
    punti.push_back(Punto(latoAB,0));
    double latoAC = ( latoAB * sin(b.getAngolo()*PI/180) ) / sin(c.getAngolo()*PI/180);
    double x, y;
    if(a.getAngolo()!=90){
        x = latoAC * cos(a.getAngolo()*PI/180);
        y = latoAC * sin(a.getAngolo() * PI / 180);
    }
    else{
        x = 0;
        y = (latoAB * sin(b.getAngolo()*PI/180)) / sin(c.getAngolo()*PI/180);
    }
    punti.push_back(Punto(x,y));
    setPunti(punti);
}

Triangolo::Triangolo(double latoAB, double latoBC, double latoAC, Colore* col) : Poligono(3, "triangolo", col) {
    double cos_a =(( pow(latoAC,2) + pow(latoAB,2) - pow(latoBC,2)) / (2*latoAB*latoAC)) ;
    Angolo a = acos(cos_a)*180/PI;
    std::cout<<a.getAngolo()<<" <-angolo a"<<std::endl;
    QVector<Punto> punti;
    punti.push_back(Punto(0,0));
    punti.push_back(Punto(latoAB,0));
    double x=0;
    if(a.getAngolo()!=90)  x= latoAC * cos(a.getAngolo()*PI/180);
    double y= latoAC * sin(a.getAngolo()*PI/180);
    punti.push_back(Punto(x,y));
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

void Triangolo::estendi(double fattore)
{
    Triangolo temp(getLati()[0]*fattore, getLati()[1]*fattore, getLati()[2]*fattore);
    setPunti(temp.getCoordinate());
}
