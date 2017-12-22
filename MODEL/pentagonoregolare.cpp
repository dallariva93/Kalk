#include "pentagonoregolare.h"

const Angolo PentagonoRegolare::angoloInterno= Angolo(108);

PentagonoRegolare::PentagonoRegolare(double lato, Colore* col) :
    Pentagono(lato,lato,lato,lato,lato,angoloInterno,angoloInterno,angoloInterno,angoloInterno,angoloInterno,col){}

double PentagonoRegolare::getArea()const{
    return Pentagono::getArea();
}

PentagonoRegolare &PentagonoRegolare::specchia() const
{
    QVector<Punto> vertici=getCoordinate();
    for(QVector<Punto>::iterator it=vertici.begin(); it<vertici.end(); ++it)
        it->invertiY();
    PentagonoRegolare& specchiato =*(new PentagonoRegolare(*this));
    specchiato.setPunti(vertici);
    return specchiato;
}
