#ifndef RGB_H
#define RGB_H
#include"colore.h"
#include<sstream>
#include<iomanip>

class RGB : public Colore{

private:
    //std::string nome;
    static unsigned int* HexToRGB(const Colore &col);
    unsigned int r;
    unsigned int g;
    unsigned int b;

public:
    RGB(unsigned int r=255, unsigned int green=255, unsigned int blu=255);
    RGB* clone() const;
    unsigned int getR()const;
    unsigned int getG()const;            //per ora non servono
    unsigned int getB()const;
    std::string getHex()const;
    virtual void inverti();
    RGB& operator+(const Colore&)const;
    RGB& operator-(const Colore&)const;
    RGB& operator*(const Colore&)const;
    RGB& operator/(const Colore&)const;

    static std::string decToHex(unsigned int value);        //metodo statico di funzionalità (conversione decimale a esadecimale)

};


#endif // RGB_H
