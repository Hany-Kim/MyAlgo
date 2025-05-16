import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String str = br.readLine();

        // 더하기 먼저
        String newStr = "";
        String strNum = "";
        int prev = 0;
        int next = 0;
        for(int i=0; i<str.length(); i++){
            if(str.charAt(i) == '-' || str.charAt(i) == '+'){
                next = Integer.parseInt(strNum);
                strNum = "";

                if(str.charAt(i) == '-'){
                    prev = prev + next;
                    newStr += (String.valueOf(prev) + '-');
                    prev = 0;
                }
                else if(str.charAt(i) == '+'){
                    prev = prev + next;
                }
            }
            else if(i == str.length() - 1){
                strNum += str.charAt(i);
                next = Integer.parseInt(strNum);

                prev = prev + next;
                newStr += String.valueOf(prev);
            }
            else {strNum += str.charAt(i);}
        }

        strNum = "";
        List<Integer> numList = new ArrayList<Integer>();
        for(int i=0; i<newStr.length(); i++){
            if(newStr.charAt(i) == '-'){
                next = Integer.parseInt(strNum);
                strNum = "";

                numList.add(next);
            }
            else if(i == newStr.length() - 1){
                strNum += newStr.charAt(i);
                next = Integer.parseInt(strNum);

                numList.add(next);
            }
            else {strNum += newStr.charAt(i);}
        }

        int num = 0;
        for(int i=0; i<numList.size(); i++){
            if(i==0){
                num += numList.get(i);
            }
            else {
                num -= numList.get(i);
            }
        }

        bw.write(String.valueOf(num));

        bw.flush();
        bw.close();
        br.close();
    }
}