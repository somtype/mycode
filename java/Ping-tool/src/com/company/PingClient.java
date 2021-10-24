package com.company;
import java.io.*;
import java.net.*;
import java.nio.Buffer;
import java.nio.ByteBuffer;
import java.nio.charset.StandardCharsets;
import java.util.*;
public class PingClient {

    private static short sequence_number = 30000; //计数器，用于计算发送了多少个ping请求
    private static long client_send_time = System.currentTimeMillis(); //时间戳
    private static String passwd = "123321";                           //密码

    public static void main(String[] args) throws Exception {
        //获取服务器ip地址，默认为localhost
        String serverName = "localhost";
        if (args.length >= 1)
            serverName = args[0];
        InetAddress serverHost = InetAddress.getByName(serverName);

        //获取端口，默认为6789
        int serverPort = 6789;
        if (args.length >= 2)
            serverPort = Integer.parseInt(args[1]);
        DatagramSocket clientSocket = new DatagramSocket();
        byte[] message = getMessage();
        DatagramPacket packet = new DatagramPacket(message, message.length);
        clientSocket.send(packet);

         /*//test
        ByteBuffer bb3 = ByteBuffer.allocate(Short.BYTES);
        bb3.put(sentence2);
        bb3.flip();
        System.out.println(sequence_number);
        System.out.println(bb3.getShort());
        ByteBuffer bb4 = ByteBuffer.allocate(Long.BYTES);
        bb4.put(sentence3);
        bb4.flip();
        System.out.println(client_send_time);
        System.out.println(bb4.getLong());
         */
    }
    private static  byte[] getMessage(){
        byte[] sentence1 = {'P', 'I', 'N', 'G'}; // PING byte[]
        //生成计数器byte[]
        ByteBuffer bb2 = ByteBuffer.allocate(Short.BYTES);
        bb2.putShort(sequence_number);
        byte[] sentence2 = bb2.array();
        //生成时间戳byte[]
        ByteBuffer bb3 = ByteBuffer.allocate(Long.BYTES);
        bb3.putLong(client_send_time);
        byte[] sentence3 = bb3.array();
        byte[] sentence4 = passwd.getBytes(); //passwd byte[]
        //生成总sentence byte[]
        byte[] sentence = new byte[sentence1.length + sentence2.length + sentence3.length + sentence4.length + 2];
        ByteBuffer bb = ByteBuffer.wrap(sentence);
        bb.put(sentence1);
        bb.put(sentence2);
        bb.put(sentence3);
        bb.put(sentence4);
        bb.put(new byte[] {'\r', '\n'}); //CRLF
        sentence = bb.array();
        return sentence;
    }
}
