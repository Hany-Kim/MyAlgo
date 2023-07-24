#include <iostream>
using namespace std;

int N, M;
int path[9];
bool used[9];

void input() {
	cin >> N >> M;
}

void func(int num, int lv) {
	if (lv == M) {
		for (int i = 0; i < M; i++) {
			cout << path[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = num; i <= N; i++) {
		//if (used[i] == 1) continue;
		path[lv] = i;
		//used[i] = 1;
		func(i, lv + 1);
		//used[i] = 0;
	}
}

void sol() {
	input();
	func(1, 0);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}