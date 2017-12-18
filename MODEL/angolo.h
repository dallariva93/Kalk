#ifndef ANGOLO_H
#define ANGOLO_H


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
    Angolo operator+(const Angolo&)const;
    Angolo& operator=(const Angolo&);
};

#endif // ANGOLO_H
