import java.io.*;
import java.util.*;

public class Main {
    static int[] arr;
    static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        arr = new int[N];
        dp = new int[N];

        for(int i=0; i<N; i++){
            arr[i] = Integer.parseInt(br.readLine());
        }

        if(N == 1){
            dp[0] = arr[0];
        } else if(N == 2){
            dp[0] = arr[0];
            dp[1] = Math.max(arr[1], dp[0] + arr[1]);
        }
        else {
            dp[0] = arr[0];
            dp[1] = Math.max(arr[1], dp[0] + arr[1]);
            dp[2] = Math.max(arr[2], Math.max(arr[0] + arr[2], arr[1] + arr[2]));

            for(int i=3; i<N; i++){
                //dp[i] = Math.max(arr[i] + dp[i-1], Math.max(arr[i] + arr[i-1] + dp[i-3], arr[i] + dp[i-2]));
                dp[i] = Math.max(arr[i] + arr[i-1] + dp[i-3], arr[i] + dp[i-2]);
                if(i>3){
                    dp[i] = Math.max(dp[i], arr[i] + arr[i-1] + dp[i-4]);
                }
            }
        }

        int ans = 0;
        for(int i=0; i<N; i++){
            ans = Math.max(ans, dp[i]);
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
        br.close();
    }

}