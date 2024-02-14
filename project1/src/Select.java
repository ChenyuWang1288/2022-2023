import java.util.List;

public class Select {
    // test if a ShapeElement is going to be selected
    public static void ReleaseOtherSelect(ShapeElement thisone) {
        // after we select another ShapeElement, the previous one will be recovered
        List<ShapeElement> list = ShapeControl.list;
        for(ShapeElement shapeElement : list) {
            if(shapeElement.beSelected == true) {
                if(shapeElement == thisone) {
                    continue;
                }
                shapeElement.beSelected = false;
            }
        }
    }
    public static boolean test(int x, int y) {
        // calculate the distance of the click to each ShapeElement, if less than a certain distance, then select
        List<ShapeElement> list = ShapeControl.list;
        for(ShapeElement shapeElement : list) {
            if(shapeElement instanceof Line) {
                double distance;
                double x1 = ((Line) shapeElement).x_start;
                double x2 = ((Line) shapeElement).x_end;
                double y1 = ((Line) shapeElement).y_start;
                double y2 = ((Line) shapeElement).y_end;

                if(x1 == x2) {
                    if(y <= y1 && y <= y2 || y >= y1 && y >= y2) {
                        distance = Math.min(Math.sqrt(Math.pow(x - x1, 2) + Math.pow(y - y1, 2)), Math.sqrt(Math.pow(x - x2, 2) + Math.pow(y - y2, 2)));
                    }
                    else distance = Math.abs(x - x1);
                }
                // distance = Math.abs(((y2 - y1)*x - (x2 - x1)*y - x1*y2 + x2*y1) / Math.sqrt(Math.pow(x2-x1, 2) - Math.pow(y2-y1 , 2)) );
                else if(x <= x1 && x <= x2 || x >= x1 && x >= x2) {
                    distance = Math.min(Math.sqrt(Math.pow(x - x1, 2) + Math.pow(y - y1, 2)), Math.sqrt(Math.pow(x - x2, 2) + Math.pow(y - y2, 2)));
                }
                else {
                    distance = Math.abs((y2-y1) / (x2-x1) * x - y + y1 - x1 * (y2-y1) / (x2-x1));
                }
                if(distance <= 5) {
                    shapeElement.beSelected = true;
                    ReleaseOtherSelect(shapeElement);
                    return true;
                }
            } else if (shapeElement instanceof Rectangle) {
                double x1 = ((Rectangle) shapeElement).x;
                double y1 = ((Rectangle) shapeElement).y;
                double height = ((Rectangle) shapeElement).height;
                double length = ((Rectangle) shapeElement).length;
                if(x >= x1 && x <= x1 + length && y >= y1 && y <= y1 + height) {
                    shapeElement.beSelected = true;
                    ReleaseOtherSelect(shapeElement);
                    return true;
                }
            } else if (shapeElement instanceof Circle) {
                double x1 = ((Circle) shapeElement).x;
                double y1 = ((Circle) shapeElement).y;
                double a = ((Circle) shapeElement).a;
                double b = ((Circle) shapeElement).a;
                if(Math.pow(x - x1 - a/2, 2) + Math.pow(y - y1 - a/2, 2) <= Math.pow(a/2, 2)) {
                    shapeElement.beSelected = true;
                    ReleaseOtherSelect(shapeElement);
                    return true;
                }
            } else if (shapeElement instanceof Text) {
                double x1 = ((Text) shapeElement).x;
                double y1 = ((Text) shapeElement).y;
                double length = ((Text) shapeElement).fontMetrics.stringWidth(((Text) shapeElement).textcontent);
                double height = ((Text) shapeElement).fontMetrics.getHeight();
                if(x >= x1 && x <= x1 + length && y <= y1 && y >= y1 - height) {
                    shapeElement.beSelected = true;
                    ReleaseOtherSelect(shapeElement);
                    return true;
                }
            }
        }
        return false;
    }
}
