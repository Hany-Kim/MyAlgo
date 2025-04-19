import java.io.*;
import java.util.*;

public class Main {
    static int[][] arr;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        arr = new int[n][n];
        dp = new int[n][n];

        for(int y=0; y<n; y++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int x=0; x<=y; x++){
                arr[y][x] = Integer.parseInt(st.nextToken());
                dp[y][x] = Integer.MIN_VALUE;
            }
        }

        for(int y=0; y<n; y++){
            if (y == 0){
                dp[y][0] = arr[y][0];
            } else {
                for(int x=0; x<=y; x++){
                    if (y != x) { dp[y][x] = maxNum(arr[y][x] + dp[y-1][x], dp[y][x]); }
                    if (x != 0) { dp[y][x] = maxNum(arr[y][x] + dp[y-1][x-1], dp[y][x]); }
                }
            }
        }

        int ans = 0;
        for(int x=0; x<n; x++){
            ans = maxNum(ans, dp[n-1][x]);
        }

        bw.write(String.valueOf(ans));
        bw.flush();
        bw.close();
        br.close();
    }

    private static int maxNum(int n1, int n2) {
        if(n1 > n2) { return n1; }
        else { return n2; }
    }
}