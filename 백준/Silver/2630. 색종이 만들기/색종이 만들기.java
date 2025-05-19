import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[][] map = new int[128][128];
    static int blueCnt = 0;
    static int whiteCnt = 0;

    public static void main(String[] args) throws IOException {
        //BufferedReader br = new BufferedReader(new FileReader("src/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        for(int y=0; y<n; y++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int x=0; x<n; x++){
                map[y][x] = Integer.parseInt(st.nextToken());
            }
        }

        func(n, 0, 0);

        bw.write(String.valueOf(whiteCnt) + '\n' + String.valueOf(blueCnt));

        bw.flush();
        bw.close();
        br.close();
    }

    static void func(int len, int sy, int sx){
        int nLen = len/2;
        if(len == 1){
            if(map[sy][sx] == 1){
                blueCnt += 1;
            }
            else if(map[sy][sx] == 0){
                whiteCnt += 1;
            }
            return;
        }
        int whiteBlockFlag = 1;
        int blueBlockFlag = 1;
        for(int y=sy; y<sy+len; y++){
            for(int x=sx; x<sx+len; x++){
                if(map[y][x] == 0){
                    blueBlockFlag = 0;
                }
                if(map[y][x] == 1){
                    whiteBlockFlag = 0;
                }
            }
        }

        if(whiteBlockFlag == 1){
            whiteCnt += 1;
            return;
        }
        else if(blueBlockFlag == 1){
            blueCnt += 1;
            return;
        }

        func(nLen, sy, sx);
        func(nLen, sy + nLen, sx);
        func(nLen, sy, sx + nLen);
        func(nLen, sy + nLen, sx + nLen);
    }
}