import java.util.*;

public class Triangolo extends Poligono {

	public Triangolo(double latoAB, double latoAC, Angolo a, Colore col, String nome){
		super(3, nome, col, new ArrayList<Punto>());
		ArrayList<Punto> punti = new ArrayList<Punto>();
	    punti.add(Punto.origine());
	    punti.add(new Punto(latoAB,0));
	    punti.add(sen_cos(latoAC,a));
	    setPunti(punti);	
	}
	public Triangolo(double latoAB, Angolo a, Angolo b, Colore col, String nome ){
		super(3, nome, col,  new ArrayList<Punto>());
		ArrayList<Punto> punti = new ArrayList<Punto>();
	    Angolo c = new Angolo( 180 -a.getAngolo() -b.getAngolo());
	    punti.add(Punto.origine());
	    punti.add(new Punto(latoAB,0));
	    double latoAC = ( latoAB * b.seno() ) / c.seno();
	    punti.add(sen_cos(latoAC, a));
	    setPunti(punti);		
	}
	public Triangolo(double latoAB, double latoBC, double latoAC, Colore col, String nome ){
		super(3, nome, col,  new ArrayList<Punto>());
		double cos_a =(( Math.pow(latoAC,2) + Math.pow(latoAB,2) - Math.pow(latoBC,2)) / (2*latoAB*latoAC)) ;
	    Angolo a = new Angolo( Math.acos(cos_a)*180/Math.PI );
		ArrayList<Punto> punti = new ArrayList<Punto>();
	    punti.add(Punto.origine());
	    punti.add(new Punto(latoAB,0));
	    punti.add(sen_cos(latoAC,a));
	    setPunti(punti);
	}	
	Triangolo(){
		this(10.0,10.0,10.0, new RGB(),"triangolo");
	}
	public Triangolo clone() {
		Triangolo t = new Triangolo();
		t = this;
	    return t;
	}
	public Double getAltezza() {
	    return Punto.distanceTo( getCoordinate().get(2) , new Punto( getCoordinate().get(2).getX() , 0.0 ) );
	}
	public Double getArea() {
	    double p = this.getPerimetro()/2;
	    return Math.sqrt( p* (p - (this.getLati().get(0))) * (p - this.getLati().get(1)) * (p - this.getLati().get(2)));
	}	
	public void estendi(Double fattore){
	    Triangolo temp = new Triangolo(getLati().get(0)*fattore, getLati().get(1)*fattore, getLati().get(2)*fattore, new RGB(), "Triangolo");
	    setPunti(temp.getCoordinate());
	}
	public Triangolo zoom(Double fattore) {
		return new Triangolo( (fattore*(this.getLati().get(0))) , (fattore*(this.getLati().get(1))) , (fattore*(this.getLati().get(2))), new RGB(), "triangolo");
	}	
	public Poligono cambiaBase(Integer i) {
		ArrayList<Double> lati = new ArrayList<Double>();
	    //lati = ordinaLati(this.getLati() , this.getLati().get(i));									//FARE ORDINALATI
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

	public Poligono unisci(Poligono pol){
		Colore col = this.getColore().somma(pol.getColore());
	   
	    ArrayList<Punto> coord;
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
	    else{   //coord.size()>5
	        throw("poligonoConPi�Di5Lati"); //sar� una eccezione
	    }
	}
	
	Poligono somma(Poligono pol) {
	    Double lato = latoComune(pol);
	    Integer indice = indexLato(lato);
	    Triangolo t1 = cambiaBase(indice);		//sistemare ordinalati
	    Integer index = pol.indexLato(lato);
	    Poligono p1 = pol.cambiaBase(index);
	    p1 = p1.specchia();
	    Poligono poligono = t1.unisci(p1); //garbage
	    poligono.ruota(p1.getAngoli().get(0));
	    return poligono;
	}
	
	public static void main(String[] args) {
		Triangolo t = new Triangolo(10.0,10.0,10.0,new RGB(),"triangolo");
		//System.out.println(t.getLati().get(0));
		//System.out.println(t.getCoordinate().get(2).getX());
		//System.out.println(t.getPerimetro());
	
	}

}


