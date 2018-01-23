#ifndef QUADRATO_H
#define QUADRATO_H
#include"quadrilatero.h"


class Quadrato : public Quadrilatero{

public:
    Quadrato();
    Quadrato(double lato, Colore *col=new RGB(), QString nome="quadrato");
    double getArea()const;
    double getPerimetro()const;
    void estendi(double);
    Quadrato& zoom(double)const;
    void cambiaBase(double);
    Quadrato& specchia()const;

};

#endif // QUADRATO_H
