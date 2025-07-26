import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int n, q;
    static String sic;
    static ArrayList<Integer> nums = new ArrayList<>();
    static ArrayList<Character> ops = new ArrayList<>();
    static ArrayList<Map<Integer, Integer>> andOpMaps = new ArrayList<>();
    static Map<Integer, Integer> orOpMap = new HashMap<>();
    static Map<Integer, Integer> indexMapper = new HashMap<>();

    public static void main(String[] args) throws IOException {

        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        q = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        sic = st.nextToken();
        for(int i=0; i<sic.length(); i+=2){
            nums.add(Integer.parseInt(sic.substring(i,i+1)));
        }
        for(int i=1; i<sic.length(); i+=2){
            ops.add(Character.valueOf(sic.charAt(i)));
        }

        st = new StringTokenizer(br.readLine()); // q

        int andOpGroupNum = 0; // 피연산자가 위치한 group num
        andOpMaps.add(new HashMap<>());

        for(int i=0; i<ops.size(); i++){
            if(ops.get(i) == '&'){
                andOpMaps.get(andOpGroupNum).put(i, nums.get(i));
                indexMapper.put(i, andOpGroupNum);
            } else {
                andOpMaps.get(andOpGroupNum).put(i, nums.get(i));
                indexMapper.put(i, andOpGroupNum);

                if(andOpMaps.get(andOpGroupNum).containsValue(0)){
                    orOpMap.put(andOpGroupNum, 0);
                }else {
                    orOpMap.put(andOpGroupNum, 1);
                }

                andOpGroupNum += 1;
                andOpMaps.add(new HashMap<>());
            }
        }
        andOpMaps.get(andOpGroupNum).put(nums.size() - 1, nums.get(nums.size() - 1));
        indexMapper.put(nums.size() - 1, andOpGroupNum);
        if(andOpMaps.get(andOpGroupNum).containsValue(0)){
            orOpMap.put(andOpGroupNum, 0);
        }else {
            orOpMap.put(andOpGroupNum, 1);
        }

        StringBuilder sb = new StringBuilder("");

        for (int i = 0; i < q; i++) {
            int idx = Integer.parseInt(st.nextToken());
            idx -= 1;

            int groupNum = indexMapper.get(idx);

            if(andOpMaps.get(groupNum).get(idx) == 0){
                andOpMaps.get(groupNum).put(idx, 1);
            } else {
                andOpMaps.get(groupNum).put(idx, 0);
            }

            if(andOpMaps.get(groupNum).containsValue(0)){
                orOpMap.put(groupNum, 0);
            }else {
                orOpMap.put(groupNum, 1);
            }

            if(orOpMap.containsValue(1)){
                sb.append("1");
            } else {
                sb.append("0");
            }
        }

        bw.write(String.valueOf(sb));

        bw.flush();
        bw.close();
        br.close();
    }
}
