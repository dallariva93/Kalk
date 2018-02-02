import java.util.*;

public abstract class Poligono {

    private Integer numeroLati;
	private String nomeOggetto;
	private Colore color = new RGB();
	private ArrayList<Punto> coordinate = new ArrayList<Punto>();	//val di default
	
	public Poligono(Integer n, String nome, Colore col, ArrayList<Punto> punti) {	//costruttore a 3parametri
        numeroLati = n;
		nomeOggetto = nome;
		color = col;
		coordinate = punti;
	}
	public Poligono() {
		this(0,"Poligono", new RGB(),new ArrayList<Punto>());
	}
    public Poligono(Poligono p){
	    nomeOggetto=p.nomeOggetto;
	    color=p.color;
	    coordinate=p.coordinate;
    }
    abstract public Double getArea();
    abstract public void estendi(Double e);
    abstract public Poligono zoom(Double z);
    abstract public Poligono cambiaBase(Integer i);
    abstract public Poligono specchia();
	public String getNome() {
		return nomeOggetto;
	}
    public void setNome(String s) {
        nomeOggetto = s;
    }
    public Double getPerimetro() {
        Double perimetro = 0d;
        for(int i=0; i<numeroLati; ++i) perimetro += getLati().get(i);
        return perimetro;
    }
    public Colore getColore() {
        return color;
    }
    public void setColore(Colore c) {
        color = c;
    }
    public void changeColor(Colore c) {
		color.somma(c);
    }
    public ArrayList getAngoli() {
        ArrayList<Punto> punti=getCoordinate();
        ArrayList<Angolo> angoli = new ArrayList<Angolo>();
        angoli.add(Punto.angoloTraTrePunti(punti.get(punti.size()-1), punti.get(0), punti.get(1)));
        for(int i=0; i<punti.size()-2; ++i){
            angoli.add(Punto.angoloTraTrePunti(punti.get(i), punti.get(i+1), punti.get(i+2)));
        }
        angoli.add(Punto.angoloTraTrePunti(punti.get(punti.size()-2), punti.get(punti.size()-1), punti.get(0)));
        return angoli;
    }
    public void setPunti(ArrayList c) {
        coordinate = c;
    }
    public ArrayList<Punto> getCoordinate() {
        return new ArrayList<Punto>(coordinate);
    }
    public ArrayList<Double> getLati() {
    	ArrayList<Double> lati = new ArrayList();
        for(int i=0; i<numeroLati-1; ++i){
            lati.add(Punto.distanceTo(coordinate.get(i), coordinate.get(i+1)));
        }
        lati.add(Punto.distanceTo(coordinate.get(0), coordinate.get(coordinate.size()-1)));
        return lati;
    }
    public Punto sen_cos(Double lato, Angolo a) {
        Double x, y;
        if(a.getAngolo() != 90){
            x = lato * a.coseno();
            y = lato * a.seno();
        } else {
            x = 0d;
            y = lato;
        }
       return new Punto( x,y );
    }
    
    public ArrayList<Double> ordinaLati(ArrayList<Double> lati, Integer lato){
        ArrayList<Double> supporto = new ArrayList<Double>();
        Integer index = lati.indexOf(lato);
        if(index == 0) return lati;   //poggia già sulla base giusta
        
//        supporto = lati.(index);
//        supporto+=lati.mid(0,index);																			//DA FAREE
        return supporto;
    }
    
    public Double latoComune(Poligono p) {
        boolean latoUguale = false;
        Double lato = 0.0;
        for( int i=0; i<numeroLati && !latoUguale; ++i){
            for( int j=0; j<p.numeroLati && !latoUguale; ++j){
                if( getLati().get(i) == p.getLati().get(j) ){
                    lato = p.getLati().get(j);
                    latoUguale = true;
                }
            }
        }
        return lato;
    }

	Integer indexLato(Double lato) {
	    ArrayList<Double> lati = getLati();
	    Integer index = lati.indexOf(lato);
	    return index;
	}
	
	public void ruota(Angolo angolo){
	    Double min=-0.01, max=0.01;
	    ArrayList<Punto> vertici = getCoordinate();
	    for(int i = 0; i<vertici.size(); ++i){
		    Double x = (vertici.get(i).getX() * angolo.coseno()) + (vertici.get(i).getY() * angolo.seno());
		    if(min<x && x<max)  x=0.0;    //per pb. macchina
	        double y = ((vertici.get(i).getX())*angolo.seno()) - (vertici.get(i).getY()*angolo.coseno());
	        if(min<y && y<max)  y=0;    //per pb. macchina
	    }
	    double cosAngoloCorretto;
	    if(angolo.getAngolo()==90) cosAngoloCorretto=0;
	    else	cosAngoloCorretto=angolo.coseno();
	    for(int i = 0; i<vertici.size(); ++i){
	        Double x = (vertici.get(i).getX() * cosAngoloCorretto) - (vertici.get(i).getY() * angolo.seno());
	        if(min<x && x<max)  x=0.0;    //per pb. macchina
	        Double y = ((vertici.get(i).getX())*angolo.seno()) + (vertici.get(i).getY()*cosAngoloCorretto);
	        if(min<y && y<max)  y=0.0;    //per pb. macchina
	        //  *(it)=Punto(x,y);
	    }
	    setPunti(vertici);
	}
    public static void main(String[] args){
	    Colore colore=new RGB(5,5,5);
	    Colore colore1=new RGB(120,120,120);
	    System.out.println(colore.getHex());

    } 

}

