#include <iostream>

using namespace std;

char str[8];
int m[8][8];

void input() {
	cin >> str;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			cin >> m[y][x];
		}
	}
}

void dfs(int now) {
	cout << str[now];


	for (int to = 0; to < 8; to++) {
		if (m[now][to] == 1) {
			dfs(to);
		}
	}

}

void solution() {
	input();
	dfs(0);
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	return 0;
}