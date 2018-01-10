#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include <QFrame>
#include <QPainter>
#include <MODEL/poligono.h>

//DRAWAREA È L'AREA DI DISEGNO PER OGNI POLIGONO, CI SARÀ SOLO UN OGGETTO VISIBILE CONTEMPORANEMANENTE,
//PER DISEGNARE UN OGGETTO SI COSTRUISCE LA DRAWAREA DI QUELL'OGGETTO USANDO IL COSTRUTTORE

class DrawArea : public QFrame
{
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

};

#endif // DRAWAREA_H
