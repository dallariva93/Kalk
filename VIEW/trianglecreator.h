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
    QPainter* triangle_box;
    QComboBox* costruttori;

public:
    TriangleCreator(QWidget *parent=0);


};

#endif // TRIANGLECREATOR_H
