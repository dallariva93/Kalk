#include "rgb.h"
#include <iostream>
#include "triangolo.h"
#include "quadrato.h"
#include "angolo.h"
#include "rettangolo.h"
#include "pentagono.h"
#include "quadrilatero.h"
#include "pentagonoregolare.h"
#define PI 3.14159265

#include<QApplication>
#include"../VIEW/colorslider.h"

int main(int argc, char* argv[])
{
    QApplication colorbox(argc,argv);
    ColorSlider col;
    col.show();
    return colorbox.exec();
}

