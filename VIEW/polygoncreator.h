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

    QPushButton* triangleButton;
    QPushButton* quadrilateralButton;
    QPushButton* pentagonButton;

    QHBoxLayout* buttonsLayout;
    QVBoxLayout* mainLayout;

public:
    PolygonCreator(QWidget *parent = 0);
    void refreshCreators();

signals:

public slots:
    void triangleSlot(bool);
    void quadrilateralSlot(bool);
    void pentagonSlot(bool);

};

#endif // POLYGONCREATOR_H
