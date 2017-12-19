#ifndef RETTANGOLO_H
#define RETTANGOLO_H
#include<quadrilatero.h>

class Rettangolo : public Quadrilatero{

public:
    Rettangolo(double latoMaggiore,double latoMinore, Colore *col=new RGB());
    double getArea()const;
    double getPerimetro()const;

    void ruotaSuUnLato(double);
};

#endif // RETTANGOLO_H
