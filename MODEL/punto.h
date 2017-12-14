#ifndef PUNTO_H
#define PUNTO_H
#include "angolo.h"

class punto{
private:
    double x, y;
public:
    punto();
    punto(double x, double y);
    double getX()const;
    double getY()const;
    static double distanceTo(const punto& primo, const punto& secondo);
    static angolo angoloTraTrePunti(const punto&, const punto&, const punto&);
};

#endif // PUNTO_H
