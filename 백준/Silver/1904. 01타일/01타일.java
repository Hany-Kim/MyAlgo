import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        long a = 1;
        long b = 2;

        if(n == 1){
            bw.write(String.valueOf(a % 15746));
        } else if(n == 2){
            bw.write(String.valueOf(b % 15746));
        } else {
            long num = 0;
            for(int i=0; i<(n-2); i++){
                num = (a + b) % 15746;
                a = b;
                b = num;
            }
            bw.write(String.valueOf(num));
        }
        bw.flush();
        bw.close();
        br.close();
    }
}