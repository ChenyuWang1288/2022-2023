import javax.swing.*;
import java.awt.*;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Initialization {
    private static JFrame frame;
    public Initialization() {
        // the main panel
        ButtonPanel buttonPanel = new ButtonPanel();
        frame = new JFrame("miniCAD");
        frame.setSize(1000, 800);
        frame.setResizable(false);
        frame.setLayout(new BorderLayout());
        frame.add(buttonPanel, BorderLayout.NORTH);
        frame.add(buttonPanel.mainPanel, BorderLayout.CENTER);
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
    // file operation
    public static void Load() throws IOException {
        FileDialog fileDialog = new FileDialog(frame, "LoadFile", FileDialog.LOAD);
        fileDialog.setVisible(true);
        String filepath = fileDialog.getDirectory();
        String fileName = fileDialog.getFile();
        if(filepath == null || fileName == null) {
            return;
        }
        FileOperation.load(filepath, fileName);
        return;
    }
    public static void Save() throws IOException {
        FileDialog fileDialog = new FileDialog(frame, "SaveFile", FileDialog.SAVE);
        fileDialog.setVisible(true);
        String filepath = fileDialog.getDirectory();
        String fileName = fileDialog.getFile();
        if(filepath == null || fileName == null) {
            return;
        }
        FileOperation.save(filepath, fileName);
    }
    public static void main(String[] args) {
        new Initialization();
    }
}