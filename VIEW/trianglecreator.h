#ifndef TRIANGLECREATOR_H
#define TRIANGLECREATOR_H

#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QInputDialog>
#include <QFormLayout>
#include <QGroupBox>
#include <QRadioButton>

class TriangleCreator : public QWidget{
    Q_OBJECT

private:
    QRadioButton *radio1;
    QRadioButton *radio2;
    QRadioButton *radio3;

    QLineEdit *lato1;
    QLineEdit *lato2;
    QLineEdit *lato3;
    QLineEdit *angolo1;
    QLineEdit *angolo2;

    QLabel *latoA;
    QLabel *latoB;
    QLabel *latoC;
    QLabel *angoloA;
    QLabel *angoloB;

    QPushButton *saveButton;
    QVBoxLayout *mainLayout;
    QVBoxLayout *choiceLayout;
    QHBoxLayout *formLayout;

public:
    TriangleCreator(QWidget *parent=0);
    void refreshFormWidget();


public slots:
    void dueAngoliUnLato(bool);
    void treLati(bool);
    void dueLatiUnAngolo(bool);


};

#endif // TRIANGLECREATOR_H
