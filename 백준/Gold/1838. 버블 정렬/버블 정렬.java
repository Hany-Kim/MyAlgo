import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[] arr;
    static int[] temp;
    static int ans;

    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        n = Integer.parseInt(br.readLine());
        arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        temp = Arrays.copyOf(arr, n);
        Arrays.sort(temp);

        for(int i=0; i<n; i++){
            int moveCnt = (binarySearch(arr[i]) - i) * -1;

            ans = Math.max(ans, moveCnt);
        }

//        bubbleSort();

        bw.write(ans + "\n");

        bw.flush();
        bw.close();
        br.close();
    }

    private static int binarySearch(int i) {
        int s = 0;
        int e = n - 1;

        while(s <= e){
            int mid = (s + e) / 2;

            if(temp[mid] == i){
                return mid;
            }
            else if(temp[mid] < i){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return -1;
    }

    private static void bubbleSort() {
        for(int i=0; i<n; i++){
            int flag = 0;
            for(int j=0; j<n-1; j++){
                if(arr[j] > arr[j+1]){
                    flag = 1;
                    int tmp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = tmp;
                }
            }
            if (flag == 0) {
                ans = i;
                break;
            }
        }
    }

}