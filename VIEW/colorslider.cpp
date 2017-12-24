#include "colorslider.h"
#include <QVBoxLayout>

ColorSlider::ColorSlider(QWidget* parent):QWidget(parent)
{
    red=new QSlider();
    red->setRange(0,255);
    green=new QSlider();
    green->setRange(0,255);
    blue=new QSlider();
    blue->setRange(0,255);

    redLCD=new QLCDNumber(3);
    greenLCD=new QLCDNumber(3);
    blueLCD=new QLCDNumber(3);

    connect(red, SIGNAL(valueChanged(int)), redLCD, SLOT(display(int));
    connect(green, SIGNAL(valueChanged(int)), greenLCD, SLOT(display(int));
    connect(blue, SIGNAL(valueChanged(int)), blueLCD, SLOT(display(int));

    QVBoxLayout* layout=new QVBoxLayout;
    layout->addWidget(red);
    layout->addWidget(redLCD);
    layout->addWidget(green);
    layout->addWidget(greenLCD);
    layout->addWidget(blue);
    layout->addWidget(blueLCD);
    setLayout(layout);



}

