import java.util.ArrayList;

public class Quadrato extends Quadrilatero{

    public Quadrato (Double lato, Colore col, String nome){
        super(lato,lato,lato,Angolo.angoloRetto,Angolo.angoloRetto,col,nome);
    }
    public Quadrato(Double lato){
        this(lato, new RGB(), "");
    }
    public Quadrato(Quadrato quad){
        this(quad.getLati().get(0));
    }


    @Override
    public Double getArea() {
        return getLati().get(0)*getLati().get(0);
    }

    @Override
    public void estendi(Double e) {
        Quadrato quad= new Quadrato(getLati().get(0)*e);

    }

    @Override
    public Quadrato zoom(Double z) {
        return new Quadrato(getLati().get(0)*z);

    }

    @Override
    public Quadrilatero cambiaBase(Integer n) {
        return super.cambiaBase(n);
    }

    public Quadrato specchia(){
        ArrayList<Punto> vertici = getCoordinate();
        for(Punto p : vertici)
            p.invertiY();

        Quadrato specchiato = new Quadrato(this);
        specchiato.setPunti(vertici);
        return specchiato;


    }



}
