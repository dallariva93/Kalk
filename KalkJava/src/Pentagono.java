import java.util.ArrayList;

public class Pentagono extends Poligono {
    public Pentagono(String nome, Colore col, ArrayList<Punto> punti) {
        super(nome, col, punti);
    }

    Pentagono(double latoAB, double latoBC, double latoCD, double latoDE, double latoAE,  Angolo a, Angolo b, Angolo c,
              Angolo d, Angolo e, Colore col, String nome) {

        super Poligono(5, nome,col, new ArrayList<Punto>());
        ArrayList<Punto> punti;
        punti.add(Punto.origine());    //coordinata A
        punti.add(new Punto(latoAB,0));   //coordinata B

        Angolo b2 = new Angolo(180 - b.getAngolo());
        Triangolo t1(latoAB, latoBC, b2);
        punti.add(Punto(  (punti[1].getX()+(latoBC*b2.coseno()))  ,   (latoBC*b2.seno())));
        Triangolo t2(latoAE, latoDE, e);
        double latoAD = t2.getLati()[1];
        Angolo beta = t2.getAngoli()[1];
        Angolo gamma = a.getAngolo() - beta.getAngolo();
        punti.push_back( sen_cos(latoAD,gamma) );    //coordinata D
        punti.push_back( sen_cos(latoAE,a) );    //coordinata E

    }
