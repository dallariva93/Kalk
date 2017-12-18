#include "rgb.h"

RGB::RGB(unsigned int red, unsigned int green, unsigned int blu):r(red), g(green), b(blu){}     //costruttore a tre parametri, di default costruisce bianco
//rgb::rgb(std::string nome){}      costruttore di colore da nome

std::string RGB::decToHex(unsigned int value){
    std::stringstream stream;
    stream << std::hex << value;
    return stream.str();
}

RGB* RGB::clone() const{
    return new RGB(*this);
}

std::string RGB::getHex()const{
    std::string red=decToHex(r);
    std::string green=decToHex(g);
    std::string blue=decToHex(b);
    if(red=="0")red="00";
    if(green=="0")green="00";
    if(blue=="0")blue="00";
    return "#" + red + green + blue;
}

unsigned int RGB::getR()const{
    return r;
}

unsigned int RGB::getG()const{
    return g;
}

unsigned int RGB::getB()const{
    return b;
}

void RGB::inverti(){

}

RGB& RGB::operator+(const Colore & col)const
{
    unsigned int red=Colore::HexToDec(col.getHex().substr(1,2));
    unsigned int green=Colore::HexToDec(col.getHex().substr(3,2));
    unsigned int blue=Colore::HexToDec(col.getHex().substr(5,2));
    return *(new RGB(((getR()+red)/2),
                    ((getG()+green)/2),
                    ((getB()+blue)/2)));

}

RGB& RGB::operator-(const Colore & col)const
{
    unsigned int red=Colore::HexToDec(col.getHex().substr(1,2));
    unsigned int green=Colore::HexToDec(col.getHex().substr(3,2));
    unsigned int blue=Colore::HexToDec(col.getHex().substr(5,2));

    red > getR() ? red=0 : red=getR()-red;          //se red-getR() è <0 do come risultato 0
    green > getG() ? green=0 : green=getG()-green;
    blue > getB() ? blue=0 : blue=getB()-blue;

    return *(new RGB(red, green, blue));
}

