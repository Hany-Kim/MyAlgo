#include <iostream>
#include <cstring>
using namespace std;

#define N_MAX 51
#define FOR(i,s,e) for(register int i = s; i < e; ++i)

int N, M;
int map[N_MAX][N_MAX];
int cloud[N_MAX][N_MAX];

void input() {
	cin >> N >> M;
	FOR(y, 1, (N + 1)) {
		FOR(x, 1, (N + 1)) {
			cin >> map[y][x];
		}
	}
}

void init_cloud() {
	cloud[N][1] = 1;
	cloud[N][2] = 1;
	cloud[N - 1][1] = 1;
	cloud[N - 1][2] = 1;
}

int dy[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 };

void move_cloud(int d, int s) {
	int tmp_cloud[N_MAX][N_MAX] = { 0, };
	FOR(y, 1, (N + 1)) {
		FOR(x, 1, (N + 1)) {
			if (cloud[y][x] == 1) {
				int ny = y;
				int nx = x;

				FOR(i, 0, s) {
					ny += dy[d];
					if (ny < 1) ny = N;
					else if (ny > N) ny = 1;
				}
				FOR(i, 0, s) {
					nx += dx[d];
					if (nx < 1) nx = N;
					else if (nx > N) nx = 1;
				}
				tmp_cloud[ny][nx] = 1;
			}
		}
	}

	memcpy(cloud, tmp_cloud, sizeof(cloud));
}

int check_diagonal(int y, int x) {
	int diagonal_cnt = 0;

	for (register int i = 2; i < 9; i += 2) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 1 || nx < 1 || ny > N || nx > N) continue;

		if (map[ny][nx] > 0) ++diagonal_cnt;
	}

	return diagonal_cnt;
}

void rain() {
	FOR(y, 1, (N + 1)) {
		FOR(x, 1, (N + 1)) {
			if (cloud[y][x] == 1) {
				map[y][x] += 1;
				//cloud[y][x] = 0;
			}
		}
	}

	int tmp_map[N_MAX][N_MAX] = { 0, };
	memcpy(tmp_map, map, sizeof(map));

	FOR(y, 1, (N + 1)) {
		FOR(x, 1, (N + 1)) {
			if (cloud[y][x] == 1) {
				int increase_num = check_diagonal(y, x);
				tmp_map[y][x] += increase_num;
				//cloud[y][x] = 0;
			}
		}
	}

	memcpy(map, tmp_map, sizeof(map));
}

void set_cloud() {
	FOR(y, 1, (N + 1)) {
		FOR(x, 1, (N + 1)) {
			if (cloud[y][x] == 1) cloud[y][x] = 0;
			else {
				if (map[y][x] >= 2) {
					cloud[y][x] = 1;
					map[y][x] -= 2;
				}
			}
		}
	}
}

void sol() {
	input();
	init_cloud();
	FOR(i, 0, M) {
		int d = 0, s = 0;
		cin >> d >> s;

		move_cloud(d, s);
		rain();
		set_cloud();
	}

	int sum = 0;
	FOR(y, 1, (N + 1)) {
		FOR(x, 1, (N + 1)) {
			sum += map[y][x];
		}
	}
	cout << sum;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}