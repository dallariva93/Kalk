#include "colorcreator.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QImage>
#include <QRgb>
#include <MODEL/rgb.h>
#include "exception.h"


ColorCreator::ColorCreator(OperandSelector* sel,QWidget* parent):QWidget(parent), selector(sel){
    QLabel* color=new QLabel("");
    color->setStyleSheet("QLabel { background-color : #000000;}");

    QSize size(250,170);
    setMaximumSize(size);
    setMinimumSize(size);

    red=new QSlider(Qt::Horizontal);
    red->setRange(0,255);
    green=new QSlider(Qt::Horizontal);
    green->setRange(0,255);
    blue=new QSlider(Qt::Horizontal);
    blue->setRange(0,255);

    redLCD=new QLCDNumber(3);
    greenLCD=new QLCDNumber(3);
    blueLCD=new QLCDNumber(3);

    redLabel = new QLabel(tr("Rosso:"));
    greenLabel = new QLabel(tr("Verde:"));
    blueLabel = new QLabel(tr("Blue:"));
    hexString = new QLabel(tr("Colore:"));
    hexValue=new QLineEdit("#000000");
    hexValue->setReadOnly(true);

    saveButton = new QPushButton;
    saveButton->setText("Crea");

    red->setStyleSheet(sliderStyle);
    green->setStyleSheet(sliderStyle);
    blue->setStyleSheet(sliderStyle);
    redLCD->setSegmentStyle(QLCDNumber::Flat);
    greenLCD->setSegmentStyle(QLCDNumber::Flat);
    blueLCD->setSegmentStyle(QLCDNumber::Flat);
    redLCD->setFrameStyle(QFrame::NoFrame);
    greenLCD->setFrameStyle(QFrame::NoFrame);
    blueLCD->setFrameStyle(QFrame::NoFrame);

    connect(red, SIGNAL(valueChanged(int)), redLCD, SLOT(display(int)));
    connect(green, SIGNAL(valueChanged(int)), greenLCD, SLOT(display(int)));
    connect(blue, SIGNAL(valueChanged(int)), blueLCD, SLOT(display(int)));
    connect(red,SIGNAL(valueChanged(int)), this, SLOT(getR(int)));
    connect(green,SIGNAL(valueChanged(int)), this, SLOT(getG(int)));
    connect(blue,SIGNAL(valueChanged(int)), this, SLOT(getB(int)));
    connect(this,SIGNAL(changeHexValue(QString)),hexValue, SLOT(setText(QString)));
    connect(this,SIGNAL(changeColor(QString)),color,SLOT(setStyleSheet(QString)));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(creaColore()));

    mainLayout = new QVBoxLayout;
    layout=new QGridLayout;
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
    mainLayout->addLayout(layout);
    mainLayout->addWidget(saveButton);
    setLayout(mainLayout);
}


void ColorCreator::getR(int r){
    QString hex=hexValue->text();
    hex=((hex).replace(1,2,RGB::decToHex(r)));
    emit changeHexValue(hex);
    QString a="QLabel { background-color :" ;
    a+=hex;
    a+=";}";
    emit changeColor(a);
}

void ColorCreator::getG(int g){
    QString hex=hexValue->text();
    hex=((hex).replace(3,2,RGB::decToHex(g)));
    emit changeHexValue(hex);
    QString a="QLabel { background-color :" ;
    a+=hex;
    a+=";}";
    emit changeColor(a);
}

Colore* ColorCreator::buildColore(){
    Colore* colore = new RGB(redLCD->value(),greenLCD->value(),blueLCD->value());

   if(selector->isPresent(colore->getHex())){
       delete colore;
       throw AlreadyPresent("Colore già presente");
   }
    return colore;
}

void ColorCreator::creaColore()try{
    Colore* colore = buildColore();
    emit inviaColore(colore);

}
catch (MyException){}

void ColorCreator::getB(int b){
    QString hex=hexValue->text();
    hex=((hex).replace(5,2,RGB::decToHex(b)));
    emit changeHexValue(hex);
    QString a="QLabel { background-color :" ;
    a+=hex;
    a+=";}";
    emit changeColor(a);
}

ColorCreator::~ColorCreator(){
    delete red;
    delete green;
    delete blue;
    delete redLCD;
    delete greenLCD;
    delete blueLCD;
    delete saveButton;
    delete hexValue;
    delete redLabel;
    delete greenLabel;
    delete blueLabel;
    delete hexString;
    delete layout;
    delete mainLayout;
}

QString ColorCreator::sliderStyle=QString("QSlider::groove:horizontal {"
                                  "border: 1px solid #bbb;"
                                  "background: white;"
                                  "height: 10px;"
                                  "border-radius: 4px;}"

                                   "QSlider::sub-page:horizontal {"
      "                                 background: qlineargradient(x1: 0, y1: 0,    x2: 0, y2: 1,stop: 0 #66e, stop: 1 #bbf);"     //qua c'è il colore sotto della barra
      "                                 background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,stop: 0 #bbf, stop: 1 #55f);"
      "                                 border: 1px solid #777;"
      "                                 height: 10px;"
      "                                 border-radius: 4px;"
                                  "}"

                                  "QSlider::add-page:horizontal {"
                                  "background: #fff;"
                                  "border: 1px solid #777;"
                                  "height: 10px;"
                                  "border-radius: 4px;"
                                  "}"

                                  "QSlider::handle:horizontal {"
                                  "background: qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 #eee, stop:1 #ccc);"
                                  "border: 1px solid #777;"
                                  "width: 13px;"
                                  "margin-top: -2px;"
                                  "margin-bottom: -2px;"
                                  "border-radius: 4px;"
                                  "}"

                                  "QSlider::handle:horizontal:hover {"
                                  "background: qlineargradient(x1:0, y1:0, x2:1, y2:1,stop:0 #fff, stop:1 #ddd);"
                                  "border: 1px solid #444;"
                                  "border-radius: 4px;"
                                  "}"

                                  "QSlider::sub-page:horizontal:disabled {"
                                  "background: #bbb;"
                                  "border-color: #999;"
                                  "}"

                                  "QSlider::add-page:horizontal:disabled {"
                                  "background: #eee;"
                                  "border-color: #999;"
                                  "}"

                                  "QSlider::handle:horizontal:disabled {"
                                  "background: #eee;"
                                  "border: 1px solid #aaa;"
                                  "border-radius: 4px;"
                                  "}");
