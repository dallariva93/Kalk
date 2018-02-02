
public class Quadrato extends Quadrilatero{

    public Quadrato (Double lato, Colore col, String nome){
        super(lato,lato,lato,Angolo.angoloRetto,Angolo.angoloRetto,col,nome);
    }


    @Override
    public Double getArea() {
        return lato*lato;
    }

    @Override
    public void estendi(Double e) {
        Quadrato quad= new Quadrato(getLati().get(0)*e);

    }

    @Override
    public Poligono zoom(Double z) {
        return null;
    }

    @Override
    public Poligono cambiaBase(Integer i) {
        return null;
    }

    @Override
    public Poligono specchia() {
        return null;
    }
}
