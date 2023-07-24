#include <iostream>
using namespace std;

int N, M;
int r, c;
int map[50][50];
int start_dir;
int dy[4] = { -1,0,1,0 }; // ºÏ µ¿ ³² ¼­
int dx[4] = { 0,1,0,-1 };
int end_flag;
struct Node {
	int y;
	int x;
};
int ans;

void input() {
	cin >> N >> M;
	cin >> r >> c >> start_dir;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
}
void dfs(Node now, int dir) {
	if (now.y == 1 && now.x == 1) 
		int de = 1;
	for (int i = 3; i >= 0; i--) {
		int next_dir = dir + i;
		if (next_dir >= 4) next_dir = next_dir - 4;
		int ny = now.y + dy[next_dir];
		int nx = now.x + dx[next_dir];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;
		if (map[ny][nx] != 0) continue;
		map[ny][nx] = 2;
		dfs({ ny,nx }, next_dir);
		if (end_flag) break;
	}
	if (end_flag) return;
	if (dir > 1) {
		int ny = now.y + dy[dir - 2];
		int nx = now.x + dx[dir - 2];
		if (map[ny][nx] == 1) {
			end_flag = 1;
			return;
		}
		dfs({ ny,nx }, dir);
	}
	else if (dir <= 1) {
		int ny = now.y + dy[dir + 2];
		int nx = now.x + dx[dir + 2];
		if (map[ny][nx] == 1) {
			end_flag = 1;
			return;
		}
		dfs({ ny,nx }, dir);
	}
}
void check() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] == 2) ans++;
		}
	}
}
void sol() {
	input();
	Node now = { r,c };
	map[r][c] = 2;
	dfs(now, start_dir);
	check();
	cout << ans;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}