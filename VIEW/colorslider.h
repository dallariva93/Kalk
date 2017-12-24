#ifndef COLORSLIDER_H
#define COLORSLIDER_H

#include <QMainWindow>
#include <QWidget>
#include <QSlider>
#include <QLCDNumber>

class ColorSlider : public QWidget
{
    Q_OBJECT
private:
    QSlider* red;
    QSlider* green;
    QSlider* blue;

    QLCDNumber* redLCD;
    QLCDNumber* greenLCD;
    QLCDNumber* blueLCD;

public:
    ColorSlider(QWidget *parent=0);
public slots:
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);
};

#endif // COLORSLIDER_H
