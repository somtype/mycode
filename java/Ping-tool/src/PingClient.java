import java.io.*;
import java.net.*;
import java.util.*;
import java.nio.ByteBuffer;

public class PingClient {
    private static short sequence_number = 0; // 计数器，用于计算发送了多少个ping请求
    private static long client_send_time = 0; // 时间戳
    private static String passwd = "123";  // 密码
    private static String serverName = "localhost";
    private static int serverPort = 6789;
    private static long toDelay = 0;
    private static long toPacket = 0;

    public static void main(String[] args) throws Exception {
        // 获取服务器ip地址，默认为localhost
        if (args.length >= 1)
            serverName = args[0];
        InetAddress serverHost = InetAddress.getByName(serverName);
        // 获取端口，默认为6789
        if (args.length >= 2)
            serverPort = Integer.parseInt(args[1]);
        // 获取密码，默认为123321
        if (args.length >= 3)
            passwd = args[2];
        DatagramSocket clientSocket = new DatagramSocket();
        clientSocket.setSoTimeout(1000);
        // 创建定时器
        Timer timer = new Timer();
        // 设置定时发包的TimerTask
        class MyTimerTask extends TimerTask {
            @Override
            public void run() {
                //发送包
                try {
                    client_send_time = System.currentTimeMillis();
                    byte[] message = getMessage();
                    DatagramPacket packet = new DatagramPacket(message, message.length, serverHost, serverPort);
                    clientSocket.send(packet);
                    System.out.println(" Packet sent");
                } catch (IOException e) {
                    e.printStackTrace();
                } finally {
                    sequence_number++;
                }
                //接受回复包
                try {
                    DatagramPacket reply = new DatagramPacket(new byte[1024], 1024);
                    clientSocket.receive(reply);
                    byte[] buf = reply.getData();
                    //获取回复包的时间
                    ByteBuffer bb = ByteBuffer.wrap(buf, 8 + Short.BYTES, Long.BYTES);
                    long repTime = bb.getLong();
                    //计算延迟
                    toDelay += repTime - client_send_time;
                    toPacket++;
                    System.out.println(" Packet arrived after " + (repTime - client_send_time) + " ms");
                } catch (IOException e) {
                    System.out.println(" No reply. TIMEOUT!");
                    //e.printStackTrace();
                }
                System.out.println();
                if (sequence_number >= 10) {
                    timer.cancel();
                    System.out.println("Number of arrived packets: " + toPacket);
                    System.out.println("Total delay: " + toDelay + " ms");
                    if (toPacket > 0)
                        System.out.println("Average delay: " + (toDelay / toPacket) + " ms");
                }
            }//End of run()
        }//End of MyTimeTask
        timer.schedule(new MyTimerTask(), 0, 1000);
    }//End of main

    private static byte[] getMessage() {
        //PING byte[]
        byte[] sentence1 = {'P', 'I', 'N', 'G'};
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
        byte[] sentence = new byte[1024];
        ByteBuffer bb = ByteBuffer.wrap(sentence);
        bb.put(sentence1);
        bb.put(sentence2);
        bb.put(sentence3);
        bb.put(sentence4);
        //CRLF
        bb.put(new byte[]{'\r', '\n'});
        sentence = bb.array();
        return sentence;
    }
}

