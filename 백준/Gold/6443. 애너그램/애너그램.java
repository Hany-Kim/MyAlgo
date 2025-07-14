import java.io.*;
import java.util.*;

class Main {
    static int n;
    static int[] alpha = new int[26];
    static int cnt = 0;
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
//        BufferedReader br = new BufferedReader(new FileReader("src/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        for(int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String str = st.nextToken();
            int len = str.length();

            for(int j = 0; j < len; j++) {
                alpha[str.charAt(j) - 'a']++;
                cnt++;
            }

            getCombi();

            Arrays.fill(alpha, 0);
            cnt = 0;
        }

        bw.flush(); // 여기서만 한 번 호출
        bw.close();
        br.close();
    }

    private static void getCombi() throws IOException {
        for(int i = 0; i < 26; i++) {
            if(alpha[i] > 0) {
                alpha[i]--;

                String combi = "";
                StringBuilder sb = new StringBuilder(combi);
                sb.append((char)(i + 'a'));
                combi = sb.toString();

                dfs(combi, 1);

                alpha[i]++;
            }
        }
    }

    private static void dfs(String combi, int depth) throws IOException {
        if(depth == cnt) {
            bw.write(combi + "\n");
            return;
        }

        for(int i = 0; i < 26; i++) {
            if(alpha[i] > 0) {
                alpha[i]--;

                StringBuilder sb = new StringBuilder(combi);
                sb.append((char)(i + 'a'));
                combi = sb.toString();

                dfs(combi, depth + 1);

                sb.delete(sb.length() - 1, sb.length());
                combi = sb.toString();

                alpha[i]++;
            }
        }
    }
}
