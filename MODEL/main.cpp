#include "rgb.h"
#include<iostream>
#include "triangolo.h"
#include "quadrato.h"
#include "angolo.h"
#include "rettangolo.h"
#define PI 3.14159265

int main(){
    Rettangolo rett(5,10);
    std::cout<<rett.getLati()[0]<<rett.getLati()[1];
    rett.ruotaSuUnLato(10);
    std::cout<<rett.getLati()[0]<<rett.getLati()[1];

}

