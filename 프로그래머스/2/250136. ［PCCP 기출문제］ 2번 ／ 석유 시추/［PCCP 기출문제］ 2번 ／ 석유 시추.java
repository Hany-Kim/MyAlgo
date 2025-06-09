import java.util.*;

class Solution {
    int[] sum;
    int row, col;
    int[] dy = {-1, 1, 0, 0};
    int[] dx = {0, 0, -1, 1};
    int[][] used;
    Map<Integer, Integer> map = new HashMap<>();

    public int solution(int[][] land) {
        int answer = 0;

        row = land.length;
        col = land[0].length;
        sum = new int[col];
        used = new int[row][col];

        int idx = 1;
        for(int y=0; y<row; y++){
            for(int x=0; x<col; x++){
                if(land[y][x]==1 && used[y][x] == 0){
                    map.put(idx, bfs(y, x, land, idx));
                    idx++;
                }
            }
        }
        
        for(int x=0; x<col; x++){
            Set<Integer> set = new HashSet<>();
            
            for(int y=0; y<row; y++){
                if(used[y][x] != 0 && !set.contains(used[y][x])){
                    set.add(used[y][x]);
                    
                    sum[x] += map.get(used[y][x]);
                }
                // System.out.print(used[y][x] + " ");
            }
            answer = Math.max(sum[x], answer);
            // System.out.print(sum[x] + " ");
            // System.out.println();
        }

        return answer;
    }

    public int bfs(int sy, int sx, int[][] land, int idx) {
        Queue<Pos> q = new LinkedList<>();
        // int[][] used = new int[row][col];

        q.add(new Pos(sy, sx));
        used[sy][sx] = idx;
        int cnt = 1;

        while(!q.isEmpty()) {
            Pos now = q.poll();

            for(int i=0; i<4; i++){
                int ny = now.y + dy[i];
                int nx = now.x + dx[i];
                
                if(ny<0 || ny>=row || nx<0 || nx>=col) { continue; }
                if(land[ny][nx] == 0) { continue; }
                if(used[ny][nx] != 0) { continue; }
                
                cnt += 1;
                used[ny][nx] = idx;
                q.add(new Pos(ny, nx));
            }
        }
        
        return cnt;
    }

    class Pos {
        int y, x;

        Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }
    }
}