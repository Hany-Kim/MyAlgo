import java.io.*;
import java.util.*;

public class Main {
    static Long[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        dp = new Long[10][101];

        dp[0][1] = 0L;
        for(int i=1; i<=9; i++){
            dp[i][1] = 1L;
        }

        for(int x=2; x<101; x++){
            for(int y=0; y<10; y++){
                Long num = 0L;
                if((y-1)>=0){
                    num += dp[y-1][x-1];
                }
                if((y+1)<10){
                    num += dp[y+1][x-1];
                }
                dp[y][x] = num % 1000000000L;
            }
        }

        Long ans = 0L;
        for(int y=0; y<10; y++){
            ans = (ans + dp[y][N]) % 1000000000L;
        }
        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
        br.close();
    }

}