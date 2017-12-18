#include "angolo.h"


angolo::angolo(double val):gradi(val){}

const angolo angolo::angoloRetto=angolo(90);

double angolo::getAngolo() const{
    return gradi;
}

bool angolo::operator >(const angolo a)const{
    return gradi > a.gradi ;
}

bool angolo::operator <(const angolo a)const{
    return gradi < a.gradi ;
}

bool angolo::operator ==(const angolo a)const{
    return gradi == a.gradi ;
}

bool angolo::operator !=(const angolo a)const{
    return gradi != a.gradi ;
}

angolo angolo::operator+(const angolo& ang)const
{
    return angolo(this->gradi+ang.gradi);
}

angolo& angolo::operator=(const angolo& ang){
    this->gradi=ang.gradi;
    return *this;
}

