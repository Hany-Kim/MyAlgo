import java.io.*;
import java.util.*;

public class Main {
    static int[][] arr;
    static int[] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        arr = new int[2][N];
        dp = new int[N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[0][i] = Integer.parseInt(st.nextToken());
            arr[1][i] = Integer.parseInt(st.nextToken());
            dp[i] = 1;
        }

        int[][] temp = new int[N][2];
        for (int i = 0; i < N; i++) {
            temp[i][0] = arr[0][i]; // 기준값
            temp[i][1] = arr[1][i]; // 같이 따라올 값
        }

        Arrays.sort(temp, (a,b) -> Integer.compare(a[0], b[0]));

        for (int i = 0; i < N; i++) {
            arr[0][i] = temp[i][0];
            arr[1][i] = temp[i][1];
        }

        for (int i = 1; i < N; i++) {
            for (int j=i-1; j>=0; j--){
                if(arr[1][i] > arr[1][j]){
                    dp[i] = Math.max(dp[j] + 1, dp[i]);
                }
            }
        }
        int ans = 0;
        for(int i=0; i<N; i++){
            ans = Math.max(ans, dp[i]);
        }

        ans = N - ans;
        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
        br.close();
    }

}