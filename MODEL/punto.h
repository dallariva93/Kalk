#ifndef PUNTO_H
#define PUNTO_H
#include "angolo.h"
#include <cmath>
#define PI 3.14159265


class punto{
private:
    double x, y;
public:
    punto();
    punto(double x, double y);
    double getX()const;
    double getY()const;
    const static punto origine;
    double getX() const;
    double getY() const;
    static double distanceTo(const punto&, const punto&);
    static angolo angoloTraTrePunti(const punto&, const punto&, const punto&);
};
#endif // PUNTO_H
