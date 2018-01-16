#include "container.h"
#include "poligono.h"

Container::Container(){
    polygon=QVector<Poligono*>();
    color=QVector<Colore*>(1);
}

void Container::addPoligono(Poligono* p){
    polygon.push_back(p);
}

void Container::addColore(Colore* c){
    color.push_back(c);
}

Poligono* Container::getPoligono(QString name) const{
    for(QVector<Poligono*>::const_iterator cit = polygon.cbegin(); cit!=polygon.cend(); ++cit){
        if((*cit)->getNome() == name)
            return *cit;
    }
    return 0;
}

Colore* Container::getColore(QString name) const{
    for(QVector<Colore*>::const_iterator cit = color.cbegin(); cit != color.cend(); ++cit){
        if( (*cit)->getHex() == name)
            return *cit;
    }
    return 0;
}
