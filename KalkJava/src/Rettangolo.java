
public class Rettangolo extends Quadrilatero {

    public Rettangolo(Double latoAB, Double latoBC, Colore col, String nome){
        super(latoAB, latoBC, latoAB,Angolo.angoloRetto, Angolo.angoloRetto, col, nome);
    }



    @Override
    public Double getArea() {
        return getLati().get(0)*getLati().get(1);
    }

    @Override
    public Double getPerimetro() {
        return (getLati().get(0)+getLati().get(1))*2;
    }


}
