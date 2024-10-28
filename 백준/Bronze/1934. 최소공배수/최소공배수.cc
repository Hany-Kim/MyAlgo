#include <iostream>
using namespace std;

int T;

void sol() {
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		int n1 = 0, n2 = 0;
		cin >> n1 >> n2;

		int times = 1;
		while (true) {
			int num = n1 * times;

			if (num % n2 == 0) {
				cout << num << "\n";
				break;
			}
			times++;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}