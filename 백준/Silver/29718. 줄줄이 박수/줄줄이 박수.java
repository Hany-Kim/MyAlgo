import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int seg;
    static int[] arr;
    static int[] segArr;

    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new FileReader("src/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        arr = new int[m];
        for(int y=0; y<n; y++){
            st = new StringTokenizer(br.readLine());
            for(int x=0; x<m; x++){
                arr[x] += Integer.parseInt(st.nextToken());
            }
        }
        seg = Integer.parseInt(br.readLine());

        int sIdx = 0;
        int eIdx = sIdx + seg;

        segArr = new int[m - seg + 1];
        for(int i=sIdx; i<eIdx; i++){
            segArr[0] += arr[i];
        }

        int maxNum = segArr[0];
        for(int j=1; j<(m-seg+1); j++){
            segArr[j] = segArr[j - 1] - arr[sIdx] + arr[eIdx];
            maxNum = Math.max(maxNum, segArr[j]);

            sIdx += 1;
            eIdx += 1;
        }

        bw.write(String.valueOf(maxNum));

        bw.flush();
        bw.close();
        br.close();
    }
}