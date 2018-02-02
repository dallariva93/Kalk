import java.util.ArrayList;

public class Quadrilatero extends Poligono {

	public Quadrilatero(Double latoAB, Double latoBC, Double latoAD, Angolo a, Angolo b, Colore col, String nome) {
		super(4,nome,col,new ArrayList<Punto>());
		Angolo b_ad = new Angolo(180d - b.getAngolo());
		ArrayList<Punto> punti = new ArrayList<Punto>();
		punti.add(Punto.origine());
		punti.add(new Punto(latoAB, 0d));
		punti.add(new Punto(latoAB + (sen_cos(latoBC, b_ad).getX()), sen_cos(latoBC, b_ad).getY()));
		punti.add(sen_cos(latoAD, a));
		setPunti(punti);
	}

	public Quadrilatero(Double latoAB, Double latoBC, Double latoAD, Angolo a, Angolo b) {
		this(latoAB, latoBC, latoAD, a, b, new RGB(), "");
	}

	public Quadrilatero() {
		this(0d, 0d, 0d, new Angolo(), new Angolo(), new RGB(), "");
	}

	public Double getArea() {
		Triangolo t1 = new Triangolo(getLati().get(0), getLati().get(1), Punto.distanceTo(getCoordinate().get(0), getCoordinate().get(2)));
		Triangolo t2 = new Triangolo(Punto.distanceTo(getCoordinate().get(0), getCoordinate().get(2)), getLati().get(2), getLati().get(3));
		return t1.getArea() + t2.getArea();
	}

	public void estendi(Double fattore) {
		Quadrilatero temp = new Quadrilatero(getLati().get(0) * fattore, getLati().get(1) * fattore, getLati().get(3) * fattore, getAngoli().get(0), getAngoli().get(1));
		setPunti(temp.getCoordinate());
	}

	public Quadrilatero zoom(Double fattore) {
		return new Quadrilatero(getLati().get(0) * fattore, getLati().get(1) * fattore, getLati().get(3) * fattore, getAngoli().get(0), getAngoli().get(1));
	}

	public Quadrilatero cambiaBase(Integer n) {
		ArrayList<Double> lati = ordinaLati(getLati(), getLati().get(n));
		return new Quadrilatero(lati.get(0), lati.get(1), lati.get(3), getAngoli().get(0), getAngoli().get(1), getColore(), "");
	}

	public Quadrilatero specchia() {
		ArrayList<Punto> vertici = getCoordinate();
		for (int i = 0; i < vertici.size(); ++i)
			vertici.get(i).invertiY();
		Quadrilatero q = new Quadrilatero();
		q = this;
		q.setPunti(vertici);
		return q;
	}


	public Poligono unisci(Poligono pol) throws Eccezione {
	    Colore col = this.getColore().somma(pol.getColore());
	    ArrayList<Punto> coord = new ArrayList<Punto>();
	    boolean piatto=false;	    
	    if(! ((this.getAngoli().get(0)).angPiatto( pol.getAngoli().get(0) ) ) ){
	        coord.add(Punto.origine());    //angolo != da 180
	        piatto=true;
	    }	    
	    for(int i = pol.getCoordinate().size()-1; i>1; --i)
	        coord.add( pol.getCoordinate().get(i));	    
	    if(! ( getAngoli().get(1).angPiatto(pol.getAngoli().get(1)) ) )
	        coord.add( getCoordinate().get(1));
	    coord.add( getCoordinate().get(2));
	    if(piatto)      coord.add( getCoordinate().get(3));
	    else            coord.add( 0, getCoordinate().get(3));
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
		Quadrilatero q = cambiaBase(indice);
		Integer index = pol.indexLato(lato);
		Poligono p1 = pol.cambiaBase(index);
		p1 = p1.specchia();
		Poligono poligono = this;
		try {
			poligono =  q.unisci(p1);
		}
		catch(Eccezione e) {
			System.out.println ("Somma non disponibile con più di 5 lati");
			System.exit(0);
		}
		poligono.ruota(p1.getAngoli().get(0));
		return poligono;
	}

	public void gira(){
	    Angolo b_ad = new Angolo( 180d - getAngoli().get(2).getAngolo() );
	    ArrayList<Punto> punti = new ArrayList<Punto>();
	    punti.add(Punto.origine());
	    punti.add(new Punto( getLati().get(1) , 0.0 ) );
	    punti.add(new Punto( getLati().get(1) + sen_cos(getLati().get(2), b_ad).getX() ,
	                            sen_cos(getLati().get(2),b_ad).getY() ));
	    punti.add(sen_cos(getLati().get(0),getAngoli().get(1)));
	    setPunti(punti);
	}
	
}


