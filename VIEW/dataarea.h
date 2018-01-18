#ifndef DATAAREA_H
#define DATAAREA_H
#include <QWidget>
#include <QTextEdit>
#include <MODEL/poligono.h>

class DataArea : public QTextEdit{
    Q_OBJECT

private:

public:
    DataArea();
    void setText(QVector<double>);

signals:

public slots:
    void outputPerimetro(double);
    void outputArea(double);
    void outputAngoli(QVector<Angolo>);
    void outputLati(QVector<double>);
};

#endif // DATAAREA_H
