#include <iostream>
using namespace std;

int n;
int used[10];
int cnt;

void input() {
	cin >> n;
}

void func(int lv) {
	if (lv == 3) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (used[i] == 1)continue;
		used[i] = 1;
		func(lv + 1);
		used[i] = 0;
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