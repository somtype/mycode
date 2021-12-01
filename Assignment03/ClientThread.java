import java.io.*;
import java.util.*;
import java.net.*;

public class ClientThread implements Runnable {
    private List<String> fileList = null;
    private String filename = null;
    Socket socket = null;
    static long totalBytes = 0;

    public ClientThread(InetAddress server, int port, List<String> fileList) throws Exception{
        this.socket = new Socket(server, port);
        this.fileList = fileList;
    }

    @Override
    public void run(){
        while (true) {
            synchronized (fileList) {
                while (fileList.isEmpty()) {
                    try {
                        fileList.wait();
                    } catch (InterruptedException e) {
                    }
                }
                filename = fileList.remove(0);
            }
            try {
                MakeRequest();
            } catch (Exception e) {
            }
        }
    }

    void MakeRequest() throws Exception{
        DataOutputStream outToServer = new DataOutputStream(socket.getOutputStream());
        outToServer.writeBytes("GET " + filename + " HTTP/1.0\r\n");
        outToServer.writeBytes("Host: " + socket.getLocalAddress() + "\r\n");
        outToServer.writeBytes("\r\n");

        BufferedReader inFromServer = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        String line = inFromServer.readLine();
        int code = Integer.parseInt(line.split("\\s")[1]); //Get response code
        if (code == 200) {
            inFromServer.readLine(); //Content-Type
            inFromServer.readLine(); //Set-Cookie
            line = inFromServer.readLine(); //Content-Length
            int currBytes = Integer.parseInt(line.split("\\s")[1]);
            for (int i = 0; i < currBytes; i++) {
                inFromServer.read();
            }
            synchronized (ClientThread.class) {
                totalBytes += currBytes;
            }
        } else {
            return;
        }
    }
}
