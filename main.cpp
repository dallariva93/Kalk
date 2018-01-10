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
#include"VIEW/quadrilateralcreator.h"
#include"VIEW/pentagoncreator.h"
#include"VIEW/polygoncreator.h"
#include"VIEW/dataarea.h"
#include"VIEW/window.h"
#include"VIEW/operandselector.h"

int main(int argc, char* argv[]){


    /*Colore* color=new RGB(170,80,93);
    Poligono* pol=new Triangolo(100,100,Angolo(90),color);*/
    QApplication app(argc,argv);
    //TriangleCreator* t=new TriangleCreator();
    //PolygonCreator* p= new PolygonCreator;
    //std::cout<<ris->getCoordinate()[3].getX();//()<<"z";
   // ColorCreator* c=new ColorCreator();
    //c->show();
   // DataArea *t=new DataArea;
    Window* t= new Window;
    //t->areaP->setPoligono(pol);
    //OperandSelector *t = new OperandSelector;
    t->show();
   // p->show();
    //c->show();

    return app.exec();

}

