
public class Use {

    public static void main(String[] args){
        Colore colore = new RGB(150,150,150);
        Colore colore1 = new RGB(70,20,12);
        Colore colore2 = new RGB(200,200,200);

        System.out.println("colore + colore1 = " + colore.somma(colore1).getHex());
        System.out.println("colore - colore1 = " + colore.sottrazione(colore1).getHex());
        System.out.println("colore * colore1 = " + colore.moltiplicazione(colore1).getHex());
        System.out.println("colore / colore1 = " + colore2.divisione(colore1).getHex());

        Poligono pentagono = new Pentagono(50d, colore1, "Pentagono");

        System.out.println("Coordinate di un pentagono regolare di lato 50");
        for(Punto p : pentagono.getCoordinate())
            System.out.println("x = " + p.getX() + " y = " + p.getY());

        System.out.println("Coordinate dello stesso pentagono specchiato");
        pentagono.specchia();
        for(Punto p : pentagono.getCoordinate())
            System.out.println("x = " + p.getX() + " y = " + p.getY());

        System.out.println("Area pentagono di lato 50 = " + pentagono.getArea());

        Poligono triangolo = new Triangolo(20d,20d, new Angolo(90d), colore, "t");
        Poligono quadrato = new Quadrato(20d, colore1, "q");

        Poligono risultato = triangolo.somma(quadrato);

        for (Punto p : risultato.getCoordinate())
            System.out.println("x = " + p.getX() + " y = " + p.getY());

        for (Punto p : quadrato.getCoordinate())
            System.out.println("x = " + p.getX() + " y = " + p.getY());


    }
}
