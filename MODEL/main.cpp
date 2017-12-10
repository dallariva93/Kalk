#include "rgb.h"
#include <QApplication>
#include<iostream>

int main()
{
    rgb colore(255,50,99);
    std::cout<<colore.getHex();
}
