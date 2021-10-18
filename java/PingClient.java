// PingSClient.java
import java.io.*;
import java.net.*;
import java.util.*;
import javax.swing.plaf.basic.BasicInternalFrameTitlePane.SystemMenuBar;

public class PingClient {

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

        short sequence_number = 30000; //计数器，用于计算发送了多少个ping请求
        long client_send_time = System.currentTimeMillis(); //时间戳
        String passwd = "123321";                           //密码

        byte[] sentence1 = {'P', 'I', 'N', 'G'}; // PING
        byte[] sentence2 = new byte[10];         // sequence_number + 时间戳
        sentence2[0] = (byte)(sequence_number >> 8); //sequence_number高字节
        sentence2[1] = (byte)sequence_number;        //sequence_number低字节

        byte[] sentence4 = passwd.getBytes();
        for (byte m : sentence2) {
            System.out.println(m);
        }
    }
}
