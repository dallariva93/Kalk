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
    public Pentagono() {
    	this(0d, 0d, 0d, 0d, new Angolo(), new Angolo(), new Angolo(), new RGB(), "");
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
    public Pentagono cambiaBase(Integer n) {
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
    
    public Poligono unisci(Poligono pol) throws Eccezione {
    	Colore col = this.getColore().somma(pol.getColore());
  	    ArrayList<Punto> coord = new ArrayList<Punto>();    
	    if(! ((this.getAngoli().get(0)).angPiatto( pol.getAngoli().get(0) ) ) ){
	        coord.add(Punto.origine());    //angolo != da 180
	    }	    
	    for(int i = pol.getCoordinate().size()-1; i>1; --i)
	        coord.add( pol.getCoordinate().get(i));	    
	    if(! ( getAngoli().get(1).angPiatto(pol.getAngoli().get(1)) ) )
	        coord.add( getCoordinate().get(1));
	    for(int i=2; i<pol.getCoordinate().size(); ++i)
    		coord.add( getCoordinate().get(i));
        if(coord.size() == 3){
            Triangolo t = new Triangolo();
            t.setPunti(coord);
            t.setColore(col);
            return t;
        }
        else if(coord.size() == 4){
            Quadrilatero q = new Quadrilatero();
            q.setPunti(coord);
            q.setColore(col);
            return q;
        }
        else if(coord.size() == 5){
            Pentagono p = new Pentagono();
            p.setPunti(coord);
            p.setColore(col);
            return p;
        }
        else{
	        throw new Eccezione();
        }
    }
    
    public Poligono somma(Poligono pol) {
        Double lato = latoComune(pol);
        Integer indice = indexLato(lato);
        Pentagono q = cambiaBase(indice);
        Integer index = pol.indexLato(lato);
        Poligono p = pol.cambiaBase(index);
        p = p.specchia();
        Poligono poligono = q.unisci(p);
        poligono.ruota(p.getAngoli().get(0));
        return poligono;
    }

    public void gira(){
        ArrayList<Punto> punti = new ArrayList<Punto>();
        punti.add(Punto.origine());
        punti.add(new Punto(getLati().get(1), 0.0) );
        Angolo b2 = new Angolo( 180d - getAngoli().get(2).getAngolo() );
        Triangolo t1 = new Triangolo(getLati().get(1), getLati().get(2), b2);
        punti.add(new Punto(  (punti.get(1).getX()+(getLati().get(2)*b2.coseno())), (getLati().get(2)*b2.seno())));
        Triangolo t2 = new Triangolo(getLati().get(0), getLati().get(4), getAngoli().get(0));
        Double latoAD = t2.getLati().get(1);
        Angolo beta = t2.getAngoli().get(1);
        Angolo gamma = new Angolo((getAngoli().get(1)).getAngolo() - beta.getAngolo());
        punti.add( sen_cos(latoAD,gamma) );
        punti.add( sen_cos(getLati().get(0),getAngoli().get(1)) );
        setPunti(punti);
    }
    
}