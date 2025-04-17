import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());
        for(int i=0; i<t; i++){
            int n = Integer.parseInt(br.readLine());

            long n1 = 1;
            long n2 = 1;
            long n3 = 1;

            if(n == 1 || n == 2 || n == 3){
                bw.write(String.valueOf(n1));
            } else {
                long num = 0;
                for(int j=0; j<n-3; j++){
                    num = n1 + n2;
                    n1 = n2;
                    n2 = n3;
                    n3 = num;
                }
                bw.write(String.valueOf(num));
            }
            bw.write("\n");
            bw.flush();
        }

        bw.close();
        br.close();
    }
}