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

void RGB::inverti(){            //inverti funziona come r=255-r, g=255-g, b=255-b
    *this=RGB()-*this;
}

RGB& RGB::operator+(const Colore & col)const            //gaaaarbaaageeee
{
    unsigned int* rgb=HexToRGB(col);
    return *(new RGB(((getR()+rgb[0])/2),
                    ((getG()+rgb[1])/2),
                    ((getB()+rgb[2])/2)));

}

RGB& RGB::operator-(const Colore & col)const            //gaaaarbaaageeee
{
    unsigned int* rgb=HexToRGB(col);
    unsigned int red=rgb[0];
    unsigned int green=rgb[1];
    unsigned int blue=rgb[2];

    red > getR() ? red=0 : red=getR()-red;          //se red-getR() è <0 do come risultato 0
    green > getG() ? green=0 : green=getG()-green;
    blue > getB() ? blue=0 : blue=getB()-blue;

    return *(new RGB(red, green, blue));
}

RGB &RGB::operator*(const Colore & col) const           //gaaaarbaaageeee
{
    unsigned int* rgb=HexToRGB(col);
    return *(new RGB(((getR()*rgb[0])/255),
                     ((getG()*rgb[1])/255),
                     ((getB()*rgb[2])/255)));
}

RGB &RGB::operator/(const Colore & col) const               //gaaaarbaaageeee
{
    unsigned int* rgb=HexToRGB(col);
    unsigned int red=rgb[0];
    unsigned int green=rgb[1];
    unsigned int blue=rgb[2];

    red==0 ? red=1 : 0;
    green==0 ? green=1 : 0;                             //sarà la soluzione migliore? da pensarci
    blue==0 ? blue=1 : 0;

    return *(new RGB(((getR()+red)), ((getG()+green)), ((getB()+blue))));
}

unsigned int *RGB::HexToRGB(const Colore& col)
{
    unsigned int* rgb=new unsigned int[3];
    rgb[0]=Colore::HexToDec(col.getHex().substr(1,2));
    rgb[1]=Colore::HexToDec(col.getHex().substr(3,2));
    rgb[2]=Colore::HexToDec(col.getHex().substr(5,2));
    return rgb;
}



