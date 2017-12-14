#include "triangolo.h"
#include "angolo.h"
#include <math.h>

/*  fare i controlli
- somma angoli 180
- lato maggiore < somma degli altri due
- coorditate una (0,0) poi (_,0) e ultima (_,_) sempre!
*/
triangolo::triangolo(double latoAB, double latoAC, angolo a, colore* col) : poligono(3, "triangolo", col) {
    QVector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(latoAB,0));
    double x = latoAC * cos(a.getAngolo());
    double y = latoAC * sin(a.getAngolo());
    punti.push_back(punto(x,y));
    setPunti(punti);
}

triangolo::triangolo(double latoAB, angolo a, angolo b, colore* col) : poligono(3, "triangolo", col) {
    angolo c = 180 - a.getAngolo()-b.getAngolo();
    QVector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(latoAB,0));
    double latoAC = ( latoAB * sin(b.getAngolo()) ) / sin(c.getAngolo());
    double x = latoAC * cos(a.getAngolo());
    double y = latoAC * sin(a.getAngolo());
    if(a > 90)    //triangolo ottuso
        x = -x;
    punti.push_back(punto(x,y));
    setPunti(punti);
}

triangolo::triangolo(double latoAB, double latoBC, double latoAC, colore* col) : poligono(3, "triangolo", col) {
    double cos_a = ( pow(latoAB,2) + pow(latoAC,2) - pow(latoBC,2) ) / 2*latoAB*latoAC ;
    angolo a = acos(cos_a);
    QVector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(latoAB,0));
    double x= latoAC * cos(a.getAngolo());
    double y= latoAC * sin(a.getAngolo());
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
