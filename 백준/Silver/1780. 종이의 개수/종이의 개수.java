import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[][] map = new int[2187][2187];
    static int minusOneCnt = 0;
    static int zeroCnt = 0;
    static int oneCnt = 0;

    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new FileReader("src/input.txt"));
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

        bw.write(String.valueOf(minusOneCnt) + '\n'
                + String.valueOf(zeroCnt) + '\n'
                + String.valueOf(oneCnt));

        bw.flush();
        bw.close();
        br.close();
    }

    static void func(int len, int sy, int sx){
        int nLen = len/3;
        if(len == 1){
            if(map[sy][sx] == 1){
                oneCnt += 1;
            }
            else if(map[sy][sx] == 0){
                zeroCnt += 1;
            }
            else if(map[sy][sx] == -1){
                minusOneCnt += 1;
            }
            return;
        }
        int minusOneFlag = 1;
        int zeroFlag = 1;
        int oneFlag = 1;
        for(int y=sy; y<sy+len; y++){
            for(int x=sx; x<sx+len; x++){
                if(map[y][x] == 0){
                    minusOneFlag = 0;
                    oneFlag = 0;
                }
                if(map[y][x] == 1){
                    minusOneFlag = 0;
                    zeroFlag = 0;
                }
                if(map[y][x] == -1){
                    zeroFlag = 0;
                    oneFlag = 0;
                }
            }
        }

        if(minusOneFlag == 1){
            minusOneCnt += 1;
            return;
        }
        else if(zeroFlag == 1){
            zeroCnt += 1;
            return;
        }
        else if(oneFlag == 1){
            oneCnt += 1;
            return;
        }

        func(nLen, sy, sx);
        func(nLen, sy, sx + nLen);
        func(nLen, sy, sx + (2 * nLen));
        func(nLen, sy + nLen, sx);
        func(nLen, sy + nLen, sx + nLen);
        func(nLen, sy + nLen, sx + (2 * nLen));
        func(nLen, sy + (2 * nLen), sx);
        func(nLen, sy + (2 * nLen), sx + nLen);
        func(nLen, sy + (2 * nLen), sx + (2 * nLen));
    }
}