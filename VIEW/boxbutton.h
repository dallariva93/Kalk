#ifndef BOXBUTTON_H
#define BOXBUTTON_H

#include <QPushButton>
#include <QWidget>
#include "QGridLayout"
#include "QLineEdit"
#include "operandselector.h"

class BoxButtons : public QWidget{
    Q_OBJECT
private:
    QPushButton* somma;
    QPushButton* sottrazione;
    QPushButton* moltiplicazione;
    QPushButton* divisione;
    QPushButton* perimetro;
    QPushButton* area;
    QPushButton* angoli;
    QPushButton* lati;
    QPushButton* scala;
    QPushButton* ruota;

    QLineEdit* inputScala;
    QLineEdit* inputRuota;

    QGridLayout* layout;

public:
    explicit BoxButtons(QWidget *parent = 0);
    void getPerimetro();

signals:
    void stampa2p(double);

public slots:
    void outputPerimetro();
    void outputArea();
    void outputLati();
    void outputAngoli();
};

#endif // BOXBUTTON_H
