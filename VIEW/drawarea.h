#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include <QFrame>
#include <QPainter>
#include <MODEL/poligono.h>



class DrawArea : public QFrame{

    Q_OBJECT
private:
    Poligono* poligono;

public:
    void setPoligono(Poligono*pol);
    DrawArea(Poligono* =0);
    static void sposta(Poligono* pol,double x, double y);

protected:
    void paintEvent(QPaintEvent *event=0);

signals:

public slots:
    void settaPoligono(Poligono*);

};

#endif // DRAWAREA_H
