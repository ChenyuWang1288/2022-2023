import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class Server {
    public static final int PORT = 8080;
    public static void main(String[] args) throws IOException {
        Server server = new Server();
    }
    public final ServerSocket serverSocket = new ServerSocket(PORT);
    public final Thread connecter;
    public final Thread sender;
    public Server() throws IOException {
        List<ConnectClient> connectClients = new ArrayList<>();
        List<String> msgs = new ArrayList<>();
        connecter = new Connecter(this.serverSocket, connectClients, msgs);
        sender = new Sender(connectClients, msgs);
        connecter.start();
        sender.start();
        System.out.println("connect success: " + serverSocket);
    }

    public static void SendToAll(List<String> Msgs) {
        synchronized (Msgs) {
            Msgs.notifyAll();
        }
    }
}

class ConnectClient extends Thread{
    public int no;
    public String nickname = null;
    private final Socket socket;
    public final PrintWriter printWriter;
    public final BufferedReader bufferedReader;
    public final List<String> Msgs;
    public ConnectClient(Socket socket, List<String> Msgs) throws IOException {
        this.socket = socket;
        bufferedReader = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        printWriter = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())), true);
        this.Msgs = Msgs;
    }
    @Override
    public void run() {
        super.run();
        printWriter.println("give yourself a nickname: ");
        try {
            while (nickname == null) {
                this.nickname = bufferedReader.readLine();
            }
            // this.nickname = nickname.strip();
            String tmp = "[NOTICE]" + this.nickname + " entered the chatting room!";
            Msgs.add(tmp);
            Server.SendToAll(Msgs);
        } catch (IOException e) {
            // throw new RuntimeException(e);
            System.out.println(e);
        }
        while (true) {
            String r = null;
            try {
                r = bufferedReader.readLine();
            } catch (IOException e) {
                // throw new RuntimeException(e);
                System.out.println(e);
                break;
            }
            if (r.equals("BYE")) {
                Msgs.add("[NOTICE]: " + this.nickname + " left the chatting room");
                Server.SendToAll(Msgs);
                printWriter.println("BYE");
                printWriter.println("END");
                break;
            }
            System.out.println(this.nickname + " send: " + r); // delete while submit
            String sendMsg = this.nickname + ": " + r;
            synchronized (Msgs) {
                Msgs.add(sendMsg);
                Msgs.notifyAll();
            }
        }
    }
}
class Connecter extends Thread {
    public final List<String> Msgs;
    public final List<ConnectClient> connectClients;
    public final ServerSocket serverSocket;
    public Connecter(ServerSocket serverSocket, List<ConnectClient> connectClients, List<String> Msgs) {
        this.Msgs = Msgs;
        this.connectClients = connectClients;
        this.serverSocket = serverSocket;
    }
    @Override
    public void run() {
        while (true) {
            Socket socket = null;
            try {
                socket = serverSocket.accept();
                System.out.println("Server connect success: " + socket);
                ConnectClient newconnect = new ConnectClient(socket, Msgs);
                connectClients.add(newconnect);
                newconnect.start();
            } catch (IOException e) {
                // throw new RuntimeException(e);
                System.out.println(e);
            }
        }
    }
}
class Sender extends Thread {
    public final List<String> Msgs;
    public final List<ConnectClient> connectClients;
    public Sender(List<ConnectClient> connectClients, List<String> Msgs) {
        this.Msgs = Msgs;
        this.connectClients = connectClients;
    }
    @Override
    public void run() {
        super.run();
        while (true) {
            String now = null;
            synchronized (Msgs) {
                if(Msgs.isEmpty()) {
                    try {
                        Msgs.wait();
                    } catch (InterruptedException ignored) {
                    }
                }else {
                    now = deq(Msgs);
                }
            }
            if(now != null) {
                for(ConnectClient connectClient : connectClients) {
                    connectClient.printWriter.println(now);
                }
            }
        }
    }
    private String deq(List<String> msgs) {
        String rst = msgs.get(0);
        msgs.remove(0);
        return rst;
    }
}