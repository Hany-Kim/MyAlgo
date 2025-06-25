import java.io.*;
import java.util.HashSet;
import java.util.Set;

public class Main {

    static int tc;
    static int n;
    static int[][][] shape = {{{0,0}, {1,0}}, {{0, 0}, {0, 1}}}; // 2x1 , 1x2 도형
    static int[][] map;
    static Set<String> set = new HashSet<>();
    static int[] dp;

    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new FileReader("src/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        tc = Integer.parseInt(br.readLine());

        for (int i = 0; i < tc; i++) {
            n = Integer.parseInt(br.readLine());
//            int answer = solution(n);
            int answer = sol(n);

            bw.write(String.valueOf(answer) + "\n");
        }


        bw.flush();
        bw.close();
        br.close();
    }

    private static int sol(int n) {
        int answer = 0;

        map = new int[4][n];
        dp = new int[n + 10];

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 5;

        for(int i=3; i<=n; i++) {
            dp[i] += (dp[i-1] + 4 * dp[i-2]);
            for(int j=i-3; j>=0; j--){
                if((i-j) % 2 == 1){
                    dp[i] += 2 * dp[j];
                } else {
                    dp[i] += 3 * dp[j];
                }
            }
        }

        answer = dp[n];

        return answer;
    }

    private static int solution(int n) {
        int answer = 0;

        map = new int[4][n];
        set.clear();

        dfs(0, map);
        answer = set.size();

        return answer;
    }

    private static void dfs(int lv, int[][] nowMap) {
        if(check(nowMap)) {
            String str = "";
            for(int y2=0; y2<nowMap.length; y2++) {
                for(int x2=0; x2<nowMap[y2].length; x2++) {
                    str += String.valueOf(nowMap[y2][x2]);
                }
            }

            set.add(str);
            return;
        }

        boolean flag = false;
        for(int y=0; y<nowMap.length; y++) {
            for(int x=0; x<nowMap[y].length; x++) {
                if(nowMap[y][x] != 0) {
                    continue;
                }

                for(int i=0; i<2; i++){
                    int[][] tempMap = deepCopy(nowMap);

                    int ny1 = y + shape[i][0][0];
                    int nx1 = x + shape[i][0][1];
                    int ny2 = y + shape[i][1][0];
                    int nx2 = x + shape[i][1][1];

                    if(ny1 < 0 || nx1 < 0 || ny1 >= nowMap.length || nx1 >= nowMap[0].length
                            || ny2 < 0 || nx2 < 0 || ny2 >= nowMap.length || nx2 >= nowMap[0].length) {
                        continue;
                    }
                    if(tempMap[ny1][nx1] != 0 || tempMap[ny2][nx2] != 0) {
                        continue;
                    }

                    flag = true;
                    tempMap[ny1][nx1] = i + 1;
                    tempMap[ny2][nx2] = i + 1;

                    dfs(lv + 1, tempMap);
                }

                if(flag) {
                    break;
                }
            }
            if(flag) {
                break;
            }
        }
    }

    private static int[][] deepCopy(int[][] nowMap) {
        int[][] tempMap = new int[nowMap.length][nowMap[0].length];
        for(int y=0; y<nowMap.length; y++) {
            for(int x=0; x<nowMap[y].length; x++) {
                tempMap[y][x] = nowMap[y][x];
            }
        }
        return tempMap;
    }

    private static boolean check(int[][] nowMap) {
        for(int y=0; y<nowMap.length; y++) {
            for(int x=0; x<nowMap[y].length; x++) {
                if(nowMap[y][x] == 0) {
                    return false;
                }
            }
        }
        return true; // 모두 채워지면 true
    }
}