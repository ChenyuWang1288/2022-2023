import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.util.List;

public class ButtonPanel extends JPanel {
    private static ShapeTypeName typenumber = ShapeTypeName.NONE;
    public JButton[] jb = new JButton[6]; // buttons on the north of the panel
    protected MainPanel mainPanel = new MainPanel(); // mainpanel on the center
    public ButtonPanel() {
        Font font = new Font("Serif", Font.BOLD, 20);
        Dimension dimension = new Dimension(1000, 200);
        this.setPreferredSize(dimension);
        this.setLayout(new GridLayout(1, 7));
        // Set the buttons and each ActionListener
        jb[0] = new JButton("Line");
        jb[0].setBackground(Color.gray);
        jb[0].addActionListener(new ShapeButtonListener(ShapeTypeName.LINE));
        // jb[0].setFont(font);
        this.add(jb[0]);
        jb[1] = new JButton("Rectangle");
        jb[1].setBackground(Color.gray);
        jb[1].addActionListener(new ShapeButtonListener(ShapeTypeName.RECTANGLE));
        this.add(jb[1]);
        jb[2] = new JButton("Circle");
        jb[2].setBackground(Color.gray);
        jb[2].addActionListener(new ShapeButtonListener(ShapeTypeName.CIRCLE));
        this.add(jb[2]);
        jb[3] = new JButton("Text");
        jb[3].setBackground(Color.gray);
        jb[3].addActionListener(new ShapeButtonListener(ShapeTypeName.TEXT));
        this.add(jb[3]);
        this.add(new FileOperation());
        this.SetColors();
        this.add(new ColorButton());
        this.add(new ResizeButton());
    }
    public static ShapeTypeName GetShapeType() {
        return typenumber;
    }
    public static Color[] colors = new Color[6];
    public void SetColors() {
        colors[0] = Color.red;
        colors[1] = Color.green;
        colors[2] = Color.blue;
        colors[3] = Color.black;
        colors[4] = Color.white;
        colors[5] = Color.gray;
    }

    public class ShapeButtonListener implements ActionListener {
        public ShapeTypeName type;

        public ShapeButtonListener(ShapeTypeName type) {
            // get the current type after click the button
            this.type = type;
            mainPanel.beselected = false;
            Select.ReleaseOtherSelect(null);
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            // get the current type after click the button
            typenumber = type;
            mainPanel.beselected = false;
            Select.ReleaseOtherSelect(null);
        }
    }
    public class FileOperation extends JPanel {
        // save and load button
        public JButton[] jButtons1 = new JButton[2];
        public FileOperation() {
            this.setLayout(new GridLayout(1,2));
            jButtons1[0] = new JButton("Load");
            jButtons1[0].addActionListener(new FileListener(FileOperationType.LOAD));
            this.add(jButtons1[0]);
            jButtons1[1] = new JButton("Save");
            jButtons1[1].addActionListener(new FileListener(FileOperationType.SAVE));
            this.add(jButtons1[1]);
        }
        class FileListener implements ActionListener {
            FileOperationType fileOperationType = FileOperationType.NONE;
            public FileListener(FileOperationType fileOperationType) {
                this.fileOperationType = fileOperationType;
            }
            @Override
            public void actionPerformed(ActionEvent e) {
                // call the funtion in class FileOperation
                if(fileOperationType == FileOperationType.NONE) {
                    return;
                } else if (fileOperationType == FileOperationType.LOAD) {
                    try {
                        Initialization.Load();
                        mainPanel.repaint();
                    } catch (IOException ex) {
                        throw new RuntimeException(ex);
                    }
                } else if (fileOperationType == FileOperationType.SAVE) {
                    try {
                        Initialization.Save();
                    } catch (IOException ex) {
                        throw new RuntimeException(ex);
                    }
                }
            }
        }
    }
    public class ResizeButton extends JPanel {
        // + and - button
        public JButton[] jButtons2 = new JButton[2];
        public ResizeButton() {
            this.setLayout(new GridLayout(1,2));
            jButtons2[0] = new JButton("+");
            // jButtons2[0].setBackground();
            jButtons2[0].addActionListener(new ResizeListener(ResizeTypeName.BIGGER));
            this.add(jButtons2[0]);
            jButtons2[1] = new JButton("-");
            // sjButtons2[1].setBackground(Color.gray);
            jButtons2[1].addActionListener(new ResizeListener(ResizeTypeName.SMALLER));
            this.add(jButtons2[1]);
        }
        class ResizeListener implements ActionListener {
            public ResizeTypeName resizeTypeName = ResizeTypeName.NO;
            public ResizeListener(ResizeTypeName typeName) {
                resizeTypeName = typeName;
            }
            @Override
            public void actionPerformed(ActionEvent e) {
                List<ShapeElement> list = ShapeControl.list;
                for(ShapeElement shapeElement : list) {
                    if(shapeElement.beSelected) {
                        if(resizeTypeName == ResizeTypeName.NO) {
                            return;
                        } else if (resizeTypeName == ResizeTypeName.BIGGER) {
                            shapeElement.Bigger();
                        } else if (resizeTypeName == ResizeTypeName.SMALLER) {
                            shapeElement.Smaller();
                        }
                        mainPanel.repaint(); // clean the panel and repaint
                    }
                }
            }
        }
    }
//    public class
    public class ColorButton extends JPanel {
        // buttons to change the color
        public JButton[] jButtons = new JButton[6];
        public ColorButton() {
            this.setLayout(new GridLayout(2,3));
            for(int i = 0; i < 6; i++) {
                jButtons[i] = new JButton();
                jButtons[i].setBackground(colors[i]);
                jButtons[i].addActionListener(new ColorListener(colors[i]));
                this.add(jButtons[i]);
            }
        }
        class ColorListener implements ActionListener {
            public Color c;
            ColorListener(Color c) {
                this.c = c;
            }
            @Override
            public void actionPerformed(ActionEvent e) {
                List<ShapeElement> list = ShapeControl.list;
                for (ShapeElement shapeElement : list) {
                    if (shapeElement.beSelected) {
                        shapeElement.itsColor = c;
                        mainPanel.repaint();
                        break;
                    }
                }
            }
        }
    }
}
