#include <iostream>
#include <vector>
using namespace std;

int N, M;
long long arr[1000000];
long long prefix[1000000];

void solution() {
    cin >> N >> M;

    vector<long long> cnt(M, 0); // 나머지 개수를 저장하는 배열
    long long total = 0;
    long long result = 0;

    cnt[0] = 1; // 누적합이 M으로 나누어떨어지는 경우 초기화

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        total += arr[i];
        int mod = (total % M + M) % M; // 음수 나머지 방지
        result += cnt[mod]; // 이전 동일 나머지 수만큼 결과 증가
        cnt[mod]++;         // 현재 나머지 기록
    }

    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solution();
    return 0;
}
