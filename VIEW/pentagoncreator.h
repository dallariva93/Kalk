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
#include <MODEL/pentagono.h>
#include <VIEW/operandselector.h>


class PentagonCreator : public QWidget{

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

    OperandSelector* selettore;
public:
    ~PentagonCreator();
    PentagonCreator(OperandSelector* sel, QWidget *parent = 0);
    void refreshFormWidget();
    Pentagono* buildPentagono();
    bool checkValidity();
    void inserisciColore(QIcon icona, QString nome);




signals:


public slots:
    void formIrregolare();
    void formRegolare();
    void creaPentagono();
};

#endif // PENTAGONCREATOR_H
