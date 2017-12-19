#ifndef PENTAGONOREGOLARE_H
#define PENTAGONOREGOLARE_H
#include "pentagono.h"

class PentagonoRegolare : public Pentagono{
private:
    static const Angolo angoloInterno;

public:
    PentagonoRegolare(double, Colore* col=new RGB());
};

#endif // PENTAGONOREGOLARE_H
