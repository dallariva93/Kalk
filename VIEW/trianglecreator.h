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
#include <QListWidgetItem>
#include "MODEL/triangolo.h"
#include "VIEW/operandselector.h"

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
    QLineEdit *nome;

    QLabel *latoA;
    QLabel *latoB;
    QLabel *latoC;
    QLabel *angoloA;
    QLabel *angoloB;
    QLabel *colore;
    QLabel *labelNome;

    QPushButton *saveButton;
    QVBoxLayout *mainLayout;
    QVBoxLayout *choiceLayout;
    QHBoxLayout *formLayout;
    QHBoxLayout *coloreNomeLayout;

    QComboBox *colori;
    QComboBox *realcol;

    OperandSelector* selettore;

public:
    TriangleCreator(OperandSelector *sel, QWidget *parent=0);
    void refreshFormWidget();
    Triangolo* buildTriangolo();
    void inserisciColore(QIcon, QString);


public slots:
    void dueAngoliUnLato();
    void treLati();
    void dueLatiUnAngolo();
    void creaTriangolo();

};

#endif // TRIANGLECREATOR_H
