#ifndef QUADRILATERALCREATOR_H
#define QUADRILATERALCREATOR_H

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

class QuadrilateralCreator : public QWidget
{
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
    QLabel *colore;

    QPushButton *saveButton;
    QVBoxLayout *mainLayout;
    QVBoxLayout *choiceLayout;
    QHBoxLayout *formLayout;

public:
    void refreshFormWidget();

signals:

public slots:
};

#endif // QUADRILATERALCREATOR_H
