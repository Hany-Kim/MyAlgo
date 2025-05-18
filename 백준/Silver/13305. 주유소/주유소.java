import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[] distList;
    static int[] priceList;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        distList = new int[n-1];
        priceList = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n-1; i++){
            distList[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            priceList[i] = Integer.parseInt(st.nextToken());
        }

        int sum = 0;
        int minPrice = priceList[0];
        for(int i=1; i<n; i++){
            if(priceList[i] > minPrice){
                int num = distList[i-1] * minPrice;
                sum += num;
            }
            else if(priceList[i] <= minPrice){
                int num = minPrice * distList[i-1];
                sum += num;

                minPrice = Math.min(minPrice, priceList[i]);
            }
        }

        bw.write(String.valueOf(sum));

        bw.flush();
        bw.close();
        br.close();
    }
}