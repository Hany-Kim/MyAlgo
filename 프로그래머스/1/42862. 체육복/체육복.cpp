#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define FOR(i,s,e) for(int i=s; i<e; ++i)
#define N_MAX (30 + 1)

bool lost_flag[N_MAX];
bool reserve_flag[N_MAX];
bool isUniform[N_MAX];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;

    FOR(i, 0, lost.size()) lost_flag[lost[i]] = true;
    FOR(i, 0, reserve.size()) {
        reserve_flag[reserve[i]] = true;
        isUniform[reserve[i]] = true;
    }
    FOR(i, 1, (n + 1)) {
        if (!lost_flag[i]) isUniform[i] = true;
    }

    FOR(i, 1, (n + 1)) {
        if ((i - 1) < 0) continue;
        if (!reserve_flag[i]) continue; // 체육복에 여유분이 없는 학생은 건너뜀
        if (lost_flag[i] && reserve_flag[i]) continue;

        if (lost_flag[i - 1] && (i != 1)) {
            if (lost_flag[i - 1] && reserve_flag[i - 1]) {}
            else {
                isUniform[i - 1] = true;
                lost_flag[i - 1] = false;
                continue;
            }
        }
        if (lost_flag[i + 1] && (i != n)) {
            if (lost_flag[i + 1] && reserve_flag[i + 1]) {}
            else {
                isUniform[i + 1] = true;
                lost_flag[i + 1] = false;
                continue;
            }
        }
    }

    FOR(i, 1, (n + 1)) {
        if (isUniform[i]) answer += 1;
    }

    

    return answer;
}