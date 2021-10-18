public class test {
    public static void main(String[] args) {
        String test = "HelloWorld";
        System.out.println(test);
        test = new String();
        System.out.println(test);

        byte[] a = {'H','E'};
        for(byte aa : a){
            System.out.println(aa);
        }
        a = new byte[3];
                for(byte aa : a){
            System.out.println(aa);
        }
    }
}
