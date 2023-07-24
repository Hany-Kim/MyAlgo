#include <iostream>
using namespace std;

bool bit_check() {
	int N = 0, M = 0;
	cin >> N >> M;

	for (register int i = N - 1; i >= 0; --i) {
		if (M & (1 << i)) {
			//cout << 1; // M의 i번쨰 비트가 1인지
		}
		else return false;
	}
	return true;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC = 0;
	cin >> TC;
	for (register int testcase = 1; testcase <= TC; ++testcase) {
		cout << "#" << testcase << ' ';
		if (bit_check()) {
			cout << "ON";
		}
		else cout << "OFF";
		cout << '\n';
	}

	return 0;
}