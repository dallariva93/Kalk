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
}

void DataArea::outputSomma(QString somma){
    QTextEdit::setText("Somma colori = " + somma);
}

void DataArea::outputSottrazione(QString s){
    QTextEdit::setText("Sottrazione colori = " + s);
}

void DataArea::outputMoltiplicazione(QString s){
    QTextEdit::setText("Moltiplicazione colori = " + s);
}

void DataArea::outputDivisione(QString s){
    QTextEdit::setText("Divisione colori = " + s);
}
