#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int dp[2501];
char c[2501];
bool p[2501][2501];

void sol() {
	cin >> c + 1;

	for (N = 1; c[N] != NULL; N++); N--;

	for (int i = 1; i <= N; i++) p[i][i] = true;
	for (int i = 1; i < N; i++) {
		if (c[i] == c[i + 1]) p[i][i + 1] = true;
	}
	for (int len = 3; len <= N; len++) {
		for (int start = 1; start + len - 1 <= N; start++) {
			int end = start + len - 1;
			if (c[start] == c[end] && p[start + 1][end - 1] == true)
				p[start][end] = true;
		}
	}

	for (int end = 1; end <= N; end++) {
		dp[end] = 2e9;
		for (int start = 1; start <= end; start++) {
			if (p[start][end] == true)
				dp[end] = min(dp[end], dp[start - 1] + 1);
		}
	}
	cout << dp[N];
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}