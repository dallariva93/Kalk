#ifndef COLORAREA_H
#define COLORAREA_H

#include <QWidget>
#include <colore.h>


class ColorArea : public QWidget
{
    Q_OBJECT
private:
    Colore* colore;
public:
    ColorArea(Colore*);
    void setColore(Colore *);

protected:
    void paintEvent(QPaintEvent *event=0);

signals:

public slots:
    void colorChanged(QString);
};

#endif // COLORAREA_H
