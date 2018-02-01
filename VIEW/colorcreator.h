#ifndef COLORCREATOR_H
#define COLORCREATOR_H

#include <QMainWindow>
#include <QWidget>
#include <QSlider>
#include <QLCDNumber>
#include <QLabel>
#include <QString>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>
#include <MODEL/colore.h>
#include "operandselector.h"
class ColorCreator : public QWidget{
    Q_OBJECT
private:
    OperandSelector* selector;


    QSlider* red;
    QSlider* green;
    QSlider* blue;

    QLCDNumber* redLCD;
    QLCDNumber* greenLCD;
    QLCDNumber* blueLCD;

    QPushButton* saveButton;

    QLineEdit* hexValue;
    QLabel* redLabel;
    QLabel* greenLabel;
    QLabel* blueLabel;
    QLabel* hexString;

    QGridLayout* layout;
    QVBoxLayout* mainLayout;

    static QString sliderStyle;

public:
    ~ColorCreator();
    ColorCreator(OperandSelector* sel, QWidget *parent=0);
    Colore* buildColore();


signals:
    void changeHexValue(QString);
    void changeColor(QString);
    void inviaColore(Colore*);


public slots:
    void getR(int);
    void getB(int);
    void getG(int);
    void creaColore();
};


#endif // COLORCREATOR_H
