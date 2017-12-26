#ifndef COLORCREATOR_H
#define COLORCREATOR_H

#include <QMainWindow>
#include <QWidget>
#include <QSlider>
#include <QLCDNumber>
#include<QLabel>
#include <QString>
#include <QLineEdit>

class ColorCreator : public QWidget
{
    Q_OBJECT
private:
    QSlider* red;
    QSlider* green;
    QSlider* blue;

    QLCDNumber* redLCD;
    QLCDNumber* greenLCD;
    QLCDNumber* blueLCD;


    QLineEdit* hexValue;

public:
    ColorCreator(QWidget *parent=0);


signals:

    void changeHex(QString);        //va allo slot valuchanged(QString) di qlineedit

public slots:
    void getR(int);
    void getB(int);
    void getG(int);


};

#endif // COLORCREATOR_H
