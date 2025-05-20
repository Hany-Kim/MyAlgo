import java.io.*;
import java.util.*;

public class Main {
    static String str1;
    static String str2;
    static String res;
    static String ans = "";
    static int[][] dp;

    public static void main(String[] args) throws IOException {
//        BufferedReader br = new BufferedReader(new FileReader("src/input.txt"));
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        str1 = br.readLine();
        str2 = br.readLine();
        res = br.readLine();

        dp = new int[str1.length() + 1][str2.length() + 1];
        dp[0][0] = 1;

        for(int idx1=0; idx1<=str1.length(); idx1++){
            for(int idx2=0; idx2<=str2.length(); idx2++){
                if(dp[idx1][idx2] == 0) {
                    continue;
                }

                if(idx1 < str1.length() && str1.charAt(idx1) == res.charAt(idx1 + idx2)){
                    dp[idx1 + 1][idx2] = 1;
                }
                if(idx2 < str2.length() && str2.charAt(idx2) == res.charAt(idx1 + idx2)){
                    dp[idx1][idx2 + 1] = 1;
                }
            }
        }

        int str1Len = str1.length();
        int str2Len = str2.length();

        while(str1Len > 0 || str2Len > 0){
            if(str1Len > 0 && dp[str1Len - 1][str2Len] >= 1 && str1.charAt(str1Len - 1) == res.charAt(str1Len + str2Len - 1)){
                ans += "1";
                str1Len--;
            } else {
                ans += "2";
                str2Len--;
            }
        }

        StringBuilder sb = new StringBuilder(ans);
        bw.write(sb.reverse().toString());

//        func(0, 0, 0, "");

        bw.flush();
        bw.close();
        br.close();
    }

    private static void func(int i, int idx1, int idx2, String str) {
        if(i == res.length()){
            if(str.length() == res.length()){
                ans = str;
            }
            return;
        }

        int flag = 0;
        if(idx1 < str1.length() && str1.charAt(idx1) == res.charAt(i)){
            flag = 1;

            int add = 0;
            String addStr = "";
            while(true){
                if(idx1 + add >= str1.length()){
                    break;
                }
                if(str1.charAt(idx1 + add) == res.charAt(i + add)){
                    add += 1;
                    addStr += "1";
                    func(i + add, idx1 + add, idx2, str + addStr);
                }
                else {
                    break;
                }
            }

        }
        if(idx2 < str2.length() && str2.charAt(idx2) == res.charAt(i)){
            flag = 1;

            int add = 0;
            String addStr = "";
            while(true){
                if(idx2 + add >= str2.length()){
                    break;
                }
                if(str2.charAt(idx2 + add) == res.charAt(i + add)){
                    add += 1;
                    addStr += "2";
                    func(i + add, idx1, idx2 + add, str + addStr);
                }
                else {
                    break;
                }
            }
        }

        if(flag == 0) {
            //func(i+1, idx1, idx2, str);
        }

    }
}
