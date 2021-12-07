
/**
 * * XMU CNNS Class Demo Basic Web Server
 **/

import java.io.*;
import java.net.*;
import java.util.*;

class WebRequestHandler implements Runnable {
    static int reqCount = 0;
    String WWW_ROOT;
    private List<Socket> connSockPool;
    Socket connSocket;
    BufferedReader inFromClient;
    DataOutputStream outToClient;

    String urlName;
    String fileName;
    File fileInfo;

    public WebRequestHandler(List<Socket> connSockPool, String WWW_ROOT){
        this.WWW_ROOT = WWW_ROOT;
        this.connSockPool = connSockPool;
    }

    public void run(){
        while (true) {
            synchronized (connSockPool) {
                while (connSockPool.isEmpty()) {
                    try {
                        connSockPool.wait();
                    } catch (InterruptedException e) {
                    }
                }
                connSocket = connSockPool.remove(0);
            }
            try {
                inFromClient = new BufferedReader(new InputStreamReader(connSocket.getInputStream()));
                outToClient = new DataOutputStream(connSocket.getOutputStream());
                mapURL2File();
                if (fileInfo != null) // found the file and knows its info
                {
                    outputResponseHeader();
                    outputResponseBody();
                } // do not handle error
                connSocket.close();
            } catch (Exception e) {
            }
        }
    }

    private void mapURL2File() throws Exception {
        String requestMessageLine = inFromClient.readLine();
        // process the request
        String[] request = requestMessageLine.split("\\s");
        if (request.length < 2 || !request[0].equals("GET")) {
            outputError(500, "Bad request");
            return;
        }
        // parse URL to retrieve file name
        urlName = request[1];
        if (urlName.startsWith("/") == true)
            urlName = urlName.substring(1);
        // map to file name
        fileName = WWW_ROOT + urlName;
        fileInfo = new File(fileName);
        if (!fileInfo.isFile()) {
            outputError(404, "Not Found");
            fileInfo = null;
        }
        synchronized (WebRequestHandler.class) {
            // 输出信息锁，防止输出信息乱序
            System.out.println("\nReceive request from " + connSocket);
            reqCount++;
            System.out.println("Request " + reqCount + ": " + requestMessageLine);
            String line = inFromClient.readLine();
            while (!line.equals("")) {
                System.out.println("Header: " + line);
                line = inFromClient.readLine();
            }
            System.out.println("Map to File name: " + fileName);
        }

    } // end mapURL2file

    private void outputResponseHeader() throws Exception {
        outToClient.writeBytes("HTTP/1.0 200 Document Follows\r\n");
        outToClient.writeBytes("Set-Cookie: MyCool433Seq12345\r\n");

        if (urlName.endsWith(".jpg"))
            outToClient.writeBytes("Content-Type: image/jpeg\r\n");
        else if (urlName.endsWith(".gif"))
            outToClient.writeBytes("Content-Type: image/gif\r\n");
        else if (urlName.endsWith(".html") || urlName.endsWith(".htm"))
            outToClient.writeBytes("Content-Type: text/html\r\n");
        else
            outToClient.writeBytes("Content-Type: text/plain\r\n");
    }

    private void outputResponseBody() throws Exception {
        int numOfBytes = (int) fileInfo.length();
        outToClient.writeBytes("Content-Length: " + numOfBytes + "\r\n");
        outToClient.writeBytes("\r\n");
        // send file content
        FileInputStream fileStream = new FileInputStream(fileName);

        byte[] fileInBytes = new byte[numOfBytes];
        fileStream.read(fileInBytes);

        outToClient.write(fileInBytes, 0, numOfBytes);
    }

    void outputError(int errCode, String errMsg) {
        try {
            outToClient.writeBytes("HTTP/1.0 " + errCode + " " + errMsg + "\r\n");
            outToClient.writeBytes("\r\n");
        } catch (Exception e) {
        }
    }
}
