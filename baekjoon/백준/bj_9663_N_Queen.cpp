#include <iostream>
using namespace std;

int N;
int chess[15];
int cnt;

void input() {
	cin >> N;
}

bool check(int lv) {
	for (int i = 0; i < lv; i++) {
		if (chess[i] == chess[lv] || abs(chess[lv] - chess[i]) == lv - i) {
			return false;
		}
	}
	return true;
}

void func(int x) {
	if (x == N) {
		cnt++;
	}
	else {
		for (int i = 0; i < N; i++) {
			chess[x] = i;
			if (check(x)) {
				func(x + 1);
			}
		}
	}
}

void sol() {
	input();
	func(0);
	cout << cnt;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}