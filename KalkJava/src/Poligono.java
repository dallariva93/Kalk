//package Poligono;

import java.util.*;

public abstract class Poligono {

	private int numeroLati;
	private String nomeOggetto;
	private Colore color = new RGB();
	private Vector<Punto> coordinate = new Vector<Punto>();	//val di default
	
	public Poligono(int nLati, String nome, Colore col, Vector<Punto> punti) {	//costruttore a 4 parametri
		numeroLati = nLati;
		nomeOggetto = nome;
		color = col;			// clone
		coordinate = punti;
	}
	public Poligono() {
		this(0,"Unknown", new RGB(),new Vector<Punto>());
	}
	// Poligonoclone() const=0;
	public String getNome() {
		return nomeOggetto;
	}
    public void setNome(String s) {
    	nomeOggetto = s;
    }
//    public double getArea() {}	//astratta
//    public double getPerimetro() {}
    public void estendi(double e) {}
//    public Poligono zoom(double z){}
//    public Poligono cambiaBase(Integer i){}
    public Colore getColore() {
    	return color;
    }
    public void setColore(Colore c) {
    	color = c;
    }
    public void changeColor(Colore c) {
    	//prima devo ridefinire operator +
		//color = color + c;	
    }
//    public Vector getAngoli() {}
    public void setPunti(Vector c) {
    	coordinate = c;
    }
    public Vector<Punto> getCoordinate() {
    	return new Vector<Punto>(coordinate);
    }
    public Vector getLati() {
    	Vector lati = new Vector();
        for(int i=0; i<numeroLati-1; ++i){
            //lati.push_back(Punto::distanceTo(coordinate[i], coordinate[i+1]));
        }
        //lati.push_back(Punto::distanceTo(coordinate.first(), coordinate.last()));
        return lati;
    }
    public Punto sen_cos(double lato, Angolo a) {
        double x=0, y=0;
        if(a.getAngolo() != 90){
            x = lato * a.coseno();
            y = lato * a.seno();
        } else {
            x = 0;
            y = lato;
        }
       return new Punto( x,y );
    }
    public static void main(String[] args){
	    Colore colore=new RGB(5,5,5);
	    Colore colore1=new RGB(120,120,120);
	    System.out.println(colore.getHex());



    }
}
