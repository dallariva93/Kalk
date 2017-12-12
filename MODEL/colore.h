#ifndef COLORE_H
#define COLORE_H
#include<iostream>


class colore{

public:
    virtual colore* clone() const =0;
    virtual std::string getHex() const =0;
    virtual ~colore()=0;
};

#endif // COLORE_H