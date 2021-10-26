import java.io.*;
import java.net.*;
import java.util.*;
import java.nio.ByteBuffer;
public class PingClient{
    private static short sequence_number = 0; //计数器，用于计算发送了多少个ping请求
    private static long client_send_time = 0; //时间戳
    private static String passwd = "123321";  //密码
    private static String serverName = "localhost";
    private static int serverPort = 6789;
    public static void main(String[] args) throws Exception {
        //获取服务器ip地址，默认为localhost
        if (args.length >= 1)
            serverName = args[0];
        InetAddress serverHost = InetAddress.getByName(serverName);
        //获取端口，默认为6789
        if (args.length >= 2)
            serverPort = Integer.parseInt(args[1]);
        DatagramSocket clientSocket = new DatagramSocket();
        clientSocket.setSoTimeout(1000);

        //10个ping
        //for(sequence_number = 0; sequence_number < 10; sequence_number++) {
            //发送包
            client_send_time = System.currentTimeMillis();
            byte[] message = getMessage();
            DatagramPacket packet = new DatagramPacket(message, message.length, serverHost, serverPort);
            clientSocket.send(packet);
            System.out.println("src msg:");
            printData(packet);

            //接受回复包
            DatagramPacket reply = new DatagramPacket(new byte[1024], 1024);
            clientSocket.receive(reply);
            byte[] buf = reply.getData();
            System.out.println("Reply msg:");
            printData(reply);

            //延迟
//            Timer timer = new Timer();
//            timer.schedule(new TimerTask(){
//                @Override
//                public void run(){
//
//                }
//            }, 1000);
        //}

    }

    private static void printData(DatagramPacket request) throws Exception {
        // Obtain references to the packet's array of bytes.
        byte[] buf = request.getData();

        // Wrap the bytes in a byte array input stream,
        // so that you can read the data as a stream of bytes.
        ByteArrayInputStream bais = new ByteArrayInputStream(buf);

        // Wrap the byte array output stream in an input
        // stream reader, so you can read the data as a
        // stream of **characters**: reader/writer handles
        // characters
        InputStreamReader isr = new InputStreamReader(bais);

        // Wrap the input stream reader in a bufferred reader,
        // so you can read the character data a line at a time.
        // (A line is a sequence of chars terminated by any
        // combination of \r and \n.)
        BufferedReader br = new BufferedReader(isr);

        // The message data is contained in a single line,
        // so read this line.
        String line = br.readLine();

        // Print host address and data received from it.
        System.out.println("Received from " +
                request.getAddress().getHostAddress() + ": " +
                new String(line));
    } // end of printData
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

