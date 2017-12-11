#ifndef PUNTO_H
#define PUNTO_H


class punto
{
private:
    int x;
    int y;
public:
    punto();
    punto(int x, int y);
    int getX()const;
    int getY()const;
    static double distanceTo(const punto& primo, const punto& secondo);
};

#endif // PUNTO_H
