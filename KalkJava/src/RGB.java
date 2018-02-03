import static java.lang.Integer.toHexString;

public class RGB implements Colore {
    private Integer r;
    private Integer g;
    private Integer b;

    public RGB(Integer r, Integer g, Integer b){
        this.r=r;
        this.g=g;
        this.b=b;
    }
    public RGB(){
        this(255,255,255);
    }
    public int getR(){
        return r;
    }
    public int getB() {
        return b;
    }
    public int getG() {
        return g;
    }

    @Override
    public String getHex() {
        String rr=toHexString(r);
        String gg=toHexString(g);
        String bb=toHexString(b);

        if(r<14)
            rr="0"+rr;
        if(g<14)
            gg="0"+gg;
        if(b<14)
            bb="0"+bb;
        return "#" + rr + gg + bb;
    }

    @Override
    public Colore somma(Colore colore) {
        RGB s=(RGB)colore;
        r=(r+s.r)/2;
        g=(g+s.g)/2;
        b=(b+s.b)/2;
        return this;
    }

    @Override
    public Colore sottrazione(Colore colore) {
        RGB s=(RGB)colore;

        if((r-s.r)>0)r=(r-s.r);
        if((g-s.g)>0)g=(g-s.g);
        if((b-s.b)>0)b=(b-s.b);

        return this;
    }

    @Override
    public Colore moltiplicazione(Colore colore) {
        RGB c=(RGB)colore;
        r=(r*c.r)/255;
        g=(g*c.g)/255;
        b=(b*c.b)/255;

        return this;
    }

    @Override
    public Colore divisione(Colore colore) {
        RGB c=(RGB)colore;


        if (c.r == 0) {
            c.r = 1;
        }
        if (c.g == 0) {
            c.g = 1;
        }
        if (c.b == 0) {
            c.b = 1;
        }

        r=r/c.r;
        g=g/c.g;
        b=b/c.b;

        return this;
    }
}