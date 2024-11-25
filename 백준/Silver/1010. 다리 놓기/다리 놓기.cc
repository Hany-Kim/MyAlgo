#include <iostream>
using namespace std;

int T;
int N, M;

void solution() {
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		cin >> N >> M;

		long long ans = 1;
		double div = 1;
		for (int i = (M - N + 1); i <= M; ++i) {
			ans *= i;
			ans /= div;
			div++;
		}
		cout << ans << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solution();
	return 0;
}