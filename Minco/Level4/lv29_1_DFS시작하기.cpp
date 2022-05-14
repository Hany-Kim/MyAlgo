#include <iostream>

using namespace std;

int node;
int m[100][100];


void input() {
	cin >> node;
	for (int y = 0; y < node; y++) {
		for (int x = 0; x < node; x++) {
			cin >> m[y][x];
		}
	}
}

void dfs(int now) {
	cout << now << " ";

	for (int to = 1; to < node; to++) {
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