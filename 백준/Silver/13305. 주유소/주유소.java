import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static Long[] distList;
    static Long[] priceList;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        distList = new Long[n-1];
        priceList = new Long[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i=0; i<n-1; i++){
            distList[i] = Long.parseLong(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i=0; i<n; i++){
            priceList[i] = Long.parseLong(st.nextToken());
        }

        Long sum = 0L;
        Long minPrice = priceList[0];
        for(int i=1; i<n; i++){
            if(priceList[i] > minPrice){
                Long num = distList[i-1] * minPrice;
                sum += num;
            }
            else if(priceList[i] <= minPrice){
                Long num = minPrice * distList[i-1];
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