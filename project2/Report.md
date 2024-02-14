# Java Project2 Report

## Chapter1 问题描述

实现一个多客户端的纯文本聊天服务器，能同时接受多个客户端的连接，并将任意一个客户端发送的文本向所有客户端（包括发送方）转发。

## Chapter2 实验过程

实验环境：

> Windows/WSL
>
> IDEA
>
> openjdk version "11.0.12"

- `Server`类：服务器

  - 成员变量

    ```java
        public final ServerSocket;
        public final Thread connecter;
        public final Thread sender;
        public static final int PORT = 8080;
    ```

  - 默认端口`8080`

    ```java
    public static final int PORT = 8080;
    ```

  - 根据端口新建一个`ServerSocket`

    ```java
    public final ServerSocket serverSocket = new ServerSocket(PORT);
    ```

  - `Server`的构造函数

    ```java
    public Server() throws IOException {
            List<ConnectClient> connectClients = new ArrayList<>(); // 连接上的客户端
            List<String> msgs = new ArrayList<>(); // msgs为待传输的消息队列
            connecter = new Connecter(this.serverSocket, connectClients, msgs); // 监听是否有客户端连接
            sender = new Sender(connectClients, msgs); // 监听是否有消息要发送
            connecter.start();
            sender.start();
            System.out.println("connect success: " + serverSocket);
        }
    ```

  - 将信息发送给所有的客户端

    - `List<String> Msgs`为等待的消息队列
    - 唤醒等待的所有线程

    ```java
    public static void SendToAll(List<String> Msgs) {
            synchronized (Msgs) {
                Msgs.notifyAll();
            }
        }
    ```

- `ConnectClient`类：服务器连接的客户端

  - 成员变量

    ```java
     	public int no;
        public String nickname = null;
        private final Socket socket;
        public final PrintWriter printWriter;
        public final BufferedReader bufferedReader;
        public final List<String> Msgs; // 待传输的消息队列
    ```

  - 接收客户端发来的消息

    - 如果结尾是`BYE`则退出
    - 将待发送的消息加入消息队列

    ```java
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
    ```

- `Connecter` 类：连接客户端和服务器，启动

- `Sender`类

  - 发送消息到客户端
    - 从消息队列中取出一个字符串，通过printWriter打印在客户端

  ```java
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
  ```

## Chapter3 测试

运行server：

<img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20221223113752710.png" alt="image-20221223113752710" style="zoom:50%;" /> 

连接：

<img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20221223120846825.png" alt="image-20221223120846825" style="zoom:50%;" /> 

用客户端程序进行测试（连接了5个客户端）

- A发送消息，此时所有客户端都可以收到消息

  <img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20221215215848378.png" alt="image-20221215215848378" style="zoom:50%;" /> 

  <img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20221215215904837.png" alt="image-20221215215904837" style="zoom:50%;" /> 

  <img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20221215215919337.png" alt="image-20221215215919337" style="zoom:50%;" /> 

  <img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20221215215928796.png" alt="image-20221215215928796" style="zoom:50%;" /> 

  <img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20221215215937750.png" alt="image-20221215215937750" style="zoom:50%;" />

- 进行对话

  ![image-20221215220039403](C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20221215220039403.png)

  <img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20221215220209669.png" alt="image-20221215220209669" style="zoom:100%;" />

- 输入`BYE`客户端断开

  <img src="C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20221215220311237.png" alt="image-20221215220311237" style="zoom:50%;" /> 

- 此时其余的客户端收到消息：`B left the chatting room`

  ![image-20221215220340601](C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20221215220340601.png)

##  Chapter4 遇到的问题

在打包jar包时，运行时，报错：

![image-20221223122522252](C:\Users\17260\AppData\Roaming\Typora\typora-user-images\image-20221223122522252.png)

在网上查阅资料知，这是由于运行.jar的环境和打包.jar包的环境的java版本不一致导致。



 









 

