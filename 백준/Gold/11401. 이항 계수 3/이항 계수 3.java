import java.io.*;
import java.util.*;

public class Main {
    static Long n, k;
    static Long mod = 1000000007L;

    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new FileReader("src/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Long.parseLong(st.nextToken());
        k = Long.parseLong(st.nextToken());

        if (k == 1) {
            bw.write(String.valueOf(n));
        }
        else if (k == 0 || n == k){
            bw.write(String.valueOf(1));
        }
        else if (n - k == 1){
            bw.write(String.valueOf(n));
        }
        else {
            Long a = 1L, b = 1L, num;
            for(Long i=n; i>=n-k+1; i--){
                a = (a * i) % mod;
            }
            for(Long i=1L; i<=k; i++){
                b = (b * i) % mod;
            }
            num = ((a % mod) * func(b, mod - 2) % mod) % mod;

            bw.write(String.valueOf(num));
        }

        bw.flush();
        bw.close();
        br.close();
    }

    private static Long func(Long a, Long m) {
        if(m == 0) return 1L;

        Long temp = func(a, m / 2) % mod;
        if (m % 2 == 1) return (((temp * temp) % mod) * a) % mod;
        return (temp * temp) % mod;
    }
}