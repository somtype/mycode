import java.net.InetAddress;
import java.util.*;

public class Client {
    // 输入参数
    static InetAddress server; // 服务器
    static String servername = "localhost";
    static int serverPort; // 服务器的端口
    static int threadsNum; // 能用的线程数
    static List<String> fileList; // 待处理的文件列表
    static long time2wait = 5; // 运行时间

    // 需要用到的变量
    private ClientThread[] threads; // 线程池

    public Client(int serverPort, int threadsNum, List<String> fileList) {
        // 生成线程池
        threads = new ClientThread[threadsNum];
        for (int i = 0; i < threadsNum; i++) {
            threads[i] = new ClientThread(server, serverPort, fileList);
            new Thread(threads[i]).start();
        }
    }

    public static void main(String[] args) throws Exception {
        if (args.length >= 1) {
            server = InetAddress.getByName(args[0]);
        }
        if (args.length >= 2) {
            serverPort = Integer.parseInt(args[1]);
        }
        if (args.length >= 3) {
            threadsNum = Integer.parseInt(args[2]);
        }
        if (args.length >= 4) {
            fileList = new ArrayList<String>();
            //默认文件数量 = 线程数
            for (int i = 0; i < threadsNum; i++) {
                fileList.add(args[3 + i]);
            }
        }
        if (args.length >= 3 + threadsNum + 1) {
            time2wait = Long.parseLong(args[3 + threadsNum]);
        }
        Timer timer = new Timer();
        timer.schedule(new TimerTask() {
            @Override
            public void run() {
                System.out.println("吞吐量: " + ClientThread.totalBytes / time2wait + "Bps");
                System.exit(1);
            }
        }, 1000 * time2wait);
        Client client = new Client(serverPort, threadsNum, fileList);
        client.run();
    }

    void run() {}
}
