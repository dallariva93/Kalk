#ifndef POLIGONO_H
#define POLIGONO_H
#include <QVector>
#include "punto.h"
#include "colore.h"
#include "rgb.h"

class Poligono{
private:
    unsigned int numeroLati;
    Colore* color;
    std::string nomeOggetto;
    QVector<Punto> coordinate;


public:
    Poligono(unsigned int, std::string, Colore*, QVector<Punto> punti=QVector<Punto>());
    virtual double getArea() const =0;
    virtual double getPerimetro() const;
    virtual void estendi(double)=0;       //meglio farla pura? da pensarci
    virtual void ruotaSuUnLato(double)=0;         //cambia la base nuova base=lato (parametro)
    virtual Colore* getColore() const;
    QVector<Angolo> getAngoli()const;
    void setPunti(const QVector<Punto>);
    QVector<Punto> getCoordinate() const;
    QVector<double> getLati() const;
    void ruota();

    static QVector<double> ordinaLati(QVector<double> lati, double lato);     //dato un lato mette gli altri in successione mantenendo
                                                                              //l'ordine es: input lati= 3 5 7 4 lato=7, output=7 4 3 5
    static Punto sen_cos(double, Angolo);

};

#endif // POLIGONO_H
