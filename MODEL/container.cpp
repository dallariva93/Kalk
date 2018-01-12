#include "container.h"

Container::Container(){

}

void Container::addPoligono(Poligono* p){
    polygon.push_back(p);
}

void Container::addColore(Colore* c){
    color.push_back(c);
}

Poligono* Container::getPoligono(QString name) const{
    QVector<Poligono*> vett = polygon;
    for(QVector<Poligono*>::Iterator it = vett.begin(); it!=vett.end(); ++it){
        if((*it)->getNome() == name)
            return *it;
    }
    return 0;
}

Colore* Container::getColore(QColor name) const{
    QVector<Colore*> vett = color;
    for(QVector<Colore*>::Iterator it = vett.begin(); it != vett.end(); ++it){
        if((*it)->toQcolor() == name)
            return *it;
    }
    return 0;
}
