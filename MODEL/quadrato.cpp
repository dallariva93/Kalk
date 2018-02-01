#include "quadrato.h"

Quadrato::Quadrato() : Quadrilatero() {}

Quadrato::Quadrato(double lato, Colore* col, QString nome) :
    Quadrilatero(lato,lato,lato,lato,Angolo(90), Angolo(90), Angolo(90), Angolo(90), col, nome){}

double Quadrato::getArea()const{
    return pow(Punto::distanceTo(Punto::origine,getCoordinate()[1]),2);
}

double Quadrato::getPerimetro()const{
    return 4*Punto::distanceTo(Punto::origine,getCoordinate()[1]);
}

void Quadrato::estendi(double fattore){
    Quadrato temp(getLati().first()*fattore);
    setPunti(temp.getCoordinate());
}

Quadrato& Quadrato::zoom(double fattore) const{
    return *(new Quadrato(getLati()[0]*fattore));
}

void Quadrato::cambiaBase(double lato){
    Quadrilatero::cambiaBase(lato);
}

Quadrato &Quadrato::specchia() const{
    QVector<Punto> vertici=getCoordinate();
    for(QVector<Punto>::iterator it=vertici.begin(); it<vertici.end(); ++it)
        it->invertiY();
    Quadrato& specchiato =*(new Quadrato(*this));
    specchiato.setPunti(vertici);
    return specchiato;
}

