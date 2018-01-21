#ifndef CONTAINER_H
#define CONTAINER_H

#include <QVector>
#include "poligono.h"

class Container{
public:
    QVector<Poligono*> polygon;
    QVector<Colore*> color;

public:
    Container();
    void addPoligono(Poligono*);
    void addColore(Colore*);

    Poligono* getPoligono(QString) const;
    Colore* getColore(QString) const;
    ~Container();
};

#endif // CONTAINER_H
