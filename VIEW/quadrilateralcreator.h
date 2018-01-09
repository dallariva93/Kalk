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
    QLineEdit *lato4;
    QLineEdit *angolo1;
    QLineEdit *angolo2;
    QLineEdit *angolo3;
    QLineEdit *angolo4;

    QLabel *latoA;
    QLabel *latoB;
    QLabel *latoC;
    QLabel *latoD;
    QLabel *angoloA;
    QLabel *angoloB;
    QLabel *angoloC;
    QLabel *angoloD;

    QLabel *colore;

    QPushButton *saveButton;
    QVBoxLayout *mainLayout;
    QVBoxLayout *choiceLayout;
    QHBoxLayout *colorLayout;
    QGridLayout *formLayout;
    QComboBox *colori;


public:
    QuadrilateralCreator(QWidget *parent=0);
    void refreshFormWidget();

signals:

public slots:
    void formQuadrato(bool);
    void formRettangolo(bool);
    void formQuadrilatero(bool);
};

#endif // QUADRILATERALCREATOR_H
