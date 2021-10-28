import com.sun.jdi.ShortType;

import java.io.*;
import java.net.*;
import java.nio.ByteBuffer;
import java.util.*;
public class PingServer {
    private static final double LOSS_RATE = 0.3;
    private static final int AVERAGE_DELAY = 100; // milliseconds
    private static short sequence_number = 0; //计数器，用于计算发送了多少个ping请求
    private static long client_send_time = 0; //时间戳
    private static String passwd = "123321";

    public static void main(String[] args) throws Exception {
        // Get command line argument.
        if (args.length < 1) {
            System.out.println("Required arguments: port password");
            return;
        }
        else if(args.length < 2){
            System.out.printf("Required arguments: password");
            return;
        }
        int port = Integer.parseInt(args[0]);
        String strPass = args[1];
        if (!strPass.equals(passwd)){
            System.out.println("Incorrect password!");
            return;
        }

        // Create random number generator for use in simulating
        // packet loss and network delay.
        Random random = new Random();

        // Create a datagram socket for receiving and sending
        // UDP packets through the port specified on the
        // command line.
        DatagramSocket socket = new DatagramSocket(port);

        // Processing loop.
        while (true) {

            // Create a datagram packet to hold incomming UDP packet.
            DatagramPacket request = new DatagramPacket(new byte[1024], 1024);

            // Block until receives a UDP packet.
            socket.receive(request);

            // Print the received data, for debugging
            printData(request);

            // 获取密码
            byte[] buf = request.getData();
            String pString = new String(buf, 4 + Short.BYTES + Long.BYTES, passwd.length());
            if(!pString.equals(passwd)){
                System.out.println(" Incorrect password!\n");
                continue;
            }

            // Decide whether to reply, or simulate packet loss.
            if (random.nextDouble() < LOSS_RATE) {
                System.out.println(" Reply not sent.\n");
                continue;
            }

            // Simulate prorogation delay.
            Thread.sleep((int)(random.nextDouble() * 2 * AVERAGE_DELAY));

            // Send reply.
            client_send_time = System.currentTimeMillis();
            // 获取sequence_number
            ByteBuffer bb2 = ByteBuffer.wrap(buf, 4, Short.BYTES);
            sequence_number = bb2.getShort();
            InetAddress clientHost = request.getAddress();
            int clientPort = request.getPort();
            byte[] message = getMessage();
            DatagramPacket reply = new DatagramPacket(message, message.length, clientHost, clientPort);
            socket.send(reply);
            System.out.println(" Reply sent. \n");
        } // end of while
    }     // end of main

    /*
     * Print ping data to the standard output stream.
     */
    private static void printData(DatagramPacket request) throws Exception

    {
        // Obtain references to the packet's array of bytes.
        byte[] buf = request.getData();
        String s1 = new String(buf,0,4);
        ByteBuffer bb2 = ByteBuffer.wrap(buf, 4, Short.BYTES);
        short snum = bb2.getShort();
        ByteBuffer bb3 = ByteBuffer.wrap(buf, 4 + Short.BYTES, Long.BYTES);
        long ctime = bb3.getLong();

        System.out.print("Received from " +
                request.getAddress().getHostAddress() + ": " +
                s1 + " " + snum + " " + ctime + " ");
        for(int i = 4 + Short.BYTES + Long.BYTES; buf[i] != '\r'; i++){
            System.out.print((char)buf[i]);
        }
        System.out.println();
    } // end of printData
    private static  byte[] getMessage(){
        // PING byte[]
        byte[] sentence1 = {'E', 'C', 'H', '0', 'P', 'I', 'N', 'G'};
        //生成计数器byte[]
        ByteBuffer bb2 = ByteBuffer.allocate(Short.BYTES);
        bb2.putShort(sequence_number);
        byte[] sentence2 = bb2.array();
        //生成时间戳byte[]
        ByteBuffer bb3 = ByteBuffer.allocate(Long.BYTES);
        bb3.putLong(client_send_time);
        byte[] sentence3 = bb3.array();
        //passwd byte[]
        byte[] sentence4 = passwd.getBytes();
        //生成总sentence byte[]
        byte[] sentence = new byte[sentence1.length + sentence2.length + sentence3.length + sentence4.length + 2];
        ByteBuffer bb = ByteBuffer.wrap(sentence);
        bb.put(sentence1);
        bb.put(sentence2);
        bb.put(sentence3);
        bb.put(sentence4);
        //CRLF
        bb.put(new byte[] {'\r', '\n'});
        sentence = bb.array();
        return sentence;
    }
}
