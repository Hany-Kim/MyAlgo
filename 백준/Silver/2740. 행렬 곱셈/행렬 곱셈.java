import java.io.*;
import java.util.*;

public class Main {
    static int n, m, k;
    static int[][] matrixA;
    static int[][] matrixB;
    static int[][] matrixC;

    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        matrixA = new int[n][m];

        for(int i=0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<m; j++){
                matrixA[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        matrixB = new int[m][k];
        matrixC = new int[n][k];

        for(int i=0; i<m; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<k; j++){
                matrixB[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int y=0; y<n; y++){
            for(int i=0; i<k; i++){
                int num = 0;
                for(int x=0; x<m; x++){
                    num += (matrixA[y][x] * matrixB[x][i]);
                }
                matrixC[y][i] = num;
            }
        }

        for(int y=0; y<n; y++){
            for(int x=0; x<k; x++){
                bw.write(matrixC[y][x] + " ");
            }
            bw.write("\n");
        }


        bw.flush();
        bw.close();
        br.close();
    }
}