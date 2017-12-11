#ifndef COLORE_H
#define COLORE_H
#include<iostream>


class colore
{
private:

public:
    virtual std::string getHex()=0;
    virtual ~colore()=0;

};

#endif // COLORE_H
