import java.io.*;
import java.util.*;

public class Main {
    static int N, K;
    static class Prod {
        int w, v;
    }
    static Prod[] prods;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        prods = new Prod[N];
        dp = new int[K + 1][N];
        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            prods[i] = new Prod();
            prods[i].w = Integer.parseInt(st.nextToken());
            prods[i].v = Integer.parseInt(st.nextToken());
        }

        for(int x=0; x<N; x++){
            for(int y=0; y<=K; y++){
                if(y==0) {
                    dp[y][x] = 0;
                }
                else {
                    if(x == 0){
                        dp[y][x] = prods[x].w <= y ? prods[x].v : 0;
                    }
                    else {
                        dp[y][x] = Math.max(dp[y][x-1], prods[x].w <= y ? dp[y-prods[x].w][x-1] + prods[x].v : dp[y][x-1]);
                    }
                }
            }
        }

        int ans = dp[K][N-1];
        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
        br.close();
    }

}