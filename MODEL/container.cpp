#include "container.h"

Container::Container(){
    polygon=QVector<Poligono*>();
    color=QVector<Colore*>();
}

void Container::addPoligono(Poligono* p){
    polygon.push_back(p);
}

void Container::addColore(Colore* c){
    if(!color.contains(c))
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
    for(auto cit = color.cbegin(); cit != color.cend(); ++cit){
        Colore *p = *cit;
        if( p->getHex() == name){
            return *cit;
        }
    }
    return 0;
}

Container::~Container(){
    for(auto it=polygon.begin(); it!=polygon.end(); ++it ){
        delete *it;
    }
    polygon.clear();

    for(auto it=color.begin(); it!=color.end(); ++it ){
        delete *it;
    }
    color.clear();
}
