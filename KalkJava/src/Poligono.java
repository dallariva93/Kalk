//package Poligono;

import java.util.*;

public abstract class Poligono {

    private int numeroLati;
	private String nomeOggetto;
	private Colore color = new RGB();
	private ArrayList<Punto> coordinate = new <Punto>();	//val di default
	
	public Poligono(String nome, Colore col, ArrayList<Punto> punti) {	//costruttore a 3parametri
		nomeOggetto = nome;
		color = col;			// clone
		coordinate = punti;
	}
	public Poligono() {
		this("Unknown", new RGB(),new ArrayList<Punto>());
	}
    public Poligono(Poligono p){
	    nomeOggetto=p.nomeOggetto;
	    color=p.color;
	    coordinate=p.coordinate;
    }

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
//    public ArrayList getAngoli() {}
    public void setPunti(ArrayList c) {
    	coordinate = c;
    }
    public ArrayList<Punto> getCoordinate() {
    	return new ArrayList<Punto>(coordinate);
    }
    public ArrayList getLati() {
    	ArrayList lati = new ArrayList();
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
