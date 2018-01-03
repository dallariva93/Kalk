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
#include"../VIEW/colorcreator.h"
#include"../VIEW/drawarea.h"
#include"../VIEW/trianglecreator.h"
#include"../VIEW/colorarea.h"


int main(int argc, char* argv[]){
    Poligono* q=new Quadrato(100);
    Poligono* p=new PentagonoRegolare(100);
    Colore* col = new RGB(136,244,189);



    QApplication createtriangle(argc,argv);
    QWidget* creator=new ColorCreator();
    QWidget* c=new ColorArea(col);
    QWidget::connect(creator,SIGNAL(changeHexValue(QString)),c, SLOT(colorChanged(QString)));
    c->show();
    creator->show();

    return createtriangle.exec();


}

