#include <iostream>

using namespace std;

int N;
int m[9][9];
int path[3];

void input() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> m[y][x];
		}
	}
}

void dfs(int lv, int now) {
	path[lv] = now;
	if (lv == 2) {
		for (int i = 0; i < 3; i++) {
			cout << path[i] << " ";
		}
		cout << endl;

		return;
	}


	for (int to = 0; to < N; to++) {
		if (m[now][to] == 1) {
			dfs(lv + 1, to);
		}
	}
}

void solution() {
	input();
	dfs(0,0);
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	return 0;
}