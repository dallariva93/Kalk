#include "container.h"
#include "poligono.h"

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
    auto cit = color.cbegin();
    std::cout<<color.size();

    for(; cit != color.cend(); ++cit){
        std::cout<<"BBBBBBBBBBBBBBB = "<<name.toStdString()<<std::endl;
        Colore* p = *cit;
        std::cout<<"CCCCCCCCCCCCCCC = "<<(p->getHex()).toStdString()<<std::endl;
        if( p->getHex() == name){                      //  da problema (*cit)->getHex() "non lo prende tipo"

            return *cit;
        }
    }
    return 0;
}
