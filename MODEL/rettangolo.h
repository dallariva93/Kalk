#ifndef RETTANGOLO_H
#define RETTANGOLO_H
#include<quadrilatero.h>

class Rettangolo : public Quadrilatero
{
public:
    Rettangolo(double latoMinore, double latoMaggiore, Colore *col=new RGB());
    double getArea()const;
    double getPerimetro()const;
};

#endif // RETTANGOLO_H
