#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    int cnt = 0;
    int num = n;

    while (1) {
        int bundle = num / a;
        int mod = num % a;

        num = num - (bundle * a) + (bundle * b);

        cnt += (bundle * b);
        if (bundle == 0) break;
    }

    answer = cnt;
    return answer;
}