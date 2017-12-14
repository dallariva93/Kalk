#include "triangolo.h"
#include "angolo.h"
#include <cmath>

#define PI 3.14159265

/*  fare i controlli
- somma angoli 180
- lato maggiore < somma degli altri due
- coorditate una (0,0) poi (_,0) e ultima (_,_) sempre!
*/
triangolo::triangolo(double latoAB, double latoAC, angolo a, colore* col) : poligono(3, "triangolo", col) {
    QVector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(latoAB,0));
    double x=0;
    if(a.getAngolo()!=0)    x = latoAC * cos((a.getAngolo() * 180.0) / PI);
    double y = latoAC * sin((a.getAngolo() * 180.0) / PI);
    punti.push_back(punto(x,y));
    setPunti(punti);
}

triangolo::triangolo(double latoAB, angolo a, angolo b, colore* col) : poligono(3, "triangolo", col) {
    angolo c = 180 - a.getAngolo()-b.getAngolo();
    QVector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(latoAB,0));
    double latoAC = ( latoAB * sin(b.getAngolo()*PI/180) ) / sin(c.getAngolo()*PI/180);
    double x=0;
    if(a.getAngolo()!=90)   x = latoAC * cos(a.getAngolo()*PI/180);
    double y = latoAC * sin(a.getAngolo() * PI / 180);
    if(a > 90)    //triangolo ottuso
        x = -x;
    punti.push_back(punto(x,y));
    setPunti(punti);
}

triangolo::triangolo(double latoAB, double latoBC, double latoAC, colore* col) : poligono(3, "triangolo", col) {
    double cos_a =-(( pow(latoBC,2) - pow(latoAC,2) - pow(latoAB,2) ) / 2*latoAB*latoAC) *PI/180;
    std::cout<<cos_a<<"fff"<<std::endl;
    angolo a = acos(cos_a)*180/PI;
    std::cout<<a.getAngolo()<<"dsfhidsuf";
    QVector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(latoAB,0));
    double x=0;
    if(a.getAngolo()!=90)  x= latoAC * cos(a.getAngolo()*PI/180);
    double y= latoAC * sin(a.getAngolo()*PI/180);
    if(a>90)    //triangolo ottuso
        x = -x;
    punti.push_back(punto(x,y));
    setPunti(punti);
}

double triangolo::getAltezza(){
    QVector<punto> vertice = this->getCoordinate();
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

double triangolo::getArea(){
    QVector<punto> vertici = this->getCoordinate();
    double base = punto::distanceTo(vertici[0],vertici[1]);    //la base è sempre la distanza dei primi due punti del vector
    return (base * getAltezza() ) / 2;
}
