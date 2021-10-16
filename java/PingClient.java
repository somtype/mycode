// PingSClient.java
import java.io.*;
import java.net.*;
import java.util.*;

import javax.swing.plaf.basic.BasicInternalFrameTitlePane.SystemMenuBar;

public class PingClient {
    
    public static void main(String[] args) throws Exception{
        String serverName = "localhost";
        if(args.length >= 1)
            serverName = args[0];
        InetAddress serverHost = InetAddress.getByName(serverName);

        int serverPort = 6789;
        if(args.length >= 2)
            serverPort = Integer.parseInt(args[1]);
        DatagramSocket clientSocket = new DatagramSocket();

        short counter = 0;
        long client_send_time = System.currentTimeMillis();
        String passwd = "123321";

        String sequence_number;
        if(counter < 10){
            sequence_number = "0" + String.valueOf(counter);
        }
        else{
            sequence_number = String.valueOf(counter);
        }
        String sentence = new String("PING" + sequence_number + passwd);
        byte[] message = sentence.getBytes();
        System.out.println(sentence);
        for(byte m : message){
            System.out.println(m);
        }
    }
}
