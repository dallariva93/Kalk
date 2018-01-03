#ifndef RETTANGOLO_H
#define RETTANGOLO_H
#include<MODEL/quadrilatero.h>

class Rettangolo : public Quadrilatero{

public:
    Rettangolo(double latoMaggiore,double latoMinore, Colore *col=new RGB());
    double getArea()const;
    double getPerimetro()const;
    void cambiaBase(double);
    Rettangolo& specchia()const;
};

#endif // RETTANGOLO_H
