#include"punto.h"
#include "poligono.h"
#include "pentagono.h"

Poligono::Poligono(unsigned int nLati, QString nome, Colore* col, QVector<Punto> punti) : numeroLati(nLati), nomeOggetto(nome){
    color=col->clone();
    coordinate=punti;
}

QString Poligono::getNome()const{
    return nomeOggetto;
}

double Poligono::getPerimetro() const{
    double perimetro=0;
    for(unsigned int i=0; i<numeroLati; ++i){
        perimetro += getLati()[i];
    }
    return perimetro;
}

Colore* Poligono::getColore() const{
    return color;
}

void Poligono::setColore(Colore* c){
    color=c->clone();
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

void Poligono::setPunti(const QVector<Punto> coord){
    coordinate=coord;
}

QVector<Punto> Poligono::getCoordinate() const{
    return coordinate;
}

QVector<double> Poligono::getLati() const{
    QVector<double> lati;
    for(unsigned int i=0; i<numeroLati-1; ++i){
        lati.push_back(Punto::distanceTo(coordinate[i], coordinate[i+1]));
    }
    lati.push_back(Punto::distanceTo(coordinate.first(), coordinate.last()));
    return lati;
}

void Poligono::ruota(Angolo angolo){
    double min=-0.01, max=0.01;
    QVector<Punto> vertici=getCoordinate();
    for(QVector<Punto>::iterator it=vertici.begin(); it<vertici.end(); ++it){
        double x = (it->getX()*angolo.coseno()) + (it->getY()*angolo.seno());
        if(min<x && x<max)  x=0;    //per pb. macchina
        double y = ((it->getX())*angolo.seno()) - (it->getY()*angolo.coseno());
        if(min<y && y<max)  y=0;    //per pb. macchina
    }
    double cosAngoloCorretto;
    angolo.getAngolo()==90 ? cosAngoloCorretto=0 : cosAngoloCorretto=angolo.coseno();
    for(QVector<Punto>::iterator it=vertici.begin(); it<vertici.end(); ++it){
        double x = (it->getX()*cosAngoloCorretto) - (it->getY()*angolo.seno());
        if(min<x && x<max)  x=0;    //per pb. macchina
        double y = ((it->getX())*angolo.seno()) + (it->getY()*cosAngoloCorretto);
        if(min<y && y<max)  y=0;    //per pb. macchina
        *(it)=Punto(x,y);
    }
    setPunti(vertici);
}

QVector<double> Poligono::ordinaLati(QVector<double> lati, double lato){
    QVector<double> supporto;
    int index=lati.indexOf(lato);       //restituisce -1 se lato non è presente all'interno del vector
    //    if(index==-1){std::cout<<"non è presente un lato in comune"; /*eccezione verrà verificata all'inserimento dati.*/}
    if(index==0) return lati;   //poggia già sulla base giusta
    supporto=lati.mid(index);
    supporto+=lati.mid(0,index);
    return supporto;
}

Punto Poligono::sen_cos(double lato, Angolo a) {
    double x=0, y=0;
    if(a.getAngolo() != 90){
        x = lato * a.coseno();
        y = lato * a.seno();
    } else {
        x = 0;
        y = lato;
    }
   return Punto( x,y );
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

int Poligono::indexLato(double lato) const{
    QVector<double> lati = getLati();
    int index = lati.indexOf(lato);
    return index;
}

QPolygonF Poligono::toQPolygon(){
    QVector<QPointF> Qpunti;
    for(int i=0; i<getLati().size(); ++i){
        QPointF punto;
        punto.setX(getCoordinate()[i].getX());
        punto.setY(getCoordinate()[i].getY());
        Qpunti.push_back(punto);
    }
    return QPolygonF(Qpunti);
}
