#include "angolo.h"

#include<iostream>


Angolo::Angolo(double val):gradi(val){}

const Angolo Angolo::angoloRetto=Angolo(90);

double Angolo::getAngolo() const{
    return gradi;
}

bool Angolo::operator >(const Angolo a)const{
    return gradi > a.gradi ;
}

bool Angolo::operator <(const Angolo a)const{
    return gradi < a.gradi ;
}

bool Angolo::operator ==(const Angolo a)const{
    return gradi == a.gradi ;
}

bool Angolo::operator !=(const Angolo a)const{
    return gradi != a.gradi ;
}

bool Angolo::angPiatto(const Angolo a)const{
    double min = 179.9, max = 180.02, val=0;    //per pb. macchina
    val = a.gradi+gradi;
    return ( min < val && val < max );
}

Angolo Angolo::operator+(const Angolo& ang)const{
    return Angolo( gradi + ang.gradi);
}

Angolo& Angolo::operator=(const Angolo& ang){
    this->gradi=ang.gradi;
    return *this;
}

double Angolo::coseno()const{
    double coseno = cos( getAngolo() * PI/180);
    if(-0.01<coseno && coseno<0.01)
        coseno=0;
    return coseno;
}

double Angolo::seno()const{
    double seno = sin( getAngolo() * PI/180);
    if(-0.01<seno && seno<0.01)   //per pb. macchina
        seno=0;
    return seno;
}
