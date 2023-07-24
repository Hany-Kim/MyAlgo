#include <iostream>
#include <vector>
using namespace std;

int N, M, K;
char map[8][8];
char cpy[8][8];
struct Point {
	int y;
	int x;
	int used;
};
vector<Point> cctv;
int min_num = 999999;
char path_map[9][8][8];

void input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
			if ((map[y][x] != '0')&& (map[y][x] != '6')) {
				cctv.push_back({ y,x,0 });
			}
		}
	}
}
void copy_map(char dst[][8], char src[][8]) {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			dst[y][x] = src[y][x];
		}
	}
}
void search_up(int lv, int cy, int cx) {
	int ny = cy - 1;
	int nx = cx + 0;
	if (ny < 0 || ny >= N || nx < 0 || nx >= M)return;
	if (map[ny][nx] == '6') return;
	if(map[ny][nx] == '0') path_map[lv+1][ny][nx] = '#';
	while (1) {
		--ny;
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
		if (cpy[ny][nx] == '6') break;
		if (map[ny][nx] == '0') path_map[lv + 1][ny][nx] = '#';
	}
}
void search_down(int lv, int cy, int cx) {
	int ny = cy + 1;
	int nx = cx + 0;
	if (ny < 0 || ny >= N || nx < 0 || nx >= M)return;
	if (map[ny][nx] == '6') return;
	if (map[ny][nx] == '0') path_map[lv + 1][ny][nx] = '#';
	while (1) {
		++ny;
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
		if (cpy[ny][nx] == '6') break;
		if (map[ny][nx] == '0') path_map[lv + 1][ny][nx] = '#';
	}
}
void search_left(int lv, int cy, int cx) {
	int ny = cy + 0;
	int nx = cx - 1;
	if (ny < 0 || ny >= N || nx < 0 || nx >= M)return;
	if (map[ny][nx] == '6') return;
	if (map[ny][nx] == '0') path_map[lv + 1][ny][nx] = '#';
	while (1) {
		--nx;
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
		if (cpy[ny][nx] == '6') break;
		if (map[ny][nx] == '0') path_map[lv + 1][ny][nx] = '#';
	}
}
void search_right(int lv, int cy, int cx) {
	int ny = cy + 0;
	int nx = cx + 1;
	if (ny < 0 || ny >= N || nx < 0 || nx >= M)return;
	if (map[ny][nx] == '6') return;
	if (map[ny][nx] == '0') path_map[lv + 1][ny][nx] = '#';
	while (1) {
		++nx;
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) break;
		if (map[ny][nx] == '6') break;
		if (map[ny][nx] == '0') path_map[lv + 1][ny][nx] = '#';
	}
}
void cctv_1(int lv, int dir, int cy, int cx) {
	if (dir == 0) search_right(lv, cy, cx);
	else if (dir == 1) search_down(lv, cy, cx);
	else if (dir == 2) search_left(lv, cy, cx);
	else if (dir == 3) search_up(lv, cy, cx);
}
void cctv_2(int lv, int dir, int cy, int cx) {
	if (dir >= 2) dir = dir - 2;
	if (dir == 0) {
		search_right(lv, cy, cx);
		search_left(lv, cy, cx);
	}
	else if (dir == 1) {
		search_down(lv, cy, cx);
		search_up(lv, cy, cx);
	}
}
void cctv_3(int lv, int dir, int cy, int cx) {
	if (dir == 0) {
		search_up(lv, cy, cx);
		search_right(lv, cy, cx);
	}
	else if (dir == 1) {
		search_right(lv, cy, cx);
		search_down(lv, cy, cx);
	}
	else if (dir == 2) {
		search_down(lv, cy, cx);
		search_left(lv, cy, cx);
	}
	else if (dir == 3) {
		search_left(lv, cy, cx);
		search_up(lv, cy, cx);
	}
}
void cctv_4(int lv, int dir, int cy, int cx) {
	if (dir == 0) {
		search_left(lv, cy, cx);
		search_up(lv, cy, cx);
		search_right(lv, cy, cx);
	}
	else if (dir == 1) {
		search_up(lv, cy, cx);
		search_right(lv, cy, cx);
		search_down(lv, cy, cx);
	}
	else if (dir == 2) {
		search_right(lv, cy, cx);
		search_down(lv, cy, cx);
		search_left(lv, cy, cx);
	}
	else if (dir == 3) {
		search_down(lv, cy, cx);
		search_left(lv, cy, cx);
		search_up(lv, cy, cx);
	}
}
void cctv_5(int lv, int cy, int cx) {
	search_left(lv, cy, cx);
	search_up(lv, cy, cx);
	search_right(lv, cy, cx);
	search_down(lv, cy, cx);
}

void dfs(int lv) {
	if (lv >= cctv.size()) {
		int zero_cnt = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (path_map[lv][y][x] == '0') zero_cnt++;
			}
		}
		if (zero_cnt < min_num) min_num = zero_cnt;
		return;
	}

	for (int i = 0; i < 4; i++) {
		copy_map(path_map[lv + 1], path_map[lv]);
		char cmd = map[cctv[lv].y][cctv[lv].x];
		if (cmd == '1') {
			cctv_1(lv, i, cctv[lv].y, cctv[lv].x);
		}
		else if (cmd == '2') {
			cctv_2(lv, i, cctv[lv].y, cctv[lv].x);
		}
		else if (cmd == '3') {
			cctv_3(lv, i, cctv[lv].y, cctv[lv].x);
		}
		else if (cmd == '4') {
			cctv_4(lv, i, cctv[lv].y, cctv[lv].x);
		}
		else if (cmd == '5') {
			cctv_5(lv, cctv[lv].y, cctv[lv].x);
		}
		dfs(lv + 1);
		copy_map(path_map[lv + 1], path_map[lv]);
	}
}

void sol() {
	input();
	copy_map(cpy, map);
	copy_map(path_map[0], map);
	
	dfs(0);
	cout << min_num;

	int de = 1;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}