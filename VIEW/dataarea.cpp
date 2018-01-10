#include "dataarea.h"
#include <sstream>
#include<QChar>
DataArea::DataArea()
{
    setReadOnly(true);
    QSize size(200,250);
    setMinimumSize(size);
    setMaximumSize(size);
}

void DataArea::setText(QVector<double> lati)
{
    QString letter("ABCDE");
    for(int i=0; i<lati.size(); ++i)
    {
        std::stringstream stream;
        stream<<lati[i];
        const char* c=stream.str().c_str();
        append(QString("Lato ")+letter[i]+QString(": ")+QString(c));
    }
}

