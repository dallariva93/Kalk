#ifndef QUADRILATERALCREATOR_H
#define QUADRILATERALCREATOR_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QRadioButton>
#include "MODEL/quadrilatero.h"
#include "MODEL/quadrato.h"
#include "VIEW/operandselector.h"

class QuadrilateralCreator : public QWidget{
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
    QLineEdit *nome;

    QLabel *latoA;
    QLabel *latoB;
    QLabel *latoC;
    QLabel *latoD;
    QLabel *angoloA;
    QLabel *angoloB;
    QLabel *angoloC;
    QLabel *angoloD;
    QLabel *labelNome;

    QLabel *colore;

    QPushButton *saveButton;
    QVBoxLayout *mainLayout;
    QVBoxLayout *choiceLayout;
    QHBoxLayout *colorLayout;
    QGridLayout *formLayout;
    QComboBox *colori;

    OperandSelector *selettore;

public:
    QuadrilateralCreator(QComboBox*col, OperandSelector *sel, QWidget *parent=0);
    void refreshFormWidget();
    ~QuadrilateralCreator();
signals:

public slots:
    void formQuadrato();
    void formRettangolo();
    void formQuadrilatero();
    void creaQuadrilatero();
};

#endif // QUADRILATERALCREATOR_H

