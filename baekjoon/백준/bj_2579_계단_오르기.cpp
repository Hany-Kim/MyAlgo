#include <iostream>
#include <algorithm>
using namespace std;

int n;
int step[301];
int dp[301];

void sol() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> step[i];
	}
	
	dp[0] = step[0];
	dp[1] = max((step[0] + step[1]), step[1]);
	dp[2] = max((step[0] + step[2]), (step[1] + step[2]));
	for (int i = 3; i < n; i++) {
		dp[i] = max((dp[i - 2] + step[i]), (step[i - 1] + step[i] + dp[i - 3]));
	}
	cout << dp[n - 1] << '\n';
	int de = 1;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}