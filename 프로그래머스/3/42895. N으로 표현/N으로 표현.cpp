#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
#define FOR(i,s,e) for(int i=s; i<e; ++i)

vector<unordered_set<int>> dp(8);

int solution(int N, int number) {
    int answer = 0;

    if (N == number) {
        answer = 1;
        return answer;
    }

    int N_join = 0;
    
    FOR(cnt_idx, 0, 8) { // N을 사용한 갯수 8초과는 -1
        N_join = (N_join * 10) + N; // N, NN, NNN, ..., NN...N 형태로 N끼리 이어붙은 형태 저장
        
        dp[cnt_idx].insert(N_join);

        FOR(j, 0, cnt_idx) {
            FOR(k, 0, cnt_idx) {
                if (j + k + 1 != cnt_idx) continue;
                for (auto a : dp[j]) {
                    for (auto b : dp[k]) {
                        dp[cnt_idx].insert(a + b);
                        if (a - b > 0) dp[cnt_idx].insert(a - b); // 음수 결과 제외
                        dp[cnt_idx].insert(a * b);
                        if (b != 0) dp[cnt_idx].insert(a / b); // 0 나누기 방지
                    }
                }
            }
        }
        if (dp[cnt_idx].find(number) != dp[cnt_idx].end()) {
            answer = cnt_idx + 1;
            return answer;
        }
    }


    return -1;
}