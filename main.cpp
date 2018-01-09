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


int main(int argc, char* argv[]){


    QApplication app(argc,argv);
    //TriangleCreator* t=new TriangleCreator();
    PolygonCreator* t= new PolygonCreator;
    //std::cout<<ris->getCoordinate()[3].getX();//()<<"z";
    //ColorCreator* c=new ColorCreator();
    //c->show();
    t->show();

    return app.exec();

}

