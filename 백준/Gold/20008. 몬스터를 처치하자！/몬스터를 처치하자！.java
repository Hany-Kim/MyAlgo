import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int hp;
    static Skill skill[];
    static int ans = Integer.MAX_VALUE;
    static int maxTime = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        hp = Integer.parseInt(st.nextToken());

        skill = new Skill[N];

        for(int i=0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            int damage = Integer.parseInt(st.nextToken());

            skill[i] = new Skill(t, damage, 0);
            maxTime = Math.max(maxTime, t);
        }

        maxTime = maxTime * 10;

        for(int i=0; i<N; i++){
            skill[i].coolTime = skill[i].t;
            dfs(skill[i].damage, 1);
            skill[i].coolTime = 0;
        }

        bw.write(String.valueOf(ans));

        bw.flush();
        bw.close();
        br.close();
    }

    static void dfs(int sumOfDamage, int nowSecond){
        if(sumOfDamage >= hp){
            ans = Math.min(ans, nowSecond);
            return;
        }
        if(maxTime < nowSecond){
            return;
        }

        int flag = 0;
        for(int i=0; i<N; i++){
            if(skill[i].coolTime <= nowSecond) {
                flag = 1;
                int temp = skill[i].coolTime;
                skill[i].coolTime = (skill[i].t) + nowSecond;
                dfs(sumOfDamage + skill[i].damage, nowSecond + 1);
                skill[i].coolTime = temp;
            }
        }
        if(flag == 0) {
            dfs(sumOfDamage, nowSecond + 1);
        }
    }

    static class Skill{
        int t;
        int damage;
        int coolTime;

        public Skill(int t, int damage, int coolTime) {
            this.t = t;
            this.damage = damage;
            this.coolTime = coolTime;
        }
    }

}