#include <iostream>
using namespace std;

int N, M;
int map[501][501];
int used[501][501];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int path[4];
struct Node {
	int y;
	int x;
};
Node now;
int max_num;

void input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
}

void dfs(int lv, Node n) {
	if (lv == 4) {
		/*for (int i = 0; i < 4; i++) {
			cout << path[i];
		}
		cout << '\n';*/
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			sum += path[i];
		}
		if (max_num < sum) max_num = sum;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int ny = n.y + dy[i];
		int nx = n.x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M || used[ny][nx] == 1) continue;
		path[lv] = map[ny][nx];
		used[ny][nx] = 1;
		dfs(lv + 1, {ny, nx});
		path[lv] = 0;
		used[ny][nx] = 0;
	}
}

void shape_T(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int sum = map[y][x];
		int flag = 0;
		for (int j = i; j < i + 3; j++) {
			int idx = j;
			if (idx >= 4) {
				idx -= 4;
			}
			int ny = y + dy[idx];
			int nx = x + dx[idx];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) {
				sum = 0;
				flag = 1;
				break;
			}
			sum += map[ny][nx];
		}
		if (flag) continue;
		if (max_num < sum) max_num = sum;
	}
}

void sol() {
	input();
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			now = { y,x };
			shape_T(y, x);
			path[0] = map[y][x];
			used[y][x] = 1;
			dfs(1, now);
			path[0] = 0;
			used[y][x] = 0;
		}
	}
	cout << max_num;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}