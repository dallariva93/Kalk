#ifndef QUADRATO_H
#define QUADRATO_H
#include"quadrilatero.h"


class quadrato : public quadrilatero
{
private:

public:
    quadrato(double lato, colore *col=new rgb());
    double getArea()const;
    double getPerimetro()const;
    void estendi(double);

};

#endif // QUADRATO_H
