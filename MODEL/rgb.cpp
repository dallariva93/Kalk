#include "rgb.h"

rgb::rgb(unsigned int red, unsigned int green, unsigned int blu):r(red), g(green), b(blu){}     //costruttore a tre parametri, di default costruisce bianco
//rgb::rgb(std::string nome){}      costruttore di colore da nome

std::string rgb::decToHex(unsigned int value)
{
    std::stringstream stream;
    stream << std::hex << value;
    return stream.str();
}

std::string rgb::getHex()const
{
    return "#" + (decToHex(r)) + (decToHex(g)) + (decToHex(b));
}
