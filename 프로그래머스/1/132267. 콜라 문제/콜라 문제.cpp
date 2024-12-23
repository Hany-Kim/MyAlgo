#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    int cnt = 0;
    int num = n;
    int mod = 0;

    while (1) {
        int bundle = num / a;
        int tmpMod = num % a;

        num = num - (bundle * a) + (bundle * b);

        cnt += (bundle * b);
        if (bundle == 0) break;
    }

    answer = cnt;
    return answer;
}