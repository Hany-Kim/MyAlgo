#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c;
int ans;

void sol() {
	cin >> a >> b >> c;

	for (int i = 1; i <= a; ++i) {
		for (int j = 1; j <= b; ++j) {
			for (int k = 1; k <= c; ++k) {
				int sum = i + j + k;
				int maxLen = max(i, max(j, k));

				sum -= maxLen;

				if (sum <= maxLen) continue;

				ans = max(ans, (sum + maxLen));
			}
		}
	}
	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}