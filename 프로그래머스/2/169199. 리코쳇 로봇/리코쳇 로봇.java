import java.util.*;

class Solution {
    int r, c;
    int[][] map;
    Pos start, goal;
    int[] dy = {0, 1, 0, -1};
    int[] dx = {1, 0, -1, 0};

    public int solution(String[] boards) {
        int answer = 0;

        init(boards);

        Queue<Pos> q = new LinkedList<>();
        int[][] visited = new int[r][c];
        q.add(start);
        visited[start.y][start.x] = 1;

        while (!q.isEmpty()) {
            Pos now = q.poll();

            for (int i=0; i<4; i++) {
                int ny = now.y, nx = now.x;

                if (i % 2 == 0){
                    nx = getNextX(now.x, i, now.y);
                } else {
                    ny = getNextY(now.y, i, now.x);
                }

                if(visited[ny][nx] > 0) {
                    continue;
                }

                if (ny == goal.y && nx == goal.x) {
                    answer = visited[now.y][now.x];
                    return answer;
                }
                visited[ny][nx] = visited[now.y][now.x] + 1;
                q.add(new Pos(ny, nx));
            }
        }
        
        if(visited[goal.y][goal.x] == 0) {
            answer = -1;
        }

        return answer;
    }

    private int getNextY(int y, int i, int x) {
       int ny = y;
        while(true) {
            int nny = ny + dy[i];
            if (nny < 0 || nny >= r) {
                return ny;
            }
            if (map[nny][x] == 1) {
                return ny;
            }
            ny = nny;
        }
    }

    private int getNextX(int x, int i, int y) {
        int nx = x;
        while(true) {
            int nnx = nx + dx[i];
            if (nnx < 0 || nnx >= c) {
                return nx;
            }
            if (map[y][nnx] == 1) {
                return nx;
            }
            nx = nnx;
        }
    }


    private void init(String[] boards) {
        r = boards.length;
        c = boards[0].length();

        map = new int[r][c];

        for (int y=0; y<r; y++){
            for (int x=0; x<c; x++){
                if (boards[y].charAt(x) == 'R') {
                    start = new Pos(y, x);
                } else if (boards[y].charAt(x) == 'G') {
                    goal = new Pos(y, x);
                } else if (boards[y].charAt(x) == 'D') {
                    map[y][x] = 1;
                } else {
                    map[y][x] = 0;
                }
            }
        }
    }

    class Pos {
        int y;
        int x;

        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}