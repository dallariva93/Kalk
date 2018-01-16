#include "dataarea.h"
#include <sstream>
#include<QChar>
DataArea::DataArea(){
    setReadOnly(true);
    QSize size(200,250);
    setMinimumSize(size);
    setMaximumSize(size);
    setStyleSheet("border: 1px solid grey; background-color: white;");
}

void DataArea::setText(QVector<double> lati){
    QString letter("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    for(int i=0; i<lati.size(); ++i){
        std::stringstream stream;
        stream<<lati[i];
        const char* c=stream.str().c_str();
        append(QString("Lato ")+letter[i]+QString(": ")+QString(c));
    }
}

void DataArea::outputPerimetro(double pp){
    std::stringstream stream;
    stream<<pp;
    const char* c=stream.str().c_str();
    append(QString("Perimetro = ")+QString(c));
}
