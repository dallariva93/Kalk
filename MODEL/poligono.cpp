#include"punto.h"
#include "poligono.h"

Punto Poligono::sen_cos(double lato, Angolo a) {
    double x=0, y=0;
    if(a.getAngolo() != 90){
        x = lato * cos( a.getAngolo() * PI/180);
        y = lato * sin( a.getAngolo() * PI/180);
    } else {
        x = 0;
        y = lato;
    }
    return Punto( x,y );
}

QVector<double> Poligono::ordinaLati(QVector<double> lati, double lato){
    QVector<double> supporto;
    int index=lati.indexOf(lato);       //restituisce -1 se lato non è presente all'interno del vector
    if(index==-1){std::cout<<"non è presente un lato in comune"; /*eccezione*/}
    supporto=lati.mid(index);
    supporto+=lati.mid(0,index);
    return supporto;
}

Poligono::Poligono(unsigned int nLati, std::string nome, Colore* col, QVector<Punto> punti) : numeroLati(nLati), nomeOggetto(nome){
    color=col->clone();
    coordinate=punti;
}

QVector<Angolo> Poligono::getAngoli()const{
    QVector<Punto> punti=getCoordinate();
    QVector<Angolo> angoli;
    angoli.push_back(Punto::angoloTraTrePunti(punti.last(), punti.first(), punti[1]));
    for(int i=0; i<punti.size()-2; ++i){
        angoli.push_back(Punto::angoloTraTrePunti(punti[i], punti[i+1], punti[i+2]));
    }
    angoli.push_back(Punto::angoloTraTrePunti(punti[punti.size()-2], punti.last(), punti.first()));
    return angoli;
}

Colore* Poligono::getColore() const{
    return color;
}

void Poligono::setPunti(const QVector<Punto> coord){
    coordinate=coord;
}

QVector<Punto> Poligono::getCoordinate() const{
    return coordinate;
}

double Poligono::getPerimetro() const{
    double perimetro=0;
    for(unsigned int i=0; i<numeroLati; ++i){
        perimetro += getLati()[i];
    }
    return perimetro;
}

QVector<double> Poligono::getLati() const{
    QVector<double> lati;
    for(unsigned int i=0; i<numeroLati-1; ++i){
        lati.push_back(Punto::distanceTo(coordinate[i], coordinate[i+1]));
    }
    lati.push_back(Punto::distanceTo(coordinate.first(), coordinate.last()));
    return lati;
}

double Poligono::latoComune(const Poligono& p) const{
    bool latoUguale = false;
    double lato = 0;
    for(unsigned int i=0; i<numeroLati && !latoUguale; ++i){
        for(unsigned int j=0; j<p.numeroLati && !latoUguale; ++j){
            if( getLati()[i] == p.getLati()[j] ){
                lato = p.getLati()[j];
                latoUguale = true;
            }
        }
    }
    return lato;
}

