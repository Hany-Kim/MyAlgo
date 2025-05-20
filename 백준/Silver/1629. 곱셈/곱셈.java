import java.io.*;
import java.util.*;

public class Main {
    static Long a, b, c;

    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new FileReader("src/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        a = Long.parseLong(st.nextToken());
        b = Long.parseLong(st.nextToken());
        c = Long.parseLong(st.nextToken());

        Long num = func(a, b, c);

        bw.write(String.valueOf(num));

        bw.flush();
        bw.close();
        br.close();
    }

    private static Long func(Long a, Long b, Long c) {
        if(b == 1L){
            return a % c;
        }

        Long halfB = b / 2;
        Long num = func(a, halfB, c) % c;
        if(b % 2 == 0L){
            return (num * num) % c;
        }
        else {
            Long nnum = func(a, 1L, c) % c;
            return (((num * num) % c) * nnum) % c;
        }
    }
}