#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10001];
int dp[10001];

void sol() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = dp[1] + arr[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max((dp[i - 3] + arr[i - 1] + arr[i]), (dp[i - 2] + arr[i]));
		dp[i] = max(dp[i - 1], dp[i]);
	}
	cout << dp[n] << '\n';
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}