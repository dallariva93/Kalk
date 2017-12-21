#include "rgb.h"
#include<iostream>
#include "triangolo.h"
#include "quadrato.h"
#include "angolo.h"
#include "rettangolo.h"
#include "pentagono.h"
#include "quadrilatero.h"
#include "pentagonoregolare.h"
#define PI 3.14159265

int main(){

    Triangolo t(10, 15, Angolo(5));
    Triangolo p = t.cambiaBase(2);
    p = p.specchia();   //non va!
/*    for(unsigned int i=0; i<p.getLati().size(); ++i){
        std::cout<<"("<<p.getCoordinate()[i].getX()<<" , "<<p.getCoordinate()[i].getY()<<")"<<std::endl;
    }
*/
}

