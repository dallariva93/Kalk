import java.util.ArrayList

public class Pentagono extends Poligono {
    public Pentagono(String nome, Colore col, ArrayList<Punto> punti) {
        super(5, nome, col, punti);
    }

    Pentagono(Double latoAB, Double latoBC, Double latoDE, Double latoAE, Angolo a, Angolo b, Angolo e, Colore col, String nome) {
        super(5, nome, col, new ArrayList<Punto>());

        ArrayList<Punto> punti = new ArrayList<>();
        punti.add(Punto.origine());    //coordinata A
        punti.add(new Punto(latoAB, 0d));   //coordinata B

        Angolo b2 = new Angolo(180 - b.getAngolo());
        Triangolo t1 = new Triangolo(latoAB, latoBC, b2);
        punti.add(new Punto(punti.get(1).getX() + (latoBC * b2.coseno()), latoBC * b2.seno()));
        Triangolo t2 = new Triangolo(latoAE, latoDE, e);
        Double latoAD = t2.getLati().get(1);
        ArrayList<Angolo> arl = t2.getAngoli();
        Angolo beta = new Angolo(arl.get(1));
        Angolo gamma = new Angolo(a.getAngolo() - beta.getAngolo());
        punti.add(sen_cos(latoAD, gamma));    //coordinata D
        punti.add(sen_cos(latoAE, a));    //coordinata E
        setPunti(punti);
    }

    @Override
    public Double getArea() {
        Triangolo t1 = new Triangolo(getLati().get(0), getLati().get(1), Punto.distanceTo(getCoordinate().get(0),getCoordinate().get(2)));
        Triangolo t2 = new Triangolo(getLati().get(2), Punto.distanceTo(getCoordinate().get(0),getCoordinate().get(2)), Punto.distanceTo(getCoordinate().get(0),getCoordinate().get(3)));
        Triangolo t3 = new Triangolo(getLati().get(3), getLati().get(4), Punto.distanceTo(getCoordinate().get(0),getCoordinate().get(3)));


        return t1.getArea()+t2.getArea()+t3.getArea();
    }

    @Override
    public void estendi(Double fattore) {
        Pentagono  p = new Pentagono(getLati().get(0)*fattore, getLati().get(1)*fattore, getLati().get(3)*fattore, getLati().get(4)*fattore, getAngoli().get(0), getAngoli().get(1), getAngoli().get(4), new RGB(), "");
        setPunti(p.getCoordinate());

    }

    @Override
    public Poligono zoom(Double fattore) {
        return new Pentagono(getLati().get(0)*fattore, getLati().get(1)*fattore, getLati().get(3)*fattore, getLati().get(4)*fattore,
                getAngoli().get(0), getAngoli().get(1), getAngoli().get(4), new RGB(), "");
    }

    @Override
    public Poligono cambiaBase(Integer n) {
        ArrayList<Double> lati = ordinaLati(getLati(),getLati().get(n));


        QVector<double> lati=ordinaLati(getLati(),getLati()[n]);
        return *(new Pentagono(lati[0], lati[1], lati[3], lati[4], getAngoli()[0], getAngoli()[1], getAngoli()[2],getColore()));
    }

    @Override
    public Poligono specchia() {
        return null;
    }
}