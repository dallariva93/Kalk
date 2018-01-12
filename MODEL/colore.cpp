#include "colore.h"
#include<sstream>
#include<iomanip>

Colore::~Colore(){}

unsigned int Colore::HexToDec(QString Hex){
    unsigned int dec;
    std::stringstream stream;
    stream << Hex.toStdString();
    stream >> std::hex >> dec;
    return dec;
}

QColor Colore::toQcolor(){
    return QColor(getHex());
}


