#include <stdio.h>
#include <iostream>
using namespace std;

int n;
int dp[5001];

void sol() {
	scanf("%d", &n);

	dp[3] = dp[5] = 1;
	for (int i = 6; i <= n; i++) {
		if (dp[i - 3])dp[i] = dp[i - 3] + 1;
		if (dp[i - 5]) {
			if (dp[i]) {
				dp[i] = min(dp[i], dp[i - 5] + 1);
			}
			else {
				dp[i] = dp[i - 5] + 1;
			}
		}
	}

	if (dp[n] == 0) {
		printf("%d", -1);
	}
	else printf("%d", dp[n]);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	sol();

	return 0;
}