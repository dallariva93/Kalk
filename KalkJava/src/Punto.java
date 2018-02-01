import java.lang.Math;

public class Punto {

    public double x;
    public double y;
	
    public Punto(double x, double y){
        this.x = x;
        this.y = y;
    }
    public Punto(){
    	this(0,0);
    }
    public double getX() {
    	return x;
    }
    public double getY() {
    	return y;
    }
    public void invertiY() {
    	y = -y;
    }
	public static double distanceTo(Punto a,  Punto b) {
		 return Math.sqrt(
	                Math.pow((b.getX()-a.getX()),2)+
	                Math.pow((b.getY()-a.getY()),2)
	            );
	}
	public static Angolo angoloTraTrePunti(Punto C,  Punto A,  Punto B) {
	    double latoAB = distanceTo(A,B);
	    double latoBC = distanceTo(B,C);
	    double latoAC = distanceTo(A,C);
	    double cos_a =(( Math.pow(latoAC,2) + Math.pow(latoAB,2) - Math.pow(latoBC,2)) / (2*latoAB*latoAC)) ;
	    return new Angolo( Math.acos(cos_a) *180/Math.PI );
	}
	public static final Punto origine(){	//
		return new Punto();
	}
}
/*
 * 
 * class Point{
    public double x;
    public double y;



    public Point add(Point other){
        this.x += other.x;
        this.y += other.y;
        return this;
    }
    public Point add(Point other) {
        return of(x+other.x, y+other.y);
    }
    }
 */