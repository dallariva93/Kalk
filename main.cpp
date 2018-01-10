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

    Colore* col = new RGB(136,244,189);
    Poligono* o = new Triangolo(15,20,10, col);
    Poligono* k = new Triangolo(10,10,Angolo(90),col);
    Poligono* f = new Triangolo(10,50,50,col);
    Poligono* q=new Triangolo(300,200,300,col);
    Poligono* pent= new PentagonoRegolare(100, col);
    Poligono* t= new Triangolo(10,10,10,col);
    Poligono* qu = new Quadrilatero(10,60,10,60,Angolo(90),Angolo(90),Angolo(90),Angolo(90));
    Poligono* a = new Quadrilatero(10,15,30,20,Angolo(80),Angolo(120), Angolo(60), Angolo(100));
    Poligono* ris=&(*t+*a);

    QApplication app(argc,argv);
    DrawArea d(ris);
    d.show();
    return app.exec();

}

