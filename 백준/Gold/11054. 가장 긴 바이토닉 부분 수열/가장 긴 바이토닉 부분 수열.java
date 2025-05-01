import java.io.*;
import java.util.*;

public class Main {
    static int[] arr;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        arr = new int[N];
        dp = new int[2][N]; // row 0 : 오름차순, row 1 : 내림차순

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            dp[0][i] = 1;
            dp[1][i] = 1;
        }

        for(int i=1; i<N; i++){
            for(int j=i-1; j>=0; j--){
                if(arr[i] > arr[j]){
                    // 오름차순 인지, 오름차순 시작 지점인지
                    dp[0][i] = Math.max(dp[0][j] + 1, dp[0][i]);
                }
                else if(arr[i] < arr[j]){
                    // 그대로 인지, 내림차순 이어지는 지점 인지, 내림차순으로 변경된지점인지
                    dp[1][i] = Math.max(dp[1][i], Math.max(dp[1][j] + 1, dp[0][j] + 1));
                }
            }
        }

        int ans = 0;
        for(int i=0; i<2; i++){
            for(int j=0; j<N; j++){
                ans = Math.max(ans, dp[i][j]);
            }
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
        br.close();
    }

}