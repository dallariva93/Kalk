#include "MODEL/rgb.h"
#include <iostream>
#include "MODEL/triangolo.h"
#include "MODEL/quadrato.h"
#include "MODEL/angolo.h"
#include "MODEL/rettangolo.h"
#include "MODEL/pentagono.h"
#include "MODEL/quadrilatero.h"
#include "MODEL/pentagonoregolare.h"
#define PI 3.14159265


#include<QApplication>
#include"VIEW/colorcreator.h"
#include"VIEW/drawarea.h"
#include"VIEW/trianglecreator.h"
#include"VIEW/colorarea.h"


int main(int argc, char* argv[]){

    Poligono* p=new Triangolo(300,150,300);
    Colore* col = new RGB(136,244,189);
    Poligono* q=new Triangolo(300,300,150);
    Poligono* pent= new PentagonoRegolare(1000);
    QApplication app(argc, argv);
    Poligono* ris=&(*p+*q);
    //std::cout<<ris->getCoordinate()[3].getX();//()<<"z";
    DrawArea d(pent);
    d.show();
    return app.exec();



}

