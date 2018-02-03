import java.util.*;

public class Triangolo extends Poligono {

	public Triangolo(Double latoAB, Double latoAC, Angolo a, Colore col, String nome){
		super(3, nome, col, new ArrayList<Punto>());
		ArrayList<Punto> punti = new ArrayList<Punto>();
	    punti.add(Punto.origine());
	    punti.add(new Punto(latoAB,0d));
	    punti.add(sen_cos(latoAC,a));
	    setPunti(punti);	
	}
	public Triangolo(Double latoAB, Double latoAC, Angolo a){
		this(latoAB,latoAC,a, new RGB(), "");
	}
	public Triangolo(Double latoAB, Angolo a, Angolo b, Colore col, String nome ){
		super(3, nome, col,  new ArrayList<Punto>());
		ArrayList<Punto> punti = new ArrayList<Punto>();
	    Angolo c = new Angolo( 180 -a.getAngolo() -b.getAngolo());
	    punti.add(Punto.origine());
	    punti.add(new Punto(latoAB,0d));
	    Double latoAC = ( latoAB * b.seno() ) / c.seno();
	    punti.add(sen_cos(latoAC, a));
	    setPunti(punti);		
	}
	public Triangolo(Double latoAB, Angolo a, Angolo b){
		this(latoAB, a, b, new RGB(), "");
	}
	
	public Triangolo(Double latoAB, Double latoBC, Double latoAC, Colore col, String nome ){
		super(3, nome, col,  new ArrayList<Punto>());
		Double cos_a =(( Math.pow(latoAC,2) + Math.pow(latoAB,2) - Math.pow(latoBC,2)) / (2*latoAB*latoAC)) ;
	    Angolo a = new Angolo( Math.acos(cos_a)*180/Math.PI );
		ArrayList<Punto> punti = new ArrayList<Punto>();
	    punti.add(Punto.origine());
	    punti.add(new Punto(latoAB,0d));
	    punti.add(sen_cos(latoAC,a));
	    setPunti(punti);
	}
	public Triangolo(Double latoAB, Double latoBC, Double latoAC){
		this(latoAB,latoBC,latoAC, new RGB(), "");
	}

	Triangolo(){
		this(10.0,10.0,10.0, new RGB(),"triangolo");
	}
	public Double getAltezza() {
	    return Punto.distanceTo( getCoordinate().get(2) , new Punto( getCoordinate().get(2).getX() , 0.0 ) );
	}
	public Double getArea() {
	    Double p = this.getPerimetro()/2;
	    return Math.sqrt( p* (p - (this.getLati().get(0))) * (p - this.getLati().get(1)) * (p - this.getLati().get(2)));
	}	
	public void estendi(Double fattore){
	    Triangolo temp = new Triangolo(getLati().get(0)*fattore, getLati().get(1)*fattore, getLati().get(2)*fattore, new RGB(), "Triangolo");
	    setPunti(temp.getCoordinate());
	}
	public Triangolo zoom(Double fattore) {
		return new Triangolo( (fattore*(this.getLati().get(0))) , (fattore*(this.getLati().get(1))) , (fattore*(this.getLati().get(2))), new RGB(), "triangolo");
	}	
	public Triangolo cambiaBase(Integer i) {
		ArrayList<Double> lati = new ArrayList<Double>();
		lati.addAll(0, ordinaLati(this.getLati() , this.getLati().get(i)));									//FARE ORDINALATI
		return new Triangolo(lati.get(0), lati.get(1), lati.get(2), new RGB(), "Triangolo");
	}


	public Triangolo specchia() {			//da verificare
	    ArrayList<Punto> vertici = getCoordinate();
	    for(int i=0; i< vertici.size(); ++i)
	        vertici.get(i).invertiY();
	    Triangolo t = new Triangolo();
	    t = this;
	    t.setPunti(vertici);
	    return t;
	}

	public Poligono unisci(Poligono pol) throws Eccezione {
		Colore col = this.getColore().somma(pol.getColore());
	    ArrayList<Punto> coord = new ArrayList<Punto>();
	    boolean piatto=false;      //per riordinare i lati quando ho degli angoli piatti
	    if(! ((this.getAngoli().get(0)).angPiatto( pol.getAngoli().get(0) ) ) ){
	        coord.add(Punto.origine());    //angolo != da 180
	        piatto=true;
	    }
	    for(int i = pol.getCoordinate().size()-1; i>1; --i)
	        coord.add( pol.getCoordinate().get(i));
	    if(! ( getAngoli().get(1).angPiatto(pol.getAngoli().get(1)) ) )
	        coord.add( getCoordinate().get(1));
	    if(piatto)     coord.add( getCoordinate().get(2));
	    else            coord.add(0, getCoordinate().get(2));
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
	    Triangolo t1 = cambiaBase(indice);		
	    Integer index = pol.indexLato(lato);
	    Poligono p1 = pol.cambiaBase(index);
	    p1 = p1.specchia();
		Poligono poligono = this;
		try {
			poligono =  t1.unisci(p1);
		}
		catch(Eccezione e) {
			System.out.println ("Somma non disponibile con più di 5 lati");
			System.exit(0);
		}
		poligono.ruota(p1.getAngoli().get(0));
		return poligono;
	}


}


