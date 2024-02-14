import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    public static final int PORT = 8080;
    public static Socket socket = null;
    public static void main(String[] args) throws IOException {
        System.out.println("Connecting ..... ");
        System.out.println("Connect the server, please input the address(default = 127.0.0.1) and the port(default = 8080), ");
        System.out.println("input \"default\" to connect as the default config");
        System.out.println("or input the connect address and port, dividng by a blank space: ");
        Scanner scanner = new Scanner(System.in);
        String in = scanner.nextLine();
        if(in.equals("default")) {
            socket = new Socket("127.0.0.1", PORT);
            Client client = new Client();
        }
        else {
            String[] tmp = in.split("\\s+");
            if(tmp.length == 2) {
                String add = tmp[0];
                int p = Integer.parseInt(tmp[1]);
                socket = new Socket(add, p);
                Client client = new Client();
            }
            else {
                System.out.println("Wrong input");
                System.exit(1);
                // return;
            }
        }
    }

    public final PrintWriter printWriter;
    public final BufferedReader bufferedReader;
    public Thread getter;
    public Thread printer;
    public Client() throws IOException {
        // this.socket = socket;
        printWriter = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
        bufferedReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        System.out.println("connect success");
        getter = new Getter(bufferedReader);
        getter.start();
        Scanner scanner = new Scanner(System.in);
        while (!socket.isClosed()) {
            printWriter.println(scanner.nextLine());
        }
        /*printer = new Printer(printWriter);
        printer.start();*/
    }
}

class Getter extends Thread{
    public final BufferedReader bufferedReader;
    public Getter(BufferedReader bufferedReader) {
        this.bufferedReader = bufferedReader;
    }
    @Override
    public void run() {
        while (true) {
            if(Client.socket.isClosed())
                break;
            try {
                String next = bufferedReader.readLine();
                System.out.println(next);
                if(next.equals("END")) {
                    Client.socket.close();
                    System.exit(0);
                }
            } catch (IOException e) {
                // throw new RuntimeException(e);
                System.out.println(e);
            }
        }
    }
}
