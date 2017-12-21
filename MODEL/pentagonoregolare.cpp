#include "pentagonoregolare.h"

const Angolo PentagonoRegolare::angoloInterno= Angolo(108);

PentagonoRegolare::PentagonoRegolare(double lato, Colore* col) :
    Pentagono(lato,lato,lato,lato,lato,angoloInterno,angoloInterno,angoloInterno,angoloInterno,angoloInterno,col){}

double PentagonoRegolare::getArea()const{
   return Pentagono::getArea();
}
