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
        //std::cout<<"string op 1 = "<<name.toStdString()<<std::endl;
        Colore *p = *cit;
        //std::cout<<"CCC = "<<(p->getHex().toStdString())<<std::endl;
        if( p->getHex() == name){
            //std::cout<<"mathc="<<std::endl;
            return *cit;
        }
    }
    return 0;
}
