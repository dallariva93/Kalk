import java.lang.Math;

public class Punto {

    public Double x;
    public Double y;
	
    public Punto(Double x, Double y){
        this.x = x;
        this.y = y;
    }
    public Punto(){
    	this(0,0);
    }
    public Double getX() {
    	return x;
    }
    public Double getY() {
    	return y;
    }
    public void invertiY() {
    	y = -y;
    }
	public static Double distanceTo(Punto a,  Punto b) {
		 return Math.sqrt(
	                Math.pow((b.getX()-a.getX()),2)+
	                Math.pow((b.getY()-a.getY()),2)
	            );
	}
	public static Angolo angoloTraTrePunti(Punto C,  Punto A,  Punto B) {
	    Double latoAB = distanceTo(A,B);
	    Double latoBC = distanceTo(B,C);
	    Double latoAC = distanceTo(A,C);
	    Double cos_a =(( Math.pow(latoAC,2) + Math.pow(latoAB,2) - Math.pow(latoBC,2)) / (2*latoAB*latoAC)) ;
	    return new Angolo( Math.acos(cos_a) *180/Math.PI );
	}
	public static final Punto origine(){	//
		return new Punto();
	}
}
