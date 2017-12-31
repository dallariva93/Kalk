#ifndef ANGOLO_H
#define ANGOLO_H
#include <cmath>
#define PI 3.14159265

class Angolo{
private:
    double gradi;

public:
    static const Angolo angoloRetto;
    Angolo(double val=0);
    double getAngolo() const;
    bool operator >(const Angolo)const;
    bool operator <(const Angolo)const;
    bool operator ==(const Angolo)const;
    bool operator !=(const Angolo)const;
    bool angPiatto(const Angolo)const;
    Angolo operator+(const Angolo&)const;
    Angolo& operator=(const Angolo&);
    double coseno()const;
    double seno()const;
};

#endif // ANGOLO_H
