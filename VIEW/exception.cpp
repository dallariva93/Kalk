#include "exception.h"
#include <QLabel>

MyException::MyException(QString text, QString titolo){

    box = new QMessageBox(QMessageBox::Warning,titolo,text);
    box->show();
}

EmptyField::EmptyField(QString text):MyException(text){}

SyntaxError::SyntaxError(QString text):MyException(text){}

AlreadyPresent::AlreadyPresent(QString text):MyException(text){}

WrongPolygon::WrongPolygon(QString text):MyException(text){}
