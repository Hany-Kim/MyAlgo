#include <iostream>
using namespace std;

int T;

void sol() {
	int N = 0;
	int arr[10] = { 0, };
	cin >> N;

	int times = 0;

	while (1) {
		++times;

		int num = N * times;
		while (num > 9) {
			if (arr[num % 10] | num) arr[num % 10] = 1;
			num = num / 10;
		}
		if (arr[num % 10] | num) arr[num % 10] = 1;

		bool flag = true;
		for (register int i = 0; i < 10; ++i) {
			if (arr[i] == 0) {
				flag = false;
				break;
			}
		}
		if (flag) break;
	}
	cout << N * times;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (register int testcase = 1; testcase <= T; ++testcase) {
		cout << "#" << testcase << ' ';
		sol();
		cout << '\n';
	}

	return 0;
}