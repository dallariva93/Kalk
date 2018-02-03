#include "MODEL/rgb.h"
#include <iostream>
#include "MODEL/triangolo.h"
#include "MODEL/quadrato.h"
#include "MODEL/angolo.h"
#include "MODEL/rettangolo.h"
#include "MODEL/pentagono.h"
#include "MODEL/quadrilatero.h"
#define PI 3.14159265

#include<QApplication>
#include"VIEW/colorcreator.h"
#include"VIEW/drawarea.h"
#include"VIEW/trianglecreator.h"
#include"VIEW/quadrilateralcreator.h"
#include"VIEW/pentagoncreator.h"
#include"VIEW/polygoncreator.h"
#include"VIEW/dataarea.h"
#include"VIEW/window.h"
#include"VIEW/operandselector.h"
#include"VIEW/boxbutton.h"
#include"VIEW/exception.h"

int main(int argc, char* argv[]){
    QApplication app(argc,argv);
    MyException c();
    Window* x= new Window;
    QIcon icon(":/logo.ico");
    app.setWindowIcon(icon);
    x->show();
    return app.exec();
}

