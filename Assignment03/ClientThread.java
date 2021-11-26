import java.io.*;
import java.util.*;
import java.net.*;

public class ClientThread implements Runnable {
    private List<String> fileList;
    Socket socket = null;
    static long totalBytes = 0;
    public ClientThread(InetAddress server, int port, List<String> fileList) throws IOException{
        this.socket = new Socket(server,port);
        this.fileList = fileList;
    }
    @Override
    public void run() {
        try {
            
        } catch (IOException e) {
        }
    }
    void makeRequest(){
        DataOutputStream outToServer = new DataOutputStream(socket.getOutputStream());
            outToServer.writeBytes("GET " + filename + " HTTP/1.0\r\n");
            outToServer.writeBytes("Host: " + clientSocket.getLocalAddress() + "\r\n");
            outToServer.writeBytes("\r\n");

            BufferedReader inFromServer = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            String line = inFromServer.readLine();
            int code = Integer.parseInt(line.split("\\s")[1]);  // Get response code
            if(code == 200){
                inFromServer.readLine();    // Content-Type
                inFromServer.readLine();    // Set-Cookie
                line = inFromServer.readLine(); // Content-Length
                int currBytes = Integer.parseInt(line.split("\\s")[1]);
                for(int i = 0; i < currBytes; i++){
                    inFromServer.read();
                }
                synchronized (this.getClass()){
                    totalBytes += currBytes;
                }
            }
            else{
                return;
            }
    }
}

