
public class RGB extends Colore{

	private int r = 255;
	private int g = 255;
	private int b = 255;
//    static unsigned int* HexToRGB(const Colore &col);
	
	public RGB(int r, int g, int b) {
		this.r = r;
		this.g = g;
		this.b = b;
	}
	public RGB() {
		this(255,255,255);
	}
	public int getR() {
		return r;
	}
	public int getG() {
		return g;
	}
	public int getB() {
		return b;
	}
 /*   static String decToHex(int value) {
        std::stringstream stream;
        stream << std::hex << value;
        QString hex;
        hex=QString::fromStdString(stream.str());
        if(value<16) hex="0"+hex;
        return hex;
    }
	public String getHex() {
	    String red = decToHex(r);
	    String green = decToHex(g);
	    String blue = decToHex(b);
	    if(red=="0") red = "00";
	    if(green=="0") green = "00";
	    if(blue=="0") blue = "00";
	    return new String("#" + red + green + blue);
	}*/

    
	/*
	RGB* clone() const;
    RGB& operator+(const Colore&)const;
    RGB& operator-(const Colore&)const;
    RGB& operator*(const Colore&)const;
    RGB& operator/(const Colore&)const;

*/
}
