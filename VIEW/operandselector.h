#ifndef OPERANDSELECTOR_H
#define OPERANDSELECTOR_H

#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QHBoxLayout>

class OperandSelector : public QWidget
{
    Q_OBJECT
private:
    QLabel *operando;
    QComboBox *selector;
    QHBoxLayout *mainLayout;
public:
    OperandSelector(QWidget *parent = 0);

signals:

public slots:
};

#endif // OPERANDSELECTOR_H
