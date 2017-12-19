#include "rgb.h"
#include<iostream>
#include "triangolo.h"
#include "quadrato.h"
#include "angolo.h"
#define PI 3.14159265

int main(){
    Triangolo t(8,Angolo(45),Angolo(70));
    std::cout<<t.getLati()[0]<<"-"<<t.getLati()[1]<<"-"<<t.getLati()[2]<<std::endl;
    t.ruotaInModoFurbo(t.getLati()[1]);
    std::cout<<t.getLati()[0]<<"-"<<t.getLati()[1]<<"-"<<t.getLati()[2]<<std::endl;

}

