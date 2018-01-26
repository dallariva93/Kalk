#ifndef POLIGONO_H
#define POLIGONO_H
#include <QVector>
#include "punto.h"
#include "colore.h"
#include "rgb.h"
#include <QPolygon>

class Poligono{
private:
    unsigned int numeroLati;
    Colore* color;
    QString nomeOggetto;
    QVector<Punto> coordinate;

public:
    Poligono(unsigned int, QString, Colore*, QVector<Punto> punti=QVector<Punto>());
    QString getNome()const;
    virtual double getArea() const =0;
    virtual double getPerimetro() const;
    virtual void estendi(double) =0;
    virtual Poligono& zoom(double) const=0;
    virtual Poligono& cambiaBase(int) const =0;
    virtual Colore* getColore() const;
    void setColore(Colore*);    //void setColore(const Colore *); da errore non  capisco perchè!!
    void changeColor(Colore &);  //vedere se unire con setColore
    QVector<Angolo> getAngoli() const;
    void setPunti(const QVector<Punto>);
    QVector<Punto> getCoordinate() const;
    QVector<double> getLati() const;
    void ruota(Angolo angolo);
    static QVector<double> ordinaLati(QVector<double> lati, double lato);     //dato un lato mette gli altri in successione mantenendo
                                                                              //l'ordine es: input lati= 3 5 7 4 lato=7, output=7 4 3 5
    static Punto sen_cos(double, Angolo);
    double latoComune(const Poligono&) const;
    virtual Poligono& specchia()const =0;
    virtual Poligono& operator+(const Poligono&) const=0;
    int indexLato(double)const;

    QPolygonF toQPolygon();
};

#endif // POLIGONO_H
