#ifndef ANGOLO_H
#define ANGOLO_H


class angolo{
private:
    double gradi;

public:
    angolo(double val=0);
    double getAngolo();
    bool operator >(const angolo)const;
    bool operator <(const angolo)const;
};

#endif // ANGOLO_H
