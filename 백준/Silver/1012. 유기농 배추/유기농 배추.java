import java.io.*;
import java.util.*;

public class Main {
    static int m, n, k;
    static int[][] map;
    static int[][] used;
    static Pos[] poss;
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int testcase = Integer.parseInt(br.readLine());
        for(int tc=0; tc<testcase; tc++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            m = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());
            k = Integer.parseInt(st.nextToken());

            map = new int[n][m];
            used = new int[n][m];
            poss = new Pos[k];

            for(int i=0; i<k; i++){
                st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());

                poss[i] = new Pos(y, x);
            }

            int ans = sol();
            bw.write(String.valueOf(ans) + '\n');
        }

        bw.flush();
        bw.close();
        br.close();
    }

    private static int sol() {
        for(Pos now : poss){
            map[now.y][now.x] = 1;
        }

        int num = 0;
        for(int y=0; y<n; y++){
            for(int x=0; x<m; x++){
                if(map[y][x] == 0){ continue;}
                if(used[y][x] == 1){continue;}

                num++;
                bfs(y, x);
            }
        }

        return num;
    }

    private static void bfs(int y, int x) {
        Queue<Pos> q = new ArrayDeque<>();

        Pos start = new Pos(y, x);
        q.add(start);
        used[start.y][start.x] = 1;

        while(!q.isEmpty()){
            Pos now = q.poll();

            for(int i=0; i<4; i++){
                int ny = now.y + dy[i];
                int nx = now.x + dx[i];

                if(ny<0 || ny>=n || nx<0 || nx>=m) {continue;}
                if(used[ny][nx] == 1) {continue;}
                if(map[ny][nx] != 1) {continue;}

                used[ny][nx] = 1;
                q.add(new Pos(ny, nx));
            }
        }
    }

    private static class Pos {
        int y, x;

        private Pos(int y, int x){
            this.y = y;
            this.x = x;
        }
    }
}