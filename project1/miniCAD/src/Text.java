import java.awt.*;

public class Text extends ShapeElement{
    public float x, y;
    public String textcontent;
    public Font font;
    public FontMetrics fontMetrics = null;
    public int TextSize = 30;
    public Text(int x, int y, String textcontent) {
        font = new Font("Arial", Font.BOLD, 25);
        this.x = x;
        this.y = y;
        this.textcontent = textcontent;
    }
    public void Draw(Graphics2D g) {
        super.Draw(g);
        fontMetrics = g.getFontMetrics(font);
        Font tf;
        if(beSelected) {
            tf = new Font("Arial", Font.BOLD, TextSize);
            g.setFont(tf);
        }
        else g.setFont(font);
        g.drawString(this.textcontent, x, y);
    }
    @Override
    public void MoveTo(int dx, int dy) {
        x += dx;
        y += dy;
    }

    @Override
    public void Bigger() {
        font = new Font("Arial", Font.BOLD, TextSize++);
    }

    @Override
    public void Smaller() {
        font = new Font("Arial", Font.BOLD, TextSize--);
    }
}
