#include <string>
#include <vector>

using namespace std;

#define FOR(i,s,e) for(int i=s; i<e; ++i)

vector<int> min_v; // 약수 저장
vector<int> max_v; // 약수 저장

void get_divisor(int num) {
    FOR(i, 1, num + 1) {
        if ((num % i) != 0) continue; // 나누어 떨어지지 않으면 약수가 아님
        if (i > (num / i)) break;
        min_v.push_back(i);
        max_v.push_back(num / i);
    }
}

bool isSame(int n1, int n2, int goal) {
    int width = n2 * 2;
    int length = n1 * 2;
    int corner = 4;

    int num = width + length + corner;

    if (num == goal) return true;
    else return false;
}

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    get_divisor(yellow);

    FOR(i, 0, min_v.size()) {
        if (isSame(min_v[i], max_v[i], brown) == true) {
            answer.push_back(max_v[i] + 2);
            answer.push_back(min_v[i] + 2);
        }
    }

    return answer;
}