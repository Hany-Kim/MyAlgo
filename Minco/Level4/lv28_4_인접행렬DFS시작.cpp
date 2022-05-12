#include <iostream>

using namespace std;

int N;
int graph[7][7];
int used[7];

void input() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> graph[y][x];
		}
	}
}

void dfs(int now) {
	used[now] = 1;
	cout << now << " ";
	
	for (int to = 0; to < N; to++) {
		if (graph[now][to] == 1) {
			dfs(to);
		}
	}
}

void solution() {
	input();
	dfs(0);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	return 0;
}