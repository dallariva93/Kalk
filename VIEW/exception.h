#ifndef EXCEPTION_H
#define EXCEPTION_H
#include<QMessageBox>
#include<QException>
#include<exception>

class MyException : public std::exception
{
private:
    QMessageBox* box;
public:
    MyException(QString text="Errore", QString titolo="Errore");
    ~MyException();
};


class EmptyField : public MyException
{
public:
    EmptyField(QString text);
};


class SyntaxError : public MyException
{
public:
    SyntaxError(QString text);
};

class AlreadyPresent : public MyException
{
public:
    AlreadyPresent(QString text);
};


class WrongPolygon : public MyException
{
public:
    WrongPolygon(QString text);
};


#endif // EXCEPTION_H
