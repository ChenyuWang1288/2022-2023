import java.awt.*;

public class Rectangle extends ShapeElement{
    public int x, y, length, height;
    public Rectangle(int x, int y, int length, int height) {
        this.x = x;
        this.y = y;
        this.length = length;
        this.height = height;
    }
    @Override
    public void MoveTo(int dx, int dy) {
        x += dx;
        y += dy;
    }

    @Override
    public void Bigger() {
        height *= 1.1;
        length *= 1.1;
    }

    @Override
    public void Smaller() {
        height *= 0.9;
        length *= 0.9;
    }


    @Override
    public void Draw(Graphics2D g) {
        super.Draw(g);
        g.drawRect(x, y, length, height);
    }
}
