#include <iostream>
#include <math.h>
using namespace std;

int N;

void func(int lv) {
	if (lv == 0) {
		cout << "-";
		return;
	}

	func(lv - 1);
	for (int j = 0; j < pow(3, lv - 1); ++j) {
		cout << " ";
	}
	func(lv - 1);
}

void solution() {
	while (cin >> N) {
		func(N);
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solution();
	return 0;
}