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
    QLabel* redLabel;
    QLabel* greenLabel;
    QLabel* blueLabel;
    QLabel* hexString;

    QGridLayout* layout;

public:
    ~ColorCreator();
    ColorCreator(QWidget *parent=0);


signals:
    void changeHexValue(QString);
    void changeColor(QString);

public slots:
    void getR(int);
    void getB(int);
    void getG(int);
};

#endif // COLORCREATOR_H
