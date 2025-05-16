import java.io.*;
import java.util.*;

public class Main {
    static int tc;
    static int n;
    static int[] arr = new int[1001];
    static int[] parent = new int[1001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        tc = Integer.parseInt(br.readLine());

        for(int i=0; i<tc; i++){
            n = Integer.parseInt(br.readLine());

            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=1; j<=n; j++){
                arr[j] = Integer.parseInt(st.nextToken());
                parent[j] = j;
            }

            int sum = sol();

            bw.write(String.valueOf(sum) + '\n');
        }

        bw.flush();
        bw.close();
        br.close();
    }

    static void setUnion(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if(pa <= pb) { parent[pb] = pa; }
        if(pa > pb) { parent[pa] = pb; }
    }

    static int find(int a){
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }

    static int sol() {
        for(int j=1; j<=n; j++){
            setUnion(j, arr[j]);
        }

        Set<Integer> s = new HashSet<Integer>();
        for(int i=1; i<=n; i++){
            s.add(find(parent[i]));
        }

        return s.size();
    }

}