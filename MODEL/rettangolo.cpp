#include "rettangolo.h"

Rettangolo::Rettangolo(double latoAB, double latoBC, Colore* col):
    Quadrilatero(latoAB, latoBC, latoAB, latoBC, Angolo::angoloRetto, Angolo::angoloRetto, Angolo::angoloRetto, Angolo::angoloRetto, col){}

double Rettangolo::getArea()const{
    return Punto::distanceTo(Punto::origine,getCoordinate()[1]) *
           Punto::distanceTo(getCoordinate()[1],getCoordinate()[2]);
}

double Rettangolo::getPerimetro()const{
    return 2 * (Punto::distanceTo(Punto::origine,getCoordinate()[1]) +
                Punto::distanceTo(getCoordinate()[1],getCoordinate()[2]));
}


void Rettangolo::cambiaBase(double lato){
    Quadrilatero::cambiaBase(lato);
}

Rettangolo &Rettangolo::specchia() const
{
    QVector<Punto> vertici=getCoordinate();
    for(QVector<Punto>::iterator it=vertici.begin(); it<vertici.end(); ++it)
        it->invertiY();
    Rettangolo& specchiato =*(new Rettangolo(*this));
    specchiato.setPunti(vertici);
    return specchiato;
}
