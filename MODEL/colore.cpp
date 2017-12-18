#include "colore.h"
#include<sstream>
#include<iomanip>

Colore::~Colore(){};

unsigned int Colore::HexToDec(std::string Hex){
    unsigned int dec;
    std::stringstream stream;
    stream << Hex;
    stream >> std::hex >> dec;
    return dec;
}


