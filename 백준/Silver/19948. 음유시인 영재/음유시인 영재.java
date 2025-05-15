import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String content = br.readLine();
        int[] alpha = new int[26];
        int space = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < 26; i++) {
            alpha[i] = Integer.parseInt(st.nextToken());
        }

        // 1. 본문 사용량 체크
        char prev = '\0';
        for (int i = 0; i < content.length(); i++) {
            char ch = content.charAt(i);

            if (ch == prev) continue; // 연속 중복 제거
            prev = ch;

            if (ch == ' ') {
                if (space == 0) {
                    System.out.println(-1);
                    return;
                }
                space--;
            } else if (Character.isLetter(ch)) {
                ch = Character.toLowerCase(ch);
                int idx = ch - 'a';
                if (alpha[idx] == 0) {
                    System.out.println(-1);
                    return;
                }
                alpha[idx]--;
            }
        }

        // 2. 제목(단어의 첫 글자들) 추출
        List<Character> title = new ArrayList<>();

        for (int i = 0; i < content.length(); i++) {
            if (i == 0 || content.charAt(i - 1) == ' ') {
                char ch = content.charAt(i);
                if (Character.isLetter(ch)) {
                    ch = Character.toLowerCase(ch);
                    title.add(ch);
                }
            }
        }

        // 3. 제목 출력 (대문자화 + 남은 알파벳 수 확인)
        StringBuilder sb = new StringBuilder();
        for (char ch : title) {
            int idx = ch - 'a';
            if (alpha[idx] == 0) {
                System.out.println(-1);
                return;
            }
            alpha[idx]--;
            sb.append((char)(ch - 'a' + 'A'));
        }

        System.out.println(sb);
    }
}
