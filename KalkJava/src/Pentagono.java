import java.util.ArrayList;

public class Pentagono extends Poligono {
    public Pentagono(String nome, Colore col, ArrayList<Punto> punti) {
        super(5, nome, col, punti);
    }

    public Pentagono(Double latoAB, Double latoBC, Double latoDE, Double latoAE, Angolo a, Angolo b, Angolo e, Colore col, String nome) {
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

    public Pentagono(Pentagono pent){
        super(5,pent.getNome(),pent.getColore(), pent.getCoordinate());
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
        return new Pentagono(lati.get(0), lati.get(1), lati.get(3), lati.get(4), getAngoli().get(0), getAngoli().get(1), getAngoli().get(2), getColore(), getNome());
    }

    @Override
    public Poligono specchia() {
        ArrayList<Punto> vertici = getCoordinate();
        for(Punto aux : vertici)
            aux.invertiY();
        Pentagono specchiato = new Pentagono(this);
        specchiato.setPunti(vertici);
        return specchiato;

    }
}