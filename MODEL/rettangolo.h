#ifndef RETTANGOLO_H
#define RETTANGOLO_H
#include<quadrilatero.h>

class rettangolo : public quadrilatero
{
public:
    rettangolo(double latoMinore, double latoMaggiore, colore *col=new rgb());
};

#endif // RETTANGOLO_H
