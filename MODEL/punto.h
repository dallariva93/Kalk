#ifndef PUNTO_H
#define PUNTO_H


class punto{
private:
    double x, y;
public:
    punto();
    punto(double x, double y);
    double getX()const;
    double getY()const;
    static double distanceTo(const punto& primo, const punto& secondo);
};

#endif // PUNTO_H
