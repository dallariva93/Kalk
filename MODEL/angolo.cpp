#include "angolo.h"


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

Angolo Angolo::operator+(const Angolo& ang)const
{
    return Angolo(this->gradi+ang.gradi);
}

Angolo& Angolo::operator=(const Angolo& ang){
    this->gradi=ang.gradi;
    return *this;
}

