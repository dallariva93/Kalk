#ifndef PENTAGONCREATOR_H
#define PENTAGONCREATOR_H

#include <QWidget>
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QRadioButton>

class PentagonCreator : public QWidget
{
    Q_OBJECT
private:
    QRadioButton *radio1;
    QRadioButton *radio2;

    QLineEdit *lato1;
    QLineEdit *lato2;
    QLineEdit *lato3;
    QLineEdit *lato4;
    QLineEdit *lato5;
    QLineEdit *angolo1;
    QLineEdit *angolo2;
    QLineEdit *angolo3;
    QLineEdit *angolo4;
    QLineEdit *angolo5;
    QLineEdit *nome;

    QLabel *latoA;
    QLabel *latoB;
    QLabel *latoC;
    QLabel *latoD;
    QLabel *latoE;
    QLabel *angoloA;
    QLabel *angoloB;
    QLabel *angoloC;
    QLabel *angoloD;
    QLabel *angoloE;
    QLabel *labelNome;

    QLabel *colore;

    QPushButton *saveButton;
    QVBoxLayout *mainLayout;
    QVBoxLayout *choiceLayout;
    QHBoxLayout *colorLayout;
    QGridLayout *formLayout;
    QComboBox *colori;
public:
    PentagonCreator(QWidget *parent = 0);
    void refreshFormWidget();


signals:


public slots:
    void formIrregolare();
    void formRegolare();
};

#endif // PENTAGONCREATOR_H
