#include <iostream>
using namespace std;

int N;
long long answer;
long long dp[101][11];

void sol() {
	cin >> N;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		dp[i][0] = dp[i - 1][1];
		for (int j = 1; j <= 9; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
		}
	}
	for (int i = 0; i < 10; i++) {
		answer += dp[N][i];
	}
	cout << answer % 1000000000 << "\n";
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}