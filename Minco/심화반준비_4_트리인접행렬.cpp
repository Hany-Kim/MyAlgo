#include <iostream>
using namespace std;

int map[6][6];
char path[6];

void input() {
	for (int y = 0; y < 6; y++) {
		for (int x = 0; x < 6; x++) {
			cin >> map[y][x];
		}
	}
}

void dfs(int lv, int now) {
	int flag = 0;
	
	for (int to = 0; to < 6; to++) {
		if (map[now][to] == 1) {
			flag = 1;
			path[lv + 1] = 'A' + to;
			dfs(lv + 1, to);
			path[lv + 1] = 0;
		}
	}

	if (flag == 0) {
		cout << path << '\n';
	}
}

void sol() {
	input();
	path[0] = 'A';
	dfs(0, 0);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}