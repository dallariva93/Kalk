#ifndef RETTANGOLO_H
#define RETTANGOLO_H
#include<quadrilatero.h>

class rettangolo : public quadrilatero
{
public:
    rettangolo(double latoMinore, double latoMaggiore, colore *col=new rgb());
    double getArea()const;
    double getPerimetro()const;
};

#endif // RETTANGOLO_H
