#ifndef COLORE_H
#define COLORE_H
#include<iostream>
#include<QColor>


class Colore{
protected:
    static unsigned int HexToDec(QString Hex);
public:
    QColor toQcolor();
    virtual Colore* clone() const =0;
    virtual QString getHex() const =0;
    virtual ~Colore()=0;
    virtual void inverti()=0;       //fa side effect
    virtual Colore& operator+(const Colore&)const=0;
    virtual Colore& operator-(const Colore&)const=0;
    virtual Colore& operator*(const Colore&)const=0;
    virtual Colore& operator/(const Colore&)const=0;

};

#endif // COLORE_H
