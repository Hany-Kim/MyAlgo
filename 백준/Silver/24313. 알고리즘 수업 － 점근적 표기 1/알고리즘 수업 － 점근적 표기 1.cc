#include <iostream>
using namespace std;


void sol() {
	int a0 = 0, a1 = 0;
	int c = 0;
	int n0 = 0;
	cin >> a0 >> a1;
	cin >> c;
	cin >> n0;

	int ans = 1;
	for (int i = n0; i <= 100; ++i) {
		int left = a0 * i + a1;
		int right = c * i;

		if (left > right) {
			ans = 0;
			break;
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