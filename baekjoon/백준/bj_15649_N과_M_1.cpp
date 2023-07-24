#include <iostream>
using namespace std;

int N, M;
int path[8];
bool used[8];

void input() {
	cin >> N >> M;
}

void func(int lv) {
	if (lv == M) {
		for (int i = 0; i < M; i++) {
			cout << path[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (used[i] == 1) continue;
		path[lv] = i;
		used[i] = 1;
		func(lv + 1);
		used[i] = 0;
	}
}

void sol() {
	input();
	func(0);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}