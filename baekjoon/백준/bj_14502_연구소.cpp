#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[8][8];
int wall[8][8];
int spread[8][8];
vector<pair<int, int>> v;
struct Node {
	int y;
	int x;
};
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int ans;

void input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
			if (map[y][x] == 2) {
				v.push_back(make_pair(y,x));
			}
		}
	}
}
void wall_map() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			wall[y][x] = map[y][x];
		}
	}
}
void spread_map() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			spread[y][x] = wall[y][x];
		}
	}
}
void safe_zone_check() {
	int zero_cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (spread[y][x] == 0) {
				zero_cnt++;
			}
		}
	}
	if (ans < zero_cnt)ans = zero_cnt;
}
void bfs() {
	spread_map();
	queue<pair<int, int>> q;
	for (int i = 0; i < v.size(); i++) {
		q.push(v[i]);
	}
	while (!q.empty()) {
		Node now = { q.front().first, q.front().second };
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)continue;
			if (spread[ny][nx] != 0)continue;
			spread[ny][nx] = 2;
			q.push(make_pair(ny,nx));
		}
	}
	safe_zone_check();
}
void dfs(int lv) {
	if (lv == 3) {
		bfs();
		return;
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (wall[y][x] != 0)continue;
			wall[y][x] = 1;
			dfs(lv + 1);
			wall[y][x] = 0;
		}
	}
}
void sol() {
	input();
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] != 0)continue;
			wall_map();
			wall[y][x] = 1;
			dfs(1);
			wall[y][x] = 0;
		}
	}
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