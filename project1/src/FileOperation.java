import java.awt.*;
import java.io.*;
import java.lang.annotation.ElementType;
import java.util.ArrayList;
import java.util.List;

public class FileOperation {
    private static String convertRGBToHex(int r, int g, int b) {
        // in ShapeElement, the color is in RGB, we must convert it to Hex and write in file
        String rFString, rSString, gFString, gSString,
                bFString, bSString, result;
        int red, green, blue;
        int rred, rgreen, rblue;
        red = r / 16;
        rred = r % 16;
        if (red == 10) rFString = "A";
        else if (red == 11) rFString = "B";
        else if (red == 12) rFString = "C";
        else if (red == 13) rFString = "D";
        else if (red == 14) rFString = "E";
        else if (red == 15) rFString = "F";
        else rFString = String.valueOf(red);

        if (rred == 10) rSString = "A";
        else if (rred == 11) rSString = "B";
        else if (rred == 12) rSString = "C";
        else if (rred == 13) rSString = "D";
        else if (rred == 14) rSString = "E";
        else if (rred == 15) rSString = "F";
        else rSString = String.valueOf(rred);

        rFString = rFString + rSString;

        green = g / 16;
        rgreen = g % 16;

        if (green == 10) gFString = "A";
        else if (green == 11) gFString = "B";
        else if (green == 12) gFString = "C";
        else if (green == 13) gFString = "D";
        else if (green == 14) gFString = "E";
        else if (green == 15) gFString = "F";
        else gFString = String.valueOf(green);

        if (rgreen == 10) gSString = "A";
        else if (rgreen == 11) gSString = "B";
        else if (rgreen == 12) gSString = "C";
        else if (rgreen == 13) gSString = "D";
        else if (rgreen == 14) gSString = "E";
        else if (rgreen == 15) gSString = "F";
        else gSString = String.valueOf(rgreen);

        gFString = gFString + gSString;

        blue = b / 16;
        rblue = b % 16;

        if (blue == 10) bFString = "A";
        else if (blue == 11) bFString = "B";
        else if (blue == 12) bFString = "C";
        else if (blue == 13) bFString = "D";
        else if (blue == 14) bFString = "E";
        else if (blue == 15) bFString = "F";
        else bFString = String.valueOf(blue);

        if (rblue == 10) bSString = "A";
        else if (rblue == 11) bSString = "B";
        else if (rblue == 12) bSString = "C";
        else if (rblue == 13) bSString = "D";
        else if (rblue == 14) bSString = "E";
        else if (rblue == 15) bSString = "F";
        else bSString = String.valueOf(rblue);
        bFString = bFString + bSString;
        result = "#" + rFString + gFString + bFString;
        return result;
    }
    private static int[] GetRGB(StringBuilder color) {
        // Get RGB of the color from the Color string
        int i = 17;
        StringBuilder r = new StringBuilder();
        StringBuilder g = new StringBuilder();
        StringBuilder b = new StringBuilder();
        while (color.charAt(i) != ',') {
            r.append(color.charAt(i));
            i++;
        }
        i += 3;
        while (color.charAt(i) != ',') {
            g.append(color.charAt(i));
            i++;
        }
        i += 3;
        while (color.charAt(i) != ']') {
            b.append(color.charAt(i));
            i++;
        }
        int[] rbg = {Integer.parseInt(r.toString()), Integer.parseInt(g.toString()), Integer.parseInt(b.toString())};
        return rbg;
    }
    public static void load(String path, String filename) throws IOException {
        // load : in general, string operation and convert it to a ShapeElement list
        FileReader fileReader = new FileReader(path + File.separator + filename);
        BufferedReader bufferedReader = new BufferedReader(fileReader);
        String record = new String(bufferedReader.readLine());
        bufferedReader.close();
        List<ShapeElement> tmp = new ArrayList<>();
        for(int i = 0; i < record.length(); i++) {
            ShapeElement shapeElement;
            if(record.charAt(i) == 'L' && record.charAt(i+1) == 'i' && record.charAt(i+2) == 'n' && record.charAt(i+3) == 'e') {
                i += 5;
                StringBuilder x1 = new StringBuilder();
                StringBuilder x2 = new StringBuilder();
                StringBuilder y1 = new StringBuilder();
                StringBuilder y2 = new StringBuilder();
                StringBuilder color = new StringBuilder();
                while (record.charAt(i) != ' ') {
                    x1.append(record.charAt(i));
                    i++;
                }
                i++;
                while (record.charAt(i) != ' ') {
                    x2.append(record.charAt(i));
                    i++;
                }
                i++;
                while (record.charAt(i) != ' ') {
                    y1.append(record.charAt(i));
                    i++;
                }
                i++;
                while (record.charAt(i) != ' ') {
                    y2.append(record.charAt(i));
                    i++;
                }
                i++;
                // read color
                while (record.charAt(i) != ' ') {
                    color.append(record.charAt(i));
                    i++;
                }
                int[] rgb = GetRGB(color);
                shapeElement = new Line(Integer.parseInt(x1.toString()), Integer.parseInt(x2.toString()), Integer.parseInt(y1.toString()), Integer.parseInt(y2.toString()));
                // shapeElement.itsColor = Color.decode(color.toString());
                shapeElement.itsColor = Color.decode(convertRGBToHex(rgb[0], rgb[1], rgb[2]));
                tmp.add(shapeElement);
            } else if(record.charAt(i) == 'R' && record.charAt(i+1) == 'e' && record.charAt(i+2) == 'c' && record.charAt(i+3) == 't') {
                i += 10;
                StringBuilder x1 = new StringBuilder();
                StringBuilder x2 = new StringBuilder();
                StringBuilder length = new StringBuilder();
                StringBuilder height = new StringBuilder();
                StringBuilder color = new StringBuilder();
                while (record.charAt(i) != ' ') {
                    x1.append(record.charAt(i));
                    i++;
                }
                i++;
                while (record.charAt(i) != ' ') {
                    x2.append(record.charAt(i));
                    i++;
                }
                i++;
                while (record.charAt(i) != ' ') {
                    length.append(record.charAt(i));
                    i++;
                }
                i++;
                while (record.charAt(i) != ' ') {
                    height.append(record.charAt(i));
                    i++;
                }
                i++;
                // read color
                while (record.charAt(i) != ' ') {
                    color.append(record.charAt(i));
                    i++;
                }
                int[] rgb = GetRGB(color);
                shapeElement = new Rectangle(Integer.parseInt(x1.toString()), Integer.parseInt(x2.toString()), Integer.parseInt(length.toString()), Integer.parseInt(height.toString()));
                shapeElement.itsColor = Color.decode(convertRGBToHex(rgb[0], rgb[1], rgb[2]));
                tmp.add(shapeElement);
            } else if(record.charAt(i) == 'C' && record.charAt(i+1) == 'i' && record.charAt(i+2) == 'r' && record.charAt(i+3) == 'c') {
                i += 7;
                StringBuilder x1 = new StringBuilder();
                StringBuilder x2 = new StringBuilder();
                StringBuilder a = new StringBuilder();
                StringBuilder b = new StringBuilder();
                StringBuilder color = new StringBuilder();
                while (record.charAt(i) != ' ') {
                    x1.append(record.charAt(i));
                    i++;
                }
                i++;
                while (record.charAt(i) != ' ') {
                    x2.append(record.charAt(i));
                    i++;
                }
                i++;
                while (record.charAt(i) != ' ') {
                    a.append(record.charAt(i));
                    i++;
                }
                i++;
                while (record.charAt(i) != ' ') {
                    b.append(record.charAt(i));
                    i++;
                }
                i++;
                // read color
                while (record.charAt(i) != ' ') {
                    color.append(record.charAt(i));
                    i++;
                }
                int[] rgb = GetRGB(color);
                shapeElement = new Circle(Integer.parseInt(x1.toString()), Integer.parseInt(x2.toString()), Integer.parseInt(a.toString()), Integer.parseInt(b.toString()));
                // shapeElement.itsColor = Color.decode(color.toString());
                shapeElement.itsColor = Color.decode(convertRGBToHex(rgb[0], rgb[1], rgb[2]));
                tmp.add(shapeElement);
            } else if(record.charAt(i) == 'T' && record.charAt(i+1) == 'e' && record.charAt(i+2) == 'x' && record.charAt(i+3) == 't') {
                i += 5;
                StringBuilder x1 = new StringBuilder();
                StringBuilder x2 = new StringBuilder();
                StringBuilder content = new StringBuilder();
                StringBuilder color = new StringBuilder();
                while (record.charAt(i) != ' ') {
                    x1.append(record.charAt(i));
                    i++;
                }
                i++;
                while (record.charAt(i) != ' ') {
                    x2.append(record.charAt(i));
                    i++;
                }
                i++;
                while (record.charAt(i) != ' ') {
                    content.append(record.charAt(i));
                    i++;
                }
                // i++;
                if(record.charAt(i) == ' ') {
                    i++;
                    content.append(' ');
                    // convert two ' ' into one ' '
                    while (record.charAt(i) != ' ') {
                        content.append(record.charAt(i));
                        i++;
                    }
                    i++;
                }
                // read color
                while (record.charAt(i) != ' ') {
                    color.append(record.charAt(i));
                    i++;
                }
                int[] rgb = GetRGB(color);
                shapeElement = new Text(Integer.parseInt(x1.toString()), Integer.parseInt(x2.toString()), content.toString());
                // shapeElement.itsColor = Color.decode(color.toString());
                shapeElement.itsColor = Color.decode(convertRGBToHex(rgb[0], rgb[1], rgb[2]));
                tmp.add(shapeElement);
            }
        }
        ShapeControl.clearPanel();
        ShapeControl.list = tmp;
    }
    public static void save(String path, String filename) throws IOException {
        // save: convert list to string in file
        List<ShapeElement> list = ShapeControl.list;
        StringBuilder stringBuilder = new StringBuilder();
        for(ShapeElement shapeElement : list) {
            if(shapeElement instanceof Line) {
                stringBuilder.append("Line" + " ").append(((Line) shapeElement).x_start).append(" ").append(((Line) shapeElement).x_end).append(" ").append(((Line) shapeElement).y_start).append(" ").append(((Line) shapeElement).y_end).append(" ").append(shapeElement.itsColor).append(" ");
            } else if (shapeElement instanceof Rectangle) {
                stringBuilder.append("Rectangle" + " ").append(((Rectangle) shapeElement).x).append(" ").append(((Rectangle) shapeElement).y).append(" ").append(((Rectangle) shapeElement).length).append(" ").append(((Rectangle) shapeElement).height).append(" ").append(shapeElement.itsColor).append(" ");
            } else if (shapeElement instanceof Circle) {
                stringBuilder.append("Circle" + " ").append(((Circle) shapeElement).x).append(" ").append(((Circle) shapeElement).y).append(" ").append(((Circle) shapeElement).a).append(" ").append(((Circle) shapeElement).b).append(" ").append(shapeElement.itsColor).append(" ");
            } else if (shapeElement instanceof Text) {
                // in case the text content contains ' ', convert one ' ' to two '  ', or we will confuse the end of one record of ShapeElement
                if(((Text) shapeElement).textcontent.indexOf(' ') != -1) {
                    String tmp = ((Text) shapeElement).textcontent;
                    tmp.replace(" ", "  ");
                    stringBuilder.append("Text" + " ").append((int)((Text) shapeElement).x).append(" ").append((int)((Text) shapeElement).y).append(" ").append(tmp).append(" ").append(shapeElement.itsColor).append(" ");
                }
                else
                    stringBuilder.append("Text" + " ").append((int)((Text) shapeElement).x).append(" ").append((int)((Text) shapeElement).y).append(" ").append(((Text) shapeElement).textcontent).append(" ").append(shapeElement.itsColor).append(" ");
            }
        }
        FileWriter fileWriter = new FileWriter(path + File.separator + filename);
        fileWriter.write(stringBuilder.toString());
        fileWriter.flush();
        fileWriter.close();
    }
}
