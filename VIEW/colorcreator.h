#ifndef COLORCREATOR_H
#define COLORCREATOR_H

#include <QMainWindow>
#include <QWidget>
#include <QSlider>
#include <QLCDNumber>
#include<QLabel>
#include <QString>

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

    QLabel* hexValue;
    QString hex;

public:
    ColorCreator(QWidget *parent=0);


/*signals:

    void valueChanged2(QString);

public slots:
    QString setHexValue(int);*/


};

#endif // COLORCREATOR_H
