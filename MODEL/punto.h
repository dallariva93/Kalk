#ifndef PUNTO_H
#define PUNTO_H
#include "angolo.h"
#include <cmath>
#define PI 3.14159265


class Punto{
private:
    double x, y;
public:
    Punto();
    Punto(double x, double y);
    double getX()const;
    double getY()const;
    void invertiY();
    const static Punto origine;
    static double distanceTo(const Punto&, const Punto&);
    static Angolo angoloTraTrePunti(const Punto&, const Punto&, const Punto&);

};
#endif // PUNTO_H
