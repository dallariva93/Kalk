#ifndef RGB_H
#define RGB_H
#include"colore.h"
#include<sstream>
#include<iomanip>

class rgb : public Colore{
public:
    rgb(unsigned int r=255, unsigned int green=255, unsigned int blu=255);
    rgb* clone() const;
    /*unsigned int getR();
    unsigned int getG();            //per ora non servono
    unsigned int getB();*/
    std::string getHex()const;

private:
    //std::string nome;
    static std::string decToHex(unsigned int value);        //metodo statico di funzionalità (conversione decimale a esadecimale)
    unsigned int r;
    unsigned int g;
    unsigned int b;
};


#endif // RGB_H
