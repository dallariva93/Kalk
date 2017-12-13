#include "triangolo.h"
#include "angolo.h"
#include <math.h>

/*  fare i controlli
- somma angoli 180
- lato maggiore < somma degli altri due

*/
triangolo::triangolo(double latoA, double latoB, angolo c, colore* col) : poligono(3, "triangolo", col) {
//angolo compreso tra  i due lati
    QVector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(latoA,0));
    double x = latoB * cos(c.getAngolo());
    double y = latoB * sin(c.getAngolo());
    punti.push_back(punto(x,y));
    setPunti(punti);
}

triangolo::triangolo(double latoA, angolo b, angolo c, colore* col) : poligono(3, "triangolo", col) {
    angolo a = 180-b.getAngolo()-c.getAngolo();
    double latoC = (latoA * sin(c.getAngolo())) / sin(a.getAngolo());
    QVector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(latoA,0));
    double x= latoC * cos(b.getAngolo());
    double y= latoC * sin(b.getAngolo());
    punti.push_back(punto(x,y));
    setPunti(punti);
}

triangolo::triangolo(double latoA, double latoB, double latoC, colore* col) : poligono(3, "triangolo", col) {
    double cos_a = ( pow(latoA,2) + pow(latoB,2) + pow(latoC,2) ) / 2*latoB*latoC ;
    angolo a = acos(cos_a);
    QVector<punto> punti;
    punti.push_back(punto(0,0));
    punti.push_back(punto(latoB,0));
    double x= latoC * cos(a.getAngolo());
    double y= latoC * sin(a.getAngolo());
    punti.push_back(punto(x,y));
    setPunti(punti);
}

double triangolo::getArea(){
    QVector<punto> vertice = this->getCoordinate();
    double base = punto::distanceTo(vertice[0],vertice[1]);
    punto p = vertice[2];
    vertice.push_back(punto( p.getX() , 0 ));
    double altezza = punto::distanceTo(vertice[2],vertice[3]);
    double area = (base * altezza ) / 2;
    return area;
}
