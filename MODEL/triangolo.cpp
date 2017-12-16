#include "triangolo.h"
#include <cmath>

/*  fare i controlli
- somma angoli 180
- lato maggiore < somma degli altri due
- coorditate una (0,0) poi (_,0) e ultima (_,_) sempre!
- lato non negativi
*/
triangolo::triangolo(double latoAB, double latoAC, const angolo& a, colore* col) : poligono(3, "triangolo", col) {
    QVector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(latoAB,0));
    double x=0;
    if(a.getAngolo()!=0)    x = latoAC * cos((a.getAngolo() *PI/180));
    double y = latoAC * sin(a.getAngolo() *PI/180);
    punti.push_back(punto(x,y));
    setPunti(punti);
}

triangolo::triangolo(double latoAB, const angolo& a, const angolo& b, colore* col) : poligono(3, "triangolo", col) {
    angolo c = 180 -a.getAngolo() -b.getAngolo();
    QVector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(latoAB,0));
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
    punti.push_back(punto(x,y));
    setPunti(punti);
}

triangolo::triangolo(double latoAB, double latoBC, double latoAC, colore* col) : poligono(3, "triangolo", col) {
    double cos_a =(( pow(latoAC,2) + pow(latoAB,2) - pow(latoBC,2)) / (2*latoAB*latoAC)) ;
    angolo a = acos(cos_a)*180/PI;
    std::cout<<a.getAngolo()<<" <-angolo a"<<std::endl;
    QVector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(latoAB,0));
    double x=0;
    if(a.getAngolo()!=90)  x= latoAC * cos(a.getAngolo()*PI/180);
    double y= latoAC * sin(a.getAngolo()*PI/180);
    punti.push_back(punto(x,y));
    setPunti(punti);
}

double triangolo::getAltezza() const{
    QVector<punto> vertice = getCoordinate();
    punto alto;
    int i=0;
    bool top=false;
    while(!top && i<3){
        punto p = vertice[i];
        if(p.getY()!=0){         //in questo modo controllo che prendo sempre il punto più alto che non sta nell' ascissa
            alto=p;
            top=true;
        }
        i++;
    }
    return punto::distanceTo( alto , punto( alto.getX() , 0 ) );
}


double triangolo::getArea() const{
    double p=getPerimetro()/2;
    return sqrt(p*(p-getLati()[0])*(p-getLati()[1])*(p-getLati()[2]));
}

triangolo triangolo::ruota() {

    QVector<punto> p(3);
//    QVector<double> lato = getLati();
    p[0] = punto(0,0);
    p[1] = punto(getLati()[1], 0);
    angolo b = punto::angoloTraTrePunti( QVector<punto>()[0], QVector<punto>()[1], QVector<punto>()[2]);
    double cx, cy;
    if(b.getAngolo() != 90 ){
        cx = getLati()[1] * cos( b.getAngolo() *PI/180);
        cy = getLati()[1] * sin( b.getAngolo() *PI/180);
    } else {
        cx = 0;
        cy = getLati()[1];
    }
    p[2] = punto(cx, cy);
    return *this;
}
