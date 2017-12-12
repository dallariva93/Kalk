#ifndef QUADRILATERO_H
#define QUADRILATERO_H
#include "poligono.h"

class quadrilatero : public poligono{
public:
    quadrilatero();
    double getArea()const;
    double getPerimetro()const;
};

#endif // QUADRILATERO_H
