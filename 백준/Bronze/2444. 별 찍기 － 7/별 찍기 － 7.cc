#include <iostream>
using namespace std;

int N;

void sol() {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N - i - 1; ++j) {
			cout << " ";
		}
		int times = 2 * i + 1;
		for (int j = 0; j < times; ++j) {
			cout << "*";
		}
		cout << "\n";
	}
	for (int i = (N - 2); i >= 0; i--) {
		for (int j = 0; j < N - i - 1; ++j) {
			cout << " ";
		}
		int times = 2 * i + 1;
		for (int j = 0; j < times; ++j) {
			cout << "*";
		}
		if (i == 0) break;
		cout << "\n";
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}