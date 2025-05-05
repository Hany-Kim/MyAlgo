import java.io.*;
import java.util.*;

public class Main {
    static String str1, str2;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        str1 = br.readLine();
        str2 = br.readLine();

        dp = new int[str2.length() + 1][str1.length() + 1];

        int ans = 0;
        for(int y=0; y<= str2.length(); y++){
            for(int x=0; x<= str1.length(); x++){
                if(y == 0 || x == 0){
                    dp[y][x] = 0;
                }
                else if(str1.charAt(x - 1) == str2.charAt(y - 1)){
                    dp[y][x] = dp[y-1][x-1] + 1;
                }else{
                    dp[y][x] = Math.max(dp[y-1][x], dp[y][x-1]);
                }
                ans = Math.max(ans, dp[y][x]);
            }
        }


        bw.write(String.valueOf(ans));
        bw.flush();
        bw.close();
        br.close();
    }

}