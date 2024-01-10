#include <string>
#include <vector>

using namespace std;

int path[20];
int sign[2] = { -1,1 };
int cnt;

void backtracking(int lv, vector<int> numbers, int target) {
    if (lv == numbers.size()) {
        int sum = 0;
        for (int i = 0; i < numbers.size(); ++i) {
            sum += (numbers[i] * path[i]);
        }

        if (sum == target) ++cnt;

        return;
    }
    for (int i = 0; i < 2; ++i) {
        path[lv] = sign[i];
        backtracking(lv + 1, numbers, target);
        path[lv] = 0;
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    backtracking(0, numbers, target); // 부호 조합

    answer = cnt;
    
    return answer;
}