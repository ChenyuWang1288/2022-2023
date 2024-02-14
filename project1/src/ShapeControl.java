import java.util.ArrayList;
import java.util.List;

public class ShapeControl {
    public static List<ShapeElement> list = new ArrayList<>();

    public static void Add(ShapeElement s) {
        list.add(s);
    }

    public static void clearPanel() {
        // if we load a new file, then we will use this function
        list.removeAll(list);
    }

}
