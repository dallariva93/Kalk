#ifndef DATAAREA_H
#define DATAAREA_H
#include <QWidget>
#include <QTextEdit>

class DataArea : public QTextEdit{
    Q_OBJECT

private:

public:
    DataArea();
    void setText(QVector<double>);

signals:

public slots:
    void outputPerimetro(double);

};

#endif // DATAAREA_H
