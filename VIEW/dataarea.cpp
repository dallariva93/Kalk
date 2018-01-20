#include "dataarea.h"
#include <sstream>
#include<QChar>
#include<iostream>
DataArea::DataArea(){
    setReadOnly(true);
    QSize size(200,250);
    setMinimumSize(size);
    setMaximumSize(size);
    setStyleSheet("border: 1px solid grey; background-color: white;");
}
/*
void DataArea::setText(QVector<double> lati){
    QString letter("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    for(int i=0; i<lati.size(); ++i){
        std::stringstream stream;
        stream<<lati[i];
        const char* c=stream.str().c_str();
        append(QString("Lato ")+letter[i]+QString(": ")+QString(c));
    }
}*/

void DataArea::outputPerimetro(double pp){
<<<<<<< HEAD
    std::stringstream stream;
    stream<<pp;
    const char* c=stream.str().c_str();
    append(QString("Perimetro = ")+QString(c));


=======
    QString s = QString::fromStdString(std::to_string(pp));
    QTextEdit::setText("Perimetro = " + s);
}

void DataArea::outputArea(double a){
    QString s = QString::fromStdString(std::to_string(a));
    QTextEdit::setText("Area = " + s);
}

void DataArea::outputAngoli(QVector<Angolo> a){
    QString letter("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    for(int i=0; i<a.size(); ++i){
        std::stringstream stream;
        stream<<a[i].getAngolo();
        const char* c=stream.str().c_str();
        append(QString("Angolo ")+letter[i]+QString(": ")+QString(c));
    }
}

void DataArea::outputLati(QVector<double> a){
    QString letter("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    for(int i=0; i<a.size(); ++i){
        std::stringstream stream;
        stream<<a[i];
        const char* c=stream.str().c_str();
        append(QString("Lato ")+letter[i]+QString(": ")+QString(c));
    }
>>>>>>> c7aa2213dddeda1d6e07d765ff1b521cd284a512
}
