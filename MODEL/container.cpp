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
<<<<<<< HEAD
    for(auto cit = color.cbegin(); cit != color.cend(); ++cit){
        std::cout<<"string op 1 = "<<name.toStdString()<<std::endl;
        Colore *p = *cit;
        std::cout<<"CCC = "<<(p->getHex().toStdString())<<std::endl;
        if( p->getHex() == name){                      //  da problema (*cit)->getHex()
=======
    auto cit = color.cbegin();
    std::cout<<color.size();

    for(; cit != color.cend(); ++cit){
        std::cout<<"BBBBBBBBBBBBBBB = "<<name.toStdString()<<std::endl;
        Colore* p = *cit;
        std::cout<<"CCCCCCCCCCCCCCC = "<<(p->getHex()).toStdString()<<std::endl;
        if( p->getHex() == name){                      //  da problema (*cit)->getHex() "non lo prende tipo"

>>>>>>> de34c38af9b6be89a0010f90d3a15a0330ef0ba6
            return *cit;
        }
        return *cit;
    }
    return 0;
}
