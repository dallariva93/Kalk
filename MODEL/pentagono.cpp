#include "pentagono.h"
#include <math.h>

pentagono::pentagono(double lato, colore* col) : poligono(5, "pentagono", col){
//per pentagono regolare
    double x= lato * sin(45);
    double y= lato * cos(45);
    QVector<punto> punti;
    punti.push_back(punto( 0 , x ));
    punti.push_back(punto( y , 0 ));
    punti.push_back(punto( y+lato , 0 ));
    punti.push_back(punto( y+y+lato , x ));
    punti.push_back(punto( (y+y+lato)/2 , x+y ));
    setPunti(punti);
}

/*
pentagono::pentagono(double latoA, double latoB, double latoC, double latoD, double latoE, angolo a, angolo b, angolo c, angolo d, colore* col=new rgb()){

}

pentagono::pentagono(double, double, double, double, double, colore* col=new rgb()){

}

pentagono::pentagono(double, double, double, double, angolo, angolo, angolo, colore* col=new rgb()){

}

double pentagono::getArea(){

}

*/
