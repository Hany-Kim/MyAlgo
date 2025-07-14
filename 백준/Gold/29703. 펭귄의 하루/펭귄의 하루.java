import java.io.*;
import java.util.*;
import javax.imageio.plugins.jpeg.JPEGImageReadParam;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[][] map;
    static Integer n, m;
    static Pos penguin;
    static Pos home;
    static List<Pos> foods = new ArrayList<>();// 먹이
    static int[] dy = {-1, 0, 1, 0};
    static int[] dx = {0, -1, 0, 1};
    static Pos selectedFood;
    static int[][] visited, revVisited;

    public static void main(String[] args) throws IOException {
        //br = new BufferedReader(new FileReader("input.txt"));

        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        map = new int[n][m];

        // 맵 정보 저장 (문자 -> 정수 변환)
        for(int y=0; y<n; y++){
            st = new StringTokenizer(br.readLine());
            String str = st.nextToken();
            for(int x=0; x<m; x++){
                if(str.charAt(x) == 'S'){
                    penguin = new Pos(y, x);
                }
                else if(str.charAt(x) == 'H'){
                    home = new Pos(y, x);
                }
                else if(str.charAt(x) == 'E'){
                    map[y][x] = 0;
                }
                else if(str.charAt(x) == 'D'){
                    map[y][x] = 1;
                }
                else if(str.charAt(x) == 'F'){
                    map[y][x] = 2;
                    foods.add(new Pos(y, x));
                }
            }
        }

        // 펭귄 ~ 먹이 거리
        setPenguinToFood();
        // 집 ~ 먹이 거리
        setHomeToFood();

        int dist = Integer.MAX_VALUE;
        for(Pos food : foods){
            if(visited[food.y][food.x] == 0 || revVisited[food.y][food.x] == 0){
                continue;
            }
            int curDist = visited[food.y][food.x] + revVisited[food.y][food.x];
            dist = Math.min(curDist, dist);
        }
        if(dist == 0 || dist == Integer.MAX_VALUE){
            dist = -1;
        }
        else {
            dist -= 2;
        }

        bw.write(String.valueOf(dist));

        bw.flush();
        bw.close();
        br.close();
    }

    private static void setHomeToFood() {
        Queue<Pos> q = new ArrayDeque<>();
        revVisited = new int[n][m];

        Pos start = home;
        q.add(start);
        revVisited[start.y][start.x] = 1;

        while(!q.isEmpty()){
            Pos now = q.poll();

            for(int i=0; i<4; i++){
                int ny = now.y + dy[i];
                int nx = now.x + dx[i];

                if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
                if(map[ny][nx] == 1) continue;
                if(revVisited[ny][nx] > 0) continue;

                Pos next = new Pos(ny, nx);
                q.add(next);
                revVisited[next.y][next.x] = revVisited[now.y][now.x] + 1;
            }
        }
    }

    private static void setPenguinToFood() {
        Queue<Pos> q = new ArrayDeque<>();
        visited = new int[n][m];

        Pos start = penguin;
        q.add(start);
        visited[start.y][start.x] = 1;

        while(!q.isEmpty()){
            Pos now = q.poll();

            for(int i=0; i<4; i++){
                int ny = now.y + dy[i];
                int nx = now.x + dx[i];

                if(ny<0 || ny>=n || nx<0 || nx>=m) continue;
                if(map[ny][nx] == 1) continue;
                if(visited[ny][nx] > 0) continue;

                Pos next = new Pos(ny, nx);
                q.add(next);
                visited[next.y][next.x] = visited[now.y][now.x] + 1;
            }
        }
    }

    static class Pos {
        int y;
        int x;

        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}
