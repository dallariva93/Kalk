import java.lang.Math;

public class Angolo {

	private Double gradi;
	final static Angolo angoloRetto = new Angolo(90d);    //costante

	public Angolo(Angolo a) {
		gradi = a.gradi;
	}

	public Angolo(Double val) {
		gradi = val;
	}

	public Angolo() {
		this(0.0);
	}

	public Double getAngolo() {
		return gradi;
	}

	public boolean maggiore(Angolo a) {    //verificare
		if (gradi > a.gradi) return true;
		else return false;
	}

	public boolean minore(Angolo a) {
		if (gradi < a.gradi) return true;
		else return false;
	}

	public boolean equals(Angolo a) {    //ridefinizioine di ==		//il != teniamo !equals
		if (gradi == a.gradi) return true;
		else return false;
	}

	public boolean angPiatto(Angolo a) {

		Double min = 179.9;
		Double max = 180.02;
		Double val = 0d;    //per pb. macchina

		val = a.gradi + gradi;
		return (min < val && val < max);
	}

	public Angolo plus(Angolo ang) {        //operatore di somma degi angoli
		return new Angolo(gradi + ang.gradi);
	}

	public Double coseno() {
		Double coseno = Math.cos(getAngolo() * Math.PI / 180);
		if (-0.01 < coseno && coseno < 0.01) coseno = 0d;
		return coseno;
	}

	public Double seno() {
		Double seno = Math.sin(getAngolo() * Math.PI / 180);
		if (-0.01 < seno && seno < 0.01)   //per pb. macchina
			seno = 0d;
		return seno;
	}

	public static void main(String[] args) {

	}
}
