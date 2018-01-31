import java.lang.Math;

public class Angolo{

	private double gradi;
	final static double angoloRetto = 90;	//costante
	
	public Angolo(double val){
		gradi = val;
	}
	public double getAngolo() {
	    return gradi;
	}
	public boolean maggiore(Angolo a){	//verificare
	   	if( gradi > a.gradi) return true;
	    else 	return false;	    	
	}
	public boolean minore(Angolo a){
	    if( gradi < a.gradi)	return true;
	    else	return false;
	}
	public boolean equals(Angolo a){	//ridefinizioine di ==		//il != teniamo !equals
		if( gradi == a.gradi ) return true;
		else return false;
	}
	public boolean angPiatto(Angolo a){
	    double min = 179.9, max = 180.02, val=0;    //per pb. macchina
	    val = a.gradi + gradi;
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
	public static void main(String[] args) {
		System.out.println(angoloRetto);
		Angolo x = new Angolo(90);
		Angolo y = new Angolo(90);
		Angolo z = new Angolo(20);
		Angolo j = new Angolo(160);
		// a = angoloRetto.seno();		//non posso		NOTA BENE
		double b = x.coseno();
		double a = x.seno();
		System.out.println(b+"  "+a);

		if(x.equals(y))	System.out.println("uguali");
		else		System.out.println("NON uguali");
	
		if(x.maggiore(z))	System.out.println(x.getAngolo()+" maggiore di "+z.getAngolo());
		else	System.out.println("minore di");
	
		if(z.angPiatto(j)) System.out.println("la somma fa 180");
		else   System.out.println("la somma NON fa 90");
			
		y = z;	System.out.println(y.getAngolo());		//non occorre ridefinire l'assegnazione tra angoli
	}
	*/
	/*	PROBLEMI
	 * - Non riesco ad usare angolo retto come un oggetto 
	 * */
}
