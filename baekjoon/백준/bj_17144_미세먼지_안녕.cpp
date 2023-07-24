#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int R, C, T;
int map[51][51];
int c_map[51][51];
struct Node {
	int y;
	int x;
};
vector<Node> airCleaner;
vector<Node> dust;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int dust_sum;

void spread_dust(int y, int x) {
	queue<pair<int, int>> q;

	q.push({ y,x });

	while(!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny < 0 || ny >= R || nx < 0 || nx >= C)continue;
			if (map[ny][nx] == -1) continue;

			c_map[ny][nx] = c_map[ny][nx] + (map[y][x] / 5);
			c_map[now.first][now.second] = c_map[now.first][now.second] - (map[y][x] / 5);
		}
	}
}
void air_circulation() {
	// 반시계
	int idx = 0;
	Node now = airCleaner[0];
	
	while (1) {
		// 하 우 상 좌
		if (now.y <= 0) idx = 1;
		if (now.x >= C - 1) idx = 2;
		if (now.y >= airCleaner[0].y && map[now.y][now.x] != -1) idx = 3;

		int ny = now.y + dy[idx];
		int nx = now.x + dx[idx];
		if (map[ny][nx] == -1) {
			map[now.y][now.x] = 0;
			break;
		}

		if (map[now.y][now.x] != -1) 
			map[now.y][now.x] = map[ny][nx];
		now = { ny,nx };

	}
	// 시계
	idx = 2;
	now = airCleaner[1];
	while (1) {
		// 상 좌 하 우
		if (now.y >= R - 1) idx = 1;
		if (now.x >= C - 1)idx = 0;
		if (now.y <= airCleaner[1].y && map[now.y][now.x] != -1) idx = 3;

		int ny = now.y + dy[idx];
		int nx = now.x + dx[idx];
		if (map[ny][nx] == -1) {
			map[now.y][now.x] = 0;
			break;
		}

		if (map[now.y][now.x] != -1)
			map[now.y][now.x] = map[ny][nx];
		now = { ny,nx };
	}
}
void sol() {
	cin >> R >> C >> T;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> map[y][x];
			if (map[y][x] == -1) airCleaner.push_back({ y,x });
			else if (map[y][x] != 0) dust.push_back({ y,x });
		}
	}

	while (T) {
		memcpy(c_map, map, sizeof(map));
		for (int i = 0; i < dust.size(); i++) {
			spread_dust(dust[i].y, dust[i].x);
		}
		memcpy(map, c_map, sizeof(map));
		dust.clear();

		air_circulation();

		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				if (map[y][x] != 0 && map[y][x] != -1)dust.push_back({ y,x });
			}
		}
		
		T--;
	}

	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			if (map[y][x] == 0) continue;
			if (map[y][x] == -1) continue;
			dust_sum += map[y][x];
		}
	}
	cout << dust_sum;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}