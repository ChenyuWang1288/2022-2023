import java.awt.*;

public class Line extends ShapeElement{
    public int x_start, y_start;
    public int x_end, y_end;
    public Line(int x_start, int y_start, int x_end, int y_end) {
        this.x_end = x_end;
        this.x_start = x_start;
        this.y_end = y_end;
        this.y_start = y_start;

    }

    @Override
    public void Draw(Graphics2D g) {
        super.Draw(g);
        g.drawLine((int) x_start, (int) y_start, (int) x_end, (int) y_end);
    }

    @Override
    public void MoveTo(int dx, int dy) {
        x_start += dx;
        y_start += dy;
        x_end += dx;
        y_end += dy;
    }

    @Override
    public void Bigger() {
        if(x_start == x_end ){
            if(y_start < y_end)
                y_end++;
            else
                y_start++;
        } else if (x_start < x_end) {
            x_end++;
            y_end += (y_end - y_start) / (x_end - x_start);
        } else {
            x_start++;
            y_start += (y_end - y_start) / (x_end - x_start);
        }
    }

    @Override
    public void Smaller() {
        if(x_start == x_end ){
            if(y_start < y_end)
                y_end--;
            else
                y_start--;
        } else if (x_start < x_end) {
            x_end--;
            y_end -= (y_end - y_start) / (x_end - x_start);
        } else {
            x_start--;
            y_start -= (y_end - y_start) / (x_end - x_start);
        }
    }
}
