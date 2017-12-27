#include "colorcreator.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QImage>
#include <QRgb>
#include <../VIEW/stylesheet.h>
#include <../MODEL/rgb.h>


ColorCreator::ColorCreator(QWidget* parent):QWidget(parent)
{
    QLabel* color=new QLabel("");
    color->setStyleSheet("QLabel { background-color : #000000;}");

    //QString hex="#000000";

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

    //CREO DEI LABEL PER IDENTIFICARE RED GREEN BLUE E L'ESADECIMALE

    QLabel* redLabel = new QLabel(tr("Rosso:"));
    QLabel* greenLabel = new QLabel(tr("Verde:"));
    QLabel* blueLabel = new QLabel(tr("Blue:"));
    QLabel* hexString = new QLabel(tr("Colore:"));
    hexValue=new QLineEdit("#000000");
    hexValue->setReadOnly(true);

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
    connect(red,SIGNAL(valueChanged(int)), this, SLOT(getR(int)));
    connect(green,SIGNAL(valueChanged(int)), this, SLOT(getG(int)));
    connect(blue,SIGNAL(valueChanged(int)), this, SLOT(getB(int)));
    connect(this,SIGNAL(changeHexValue(QString)),hexValue, SLOT(setText(QString)));
    connect(this,SIGNAL(changeColor(QString)),color,SLOT(setStyleSheet(QString)));

    //CREO UN LAYOUT A GRIGLIA E AGGIUNGO I WIDGET IN UN CERTO ORDINE

    QGridLayout* layout=new QGridLayout;
    layout->addWidget(red,0,1);
    layout->addWidget(redLabel,0,0);
    layout->addWidget(redLCD,0,2);
    layout->addWidget(green,1,1);
    layout->addWidget(greenLabel,1,0);
    layout->addWidget(greenLCD,1,2);
    layout->addWidget(blue,2,1);
    layout->addWidget(blueLabel,2,0);
    layout->addWidget(blueLCD,2,2);
    layout->addWidget(hexString,3,0);
    layout->addWidget(hexValue,3,1);
    layout->addWidget(color,3,2);
    setLayout(layout);

}


void ColorCreator::getR(int r)
{
    QString hex=hexValue->text();
    hex=((hex).replace(1,2,QString::fromStdString(RGB::decToHex(r))));
    emit changeHexValue(hex);
    QString a="QLabel { background-color :" ;
    a+=hex;
    a+=";}";
    emit changeColor(a);
}

void ColorCreator::getG(int g)
{
    QString hex=hexValue->text();
    hex=((hex).replace(3,2,QString::fromStdString(RGB::decToHex(g))));
    emit changeHexValue(hex);
    QString a="QLabel { background-color :" ;
    a+=hex;
    a+=";}";
    emit changeColor(a);
}

void ColorCreator::getB(int b)
{
    QString hex=hexValue->text();
    hex=((hex).replace(5,2,QString::fromStdString(RGB::decToHex(b))));
    emit changeHexValue(hex);
    QString a="QLabel { background-color :" ;
    a+=hex;
    a+=";}";
    emit changeColor(a);
}



