#ifndef POLYGONCREATOR_H
#define POLYGONCREATOR_H

#include <QWidget>
#include"trianglecreator.h"
#include"quadrilateralcreator.h"
#include"pentagoncreator.h"
#include<QPushButton>

class PolygonCreator : public QWidget{

    Q_OBJECT
private:
    TriangleCreator* triangleWidget;
    QuadrilateralCreator* quadrilateralWidget;
    PentagonCreator* pentagonWidget;

    QComboBox* colori;
    OperandSelector* selettore;

    QPushButton* triangleButton;
    QPushButton* quadrilateralButton;
    QPushButton* pentagonButton;

    QHBoxLayout* buttonsLayout;
    QVBoxLayout* mainLayout;

public:
    PolygonCreator(OperandSelector*, QComboBox*, QWidget *parent = 0);  //ho aggiunto colore
    void refreshCreators();
    ~PolygonCreator();


signals:

public slots:
    void triangleSlot();
    void quadrilateralSlot();
    void pentagonSlot();
    void addColore(Colore*);

};

#endif // POLYGONCREATOR_H
