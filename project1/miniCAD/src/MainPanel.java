import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.util.List;

public class MainPanel extends JPanel {
    public int x_start = 0, y_start = 0, x_end = 0, y_end = 0;
    public boolean beselected = false;
    public MainPanel() {
        this.setBackground(Color.WHITE);
        this.addMouseMotionListener(new MouseMotionListener() {
            @Override
            public void mouseDragged(MouseEvent e) {
                if(beselected) {
                    List<ShapeElement> list = ShapeControl.list;
                    x_start = x_end;
                    y_start = y_end;
                    x_end = e.getX();
                    y_end = e.getY();
                    int dx = e.getX() - x_start;
                    int dy = e.getY() - y_start;

                    for (ShapeElement shapeElement : list) {
                        if (shapeElement.beSelected) {
                            shapeElement.MoveTo(dx, dy);
                        }
                    }
                    repaint();
                }
            }

            @Override
            public void mouseMoved(MouseEvent e) {
            }
        });
        this.addMouseListener(new MouseListener() {
            @Override
            public void mouseClicked(MouseEvent e) {
                x_start = e.getX();
                x_end = e.getX();
                y_start = e.getY();
                y_end = e.getY();
                beselected = Select.test(x_start, y_start);
                if(!beselected)
                    Select.ReleaseOtherSelect(null);
                repaint();
                requestFocus();
            }

            @Override
            public void mousePressed(MouseEvent e) {
                x_start = e.getX();
                y_start = e.getY();
            }

            @Override
            public void mouseReleased(MouseEvent e) {
                if(!beselected) {
                    x_end = e.getX();
                    y_end = e.getY();
                    if (Math.pow(x_start - x_end, 2) + Math.pow(y_start - y_end, 2) >= 25) {
                        addShape();
                    }
                }
            }

            @Override
            public void mouseEntered(MouseEvent e) {

            }

            @Override
            public void mouseExited(MouseEvent e) {

            }
        });
    }
    public void addShape() {
        ShapeTypeName shape = ButtonPanel.GetShapeType();
        ShapeElement s = null;
        if(shape == ShapeTypeName.NONE) {
            return;
        } else if(shape == ShapeTypeName.LINE) {
            s = new Line(x_start, y_start, x_end, y_end);
        } else if (shape == ShapeTypeName.RECTANGLE) {
            s = new Rectangle(x_start, y_start, Math.abs(x_end-x_start), Math.abs(y_end - y_start));
        } else if (shape == ShapeTypeName.CIRCLE) {
            s = new Circle(x_start, y_start, Math.abs(x_end-x_start), Math.abs(x_end - x_start));
        } else if (shape == ShapeTypeName.TEXT) {
            String content = JOptionPane.showInputDialog("Please input the text content");
            s = new Text(x_start, y_start, content);
        }
        // ShapeControl.clearPanel();
        ShapeControl.Add(s);
        repaint();
    }
    @Override
    public void paintComponent(Graphics graphics) {
        super.paintComponent(graphics);
        List<ShapeElement> list = ShapeControl.list;
        for (ShapeElement shapeElement : list) {
            shapeElement.Draw((Graphics2D) graphics);
        }
    }
}
