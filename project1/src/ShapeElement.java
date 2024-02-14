import java.awt.*;

public abstract class ShapeElement {
    public boolean beSelected =false;
    public Color itsColor = Color.black;
    public float lineWidth = 1;
    public Stroke stroke;

    public void setItsColor(Color c) {
        itsColor = c;
    }
    public void Draw(Graphics2D g) {
        if(beSelected == true) {
            stroke = new BasicStroke(lineWidth + 5);
        }
        else stroke = new BasicStroke(lineWidth);
        g.setColor(itsColor);
        g.setStroke(stroke);
    }

    public abstract void MoveTo(int dx, int dy);
    public abstract void Bigger();
    public abstract void Smaller();


}
