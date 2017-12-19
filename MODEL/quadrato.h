#ifndef QUADRATO_H
#define QUADRATO_H
#include"quadrilatero.h"


class Quadrato : public Quadrilatero
{
private:

public:
    Quadrato(double lato, Colore *col=new RGB());
    double getArea()const;
    double getPerimetro()const;
    void estendi(double);
    void ruotaInModoFurbo(double);

};

#endif // QUADRATO_H
