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
    Triangolo t2(5,10,7);
    std::cout<<t.latoComune(t2);


}

