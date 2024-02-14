import java.awt.*;

public class Circle extends ShapeElement{
    public int x, y, a, b;

    public Circle(int x_start, int y_start, int abs, int abs1) {
        x = x_start;
        y = y_start;
        a = abs;
        b = abs1;
    }

    @Override
    public void MoveTo(int dx, int dy) {
        x += dx;
        y += dy;
    }

    @Override
    public void Bigger() {
        a++;
        b++;
    }

    @Override
    public void Smaller() {
        a--;
        b--;
    }

    @Override
    public void Draw(Graphics2D g) {
        super.Draw(g);
        g.drawOval(x, y, a, a);
    }
}
