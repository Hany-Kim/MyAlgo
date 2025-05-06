import java.io.*;
import java.util.*;

public class Main {
    static int N, M, K;
    static String[] std;
    static int[][] board1;
    static int[][] board2;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        std = new String[N];
        board1 = new int[N][M];
        board2 = new int[N][M];

        for (int i = 0; i < N; i++) {
            String s = "";
            for(int j=0; j<M; j++){
                if(i%2==0) { s += (j%2==0) ? "B"  : "W"; }
                else if(i%2==1) {s += (j%2==0) ? "W" : "B";}
                std[i] = s;
            }

            st = new StringTokenizer(br.readLine());
            String str = st.nextToken();
            for (int j = 0; j < M; j++) {
                board1[i][j] = str.charAt(j) == s.charAt(j) ? 0 : 1;
                board2[i][j] = str.charAt(j) == s.charAt(j) ? 1 : 0;
            }
        }

        for(int y=0; y<N; y++){
            for(int x=1; x<M; x++){
                board1[y][x] += board1[y][x-1];
                board2[y][x] += board2[y][x-1];
            }
        }

        for(int x=0; x<M; x++){
            for(int y=1; y<N; y++){
                board1[y][x] += board1[y-1][x];
                board2[y][x] += board2[y-1][x];
            }
        }

        int ans = 2134567890;
        for(int ny=N-1; ny>=N-1-(N-K); ny--){
            for(int nx=M-1; nx>=M-1-(M-K); nx--){
                int y = ny;
                int x = nx;
                int num1 = y - K < 0 ? 0 : board1[y-K][x];
                int num2 = x - K < 0 ? 0 : board1[y][x-K];
                int num3 = num1 == 0 || num2 == 0 ? 0 : board1[y-K][x-K];

                ans = Math.min(board1[y][x] - (num1 + num2) + num3, ans);

                num1 = y - K < 0 ? 0 : board2[y-K][x];
                num2 = x - K < 0 ? 0 : board2[y][x-K];
                num3 = num1 == 0 || num2 == 0 ? 0 : board2[y-K][x-K];

                ans = Math.min(board2[y][x] - (num1 + num2) + num3, ans);

                int de = 1;
            }
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
        br.close();
    }

}