#include <iostream>

using namespace std;

int N, K;
int coin_val[100];
int dp[10001] = { 1, };
int result[101][10001];

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coin_val[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = coin_val[i]; j <= K; j++) {
			dp[j] += dp[j - coin_val[i]];
		}
	}

	cout << dp[K] << endl;
	return 0;
}