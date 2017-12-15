#include "angolo.h"


angolo::angolo(double val):gradi(val){}

double angolo::getAngolo() const{
    return gradi;
}

bool angolo::operator >(const angolo a)const{
    return gradi > a.gradi ;
}

bool angolo::operator <(const angolo a)const{
    return gradi < a.gradi ;
}
