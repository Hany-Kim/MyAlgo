import java.io.*;
import java.util.*;

public class Main {
    static int[] arr;
    static int maxNum = -1001;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int sum = 0;
        for(int i=0; i<arr.length; i++){
            if((arr[i] + sum) > arr[i]){
                maxNum = max(arr[i] + sum, maxNum);
                sum += arr[i];
            } else {
                maxNum = max(arr[i], maxNum);
                sum = arr[i];
            }
        }

        bw.write(String.valueOf(maxNum));

        bw.flush();
        bw.close();
        br.close();
    }

    private static int max(int n1, int n2) {
        if(n1 >= n2) { return n1; }
        else { return n2; }
    }
}