#include "colorcreator.h"
#include <QVBoxLayout>
#include <QLabel>
#include <../VIEW/stylesheet.h>
#include <../MODEL/rgb.h>


ColorCreator::ColorCreator(QWidget* parent):QWidget(parent)
{
    //CREO GLI SLIDER E NE SETTO IL VALORE MASSIMO

    red=new QSlider(Qt::Horizontal);
    red->setRange(0,255);
    green=new QSlider(Qt::Horizontal);
    green->setRange(0,255);
    blue=new QSlider(Qt::Horizontal);
    blue->setRange(0,255);

    //CREO GLI LCD NUMBER

    redLCD=new QLCDNumber(3);
    greenLCD=new QLCDNumber(3);
    blueLCD=new QLCDNumber(3);

    //CREO DEI LABEL PER  IDENTIFICARE RED GREEN E BLUE

    QLabel* redLabel = new QLabel(tr("R:"));
    QLabel* greenLabel = new QLabel(tr("G:"));
    QLabel* blueLabel = new QLabel(tr("B:"));

    hexValue=new QLabel("stringdimmmerda");

    //MODIFICO GRAFICAMENTE GLI SLIDER E GLI LCD NUMBER: APPLICO DEI FOGLI DI STILE, MODIFICO IL NUMERO E TOLGO IL RIQUADRO

    red->setStyleSheet(Stylesheet::sliderStyle());
    green->setStyleSheet(Stylesheet::sliderStyle());
    blue->setStyleSheet(Stylesheet::sliderStyle());
    redLCD->setSegmentStyle(QLCDNumber::Flat);
    greenLCD->setSegmentStyle(QLCDNumber::Flat);
    blueLCD->setSegmentStyle(QLCDNumber::Flat);
    redLCD->setFrameStyle(QFrame::NoFrame);
    greenLCD->setFrameStyle(QFrame::NoFrame);
    blueLCD->setFrameStyle(QFrame::NoFrame);

    //CONNETTO SEGNALI CON SLOT APPROPRIATI

    connect(red, SIGNAL(valueChanged(int)), redLCD, SLOT(display(int)));
    connect(green, SIGNAL(valueChanged(int)), greenLCD, SLOT(display(int)));
    connect(blue, SIGNAL(valueChanged(int)), blueLCD, SLOT(display(int)));
  /*  connect(red,SIGNAL(valueChanged(int)), this, SLOT(setHexValue(int)));
    connect(green,SIGNAL(valueChanged(int)), this, SLOT(setHexValue()));
    connect(blue,SIGNAL(valueChanged(int)), this, SLOT(setHexValue(int)));
    connect(this,SIGNAL(valueChanged()), hexValue, SLOT(setText(QString)));*/

    //CREO UN LAYOUT A GRIGLIA E AGGIUNGO I WIDGET IN UN CERTO ORDINE

    QGridLayout* layout=new QGridLayout;
    layout->addWidget(red,0,0);
    layout->addWidget(redLabel,0,1);
    layout->addWidget(redLCD,0,2);
    layout->addWidget(green,1,0);
    layout->addWidget(greenLabel,1,1);
    layout->addWidget(greenLCD,1,2);
    layout->addWidget(blue,2,0);
    layout->addWidget(blueLabel,2,1);
    layout->addWidget(blueLCD,2,2);
    layout->addWidget(hexValue);
    setLayout(layout);

}
/*
void valueChanged(QString a){
    emit a;
}

QString ColorCreator::setHexValue(int){
    hex.fromStdString("#" + RGB::decToHex(red->value()) + RGB::decToHex(green->value()) + RGB::decToHex(blue->value()));
    emit valueChanged(hex);
}*/
