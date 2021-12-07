
/**
 ** XMU CNNS Class Demo Basic Web Server
 **/

import java.io.*;
import java.net.*;
import java.util.*;

class WebServer {

    public static int serverPort = 4165;
    // public static String WWW_ROOT = "/home/httpd/html/zoo/classes/cs433/";
    public static String WWW_ROOT = "/home/somtype/http/";
    private ServerSocket welcomeSocket;
    private List<Socket> connSockPool;
    private WebRequestHandler[] threads;
    private int backlog = 4;//设置线程数为4

    public WebServer(int serverPort) {
        try {
            welcomeSocket = new ServerSocket(serverPort);
            connSockPool = new ArrayList<Socket>();
            threads = new WebRequestHandler[backlog];
            for (int i = 0; i < backlog; i++) {
                threads[i] = new WebRequestHandler(connSockPool, WWW_ROOT);
                Thread temp = new Thread(threads[i]);
                temp.start();
            }
            System.out.println("server listening at: " + welcomeSocket);
            System.out.println("server www root: " + WWW_ROOT);
        } catch (Exception e) {
        }
    }

    public static void main(String args[]) throws Exception {
        // see if we do not use default server port
        if (args.length >= 1)
            serverPort = Integer.parseInt(args[0]);

        // see if we want a different root
        if (args.length >= 2)
            WWW_ROOT = args[1];
        WebServer webServer = new WebServer(serverPort);
        webServer.run();
    } // end of main

    void run() {
        while (true) {
            try {
                Socket connectionSocket = welcomeSocket.accept();
                synchronized (connSockPool) {
                    connSockPool.add(connectionSocket);
                    //唤醒线程处理请求
                    connSockPool.notifyAll();
                }
            } catch (Exception e) {
            }
        } // end of while (true)
    }

} // end of class WebServer
