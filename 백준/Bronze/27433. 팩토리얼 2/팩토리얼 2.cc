#include <iostream>
using namespace std;

int N;
long long ans = 1;

void solution() {
	cin >> N;

	if (N > 0) {
		for (long long i = 1; i <= N; ++i) {
			ans *= i;
		}
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solution();
	return 0;
}