#include "rgb.h"

RGB::RGB(unsigned int red, unsigned int green, unsigned int blu):r(red), g(green), b(blu){}     //costruttore a tre parametri, di default costruisce bianco
//rgb::rgb(std::string nome){}      costruttore di colore da nome

QString RGB::decToHex(unsigned int value){
    std::stringstream stream;
    stream << std::hex << value;
    QString hex;
    hex=QString::fromStdString(stream.str());
    if(value<16) hex="0"+hex;
    return hex;
}

RGB* RGB::clone() const{
    return new RGB(*this);
}

QString RGB::getHex()const{
    QString red=decToHex(r);
    QString green=decToHex(g);
    QString blue=decToHex(b);
    if(red=="0")red="00";
    if(green=="0")green="00";
    if(blue=="0")blue="00";
    return QString("#" + red + green + blue);
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
    *this=RGB()-*this;
}

RGB& RGB::operator+(const Colore & col)const{
    unsigned int* rgb=HexToRGB(col);
    RGB& tmp = *(new RGB(((getR()+rgb[0])/2),
                    ((getG()+rgb[1])/2),
                    ((getB()+rgb[2])/2)));
    delete []rgb;
    return tmp;

}

RGB& RGB::operator-(const Colore & col)const{
    unsigned int* rgb=HexToRGB(col);
    unsigned int red=rgb[0];
    unsigned int green=rgb[1];
    unsigned int blue=rgb[2];

    red > getR() ? red=0 : red=getR()-red;
    green > getG() ? green=0 : green=getG()-green;
    blue > getB() ? blue=0 : blue=getB()-blue;

    RGB& tmp = *(new RGB(red, green, blue));
    delete []rgb;
    return tmp;
}

RGB &RGB::operator*(const Colore & col) const{
    unsigned int* rgb=HexToRGB(col);
    RGB& tmp =  *(new RGB(((getR()*rgb[0])/255),
                     ((getG()*rgb[1])/255),
                     ((getB()*rgb[2])/255)));
    delete []rgb;
    return tmp;
}

RGB &RGB::operator/(const Colore & col) const{
    unsigned int* rgb=HexToRGB(col);
    unsigned int red=rgb[0];
    unsigned int green=rgb[1];
    unsigned int blue=rgb[2];

    red==0 ? red=1 : 0;
    green==0 ? green=1 : 0;
    blue==0 ? blue=1 : 0;

    RGB& tmp = *(new RGB(((getR()+red)), ((getG()+green)), ((getB()+blue))));
    delete [] rgb;
    return tmp;
}

unsigned int *RGB::HexToRGB(const Colore& col){
    unsigned int* rgb=new unsigned int[3];
    rgb[0]=Colore::HexToDec(col.getHex().mid(1,2));
    rgb[1]=Colore::HexToDec(col.getHex().mid(3,2));
    rgb[2]=Colore::HexToDec(col.getHex().mid(5,2));
    return rgb;
}



