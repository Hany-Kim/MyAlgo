import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int n;
    static int[] arr = new int[100001];
    static Set<Integer> set = new TreeSet<>();

    public static void main(String[] args) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int maxNum = 0;
        for(int i=0; i<n; i++){
            int num = Integer.parseInt(st.nextToken());
            ++arr[num];

            set.add(num);
            maxNum = Math.max(maxNum, arr[num]);
        }

        long sum = 0L;
        for(int i=1; i<maxNum + 1; i++){
            int now = 0;
            int cnt = 0;
            for(Integer j : set){
                if(arr[j] < i) continue;

                if(now == 0){
                    now = j;
                    cnt += 1;
                }
                else if(j - now == 1){
                    now = j;
                    cnt += 1;
                }
                else if(j - now > 1){
                    long num = (long)now * cnt;
                    sum += num;

                    now = j;
                    cnt = 1;
                }
            }
            long num1 = (long)now * cnt;
            sum += num1;
        }


        bw.write(String.valueOf(sum));

        bw.flush();
        bw.close();
        br.close();
    }
}
