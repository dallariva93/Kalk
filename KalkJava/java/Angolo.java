import java.lang.Math;

public class Angolo extends Poligono{

	private double gradi;
	final static double angoloRetto = 90;	//costante
	
	public Angolo(double val){
		gradi = val;
	}
	public double getAngolo() {
	    return gradi;
	}
	public boolean compareTo(Angolo a){	//verificare
	   	if( gradi > a.gradi) return true;
	    else 	return false;	    	
	}
/*	public boolean compareTo(Angolo a){
	    if( gradi < a.gradi)	return true;
	    else	return false;
	}*/
	public boolean equals(Angolo a){	//ridefinizioine di ==		//il != teniamo !equals
		if( gradi == a.gradi ) return true;
		else return false;
	}
	public boolean angPiatto(Angolo a){
	    double min = 179.9, max = 180.02, val=0;    //per pb. macchina
	    val = a.gradi+gradi;
	    return ( min < val && val < max );
	}
	public Angolo plus(Angolo ang){		//operatore di somma degi angoli
		return new Angolo( gradi + ang.gradi);
	}
	public double coseno(){
	    double coseno = Math.cos( getAngolo() * Math.PI/180);
	    if(-0.01<coseno && coseno<0.01)
	        coseno=0;
	    return coseno;
	}
	public double seno(){
	    double seno = Math.sin( getAngolo() * Math.PI/180);
	    if(-0.01<seno && seno<0.01)   //per pb. macchina
	        seno=0;
	    return seno;
	}
 /*
	public Angolo operator=(Angolo a){
		gradi = a.gradi;
		return this;
	}*/
}
/*  @Override public String toString() {
        return "("+x+", "+y+")";
    }*/