import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static Long b;
    static int[][] matrixA;
    static int mod = 1000;

    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        b = Long.parseLong(st.nextToken());
        matrixA = new int[n][n];

        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<n; j++){
                matrixA[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        
        int[][] ans = func(matrixA, b);

        for(int y=0; y<n; y++){
            for(int x=0; x<n; x++){
                bw.write(ans[y][x] + " ");
            }
            bw.write("\n");
        }

        bw.flush();
        bw.close();
        br.close();
    }

    private static int[][] func(int[][] now, Long b) {
        if(b == 1){
            int[][] temp = new int[n][n];

            for(int y=0; y<n; y++){
                for(int x=0; x<n; x++){
                    temp[y][x] = matrixA[y][x] % mod;
                }
            }
            return temp;
        }

        int[][] newMatrix = func(now, b / 2);
        if(b%2 == 0){
            return multiplicationMatrixAAndB(newMatrix, newMatrix);
        }
        else {
            return multiplicationMatrixAAndB(newMatrix, multiplicationMatrixAAndB(newMatrix, matrixA));
        }
    }

    private static int[][] multiplicationMatrixAAndB(int[][] a, int[][] b) {
        int[][] temp = new int[n][n];

        for(int y=0; y<n; y++){
            for(int i=0; i<n; i++){
                int num = 0;
                for(int x=0; x<n; x++){
                    num += ((a[y][x] * b[x][i]) % mod);
                }
                temp[y][i] = num % mod;
            }
        }

        return temp;
    }
}