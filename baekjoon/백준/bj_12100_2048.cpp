#include <iostream>
#include <string>
using namespace std;

int N;
int map[21][21];
int original_map[21][21];
int max_num;
string path[5];

void input() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> original_map[y][x];
		}
	}
}

void move_left() {
	for (int y = 0; y < N; y++) { // 왼쪽으로 밀기
		for (int x = 1; x < N; x++) {
			int i = 1;
			while (map[y][x - i] == 0) {
				if ((x - i) < 0)break;
				map[y][x - i] = map[y][x - (i - 1)];
				map[y][x - (i - 1)] = 0;
				i++;
			}
		}
	}
	for (int y = 0; y < N; y++) { // 합치기
		for (int x = 1; x < N; x++) {
			if (map[y][x] == map[y][x - 1]) {
				map[y][x - 1] = map[y][x - 1] + map[y][x];
				map[y][x] = 0;
			}
		}
	}
	for (int y = 0; y < N; y++) { // 왼쪽으로 밀기
		for (int x = 1; x < N; x++) {
			int i = 1;
			while (map[y][x - i] == 0) {
				if ((x - i) < 0)break;
				map[y][x - i] = map[y][x - (i - 1)];
				map[y][x - (i - 1)] = 0;
				i++;
			}
		}
	}
}
void move_up() {
	for (int x = 0; x < N; x++) { // 위로 밀기
		for (int y = 1; y < N; y++) {
			int i = 1;
			while (map[y - i][x] == 0) {
				if ((y - i) < 0)break;
				map[y - i][x] = map[y - (i - 1)][x];
				map[y - (i - 1)][x] = 0;
				i++;
			}
		}
	}
	for (int x = 0; x < N; x++) { // 합치기
		for (int y = 1; y < N; y++) {
			if (map[y][x] == map[y - 1][x]) {
				map[y - 1][x] = map[y - 1][x] + map[y][x];
				map[y][x] = 0;
			}
		}
	}
	for (int x = 0; x < N; x++) { // 위로 밀기
		for (int y = 1; y < N; y++) {
			int i = 1;
			while (map[y - i][x] == 0) {
				if ((y - i) < 0)break;
				map[y - i][x] = map[y - (i - 1)][x];
				map[y - (i - 1)][x] = 0;
				i++;
			}
		}
	}
}
void move_right() {
	for (int y = 0; y < N; y++) { // 오른쪽으로 밀기
		for (int x = N - 2; x >= 0; x--) {
			int i = 1;
			while (map[y][x + i] == 0) {
				if ((x + i) >= N)break;
				map[y][x + i] = map[y][x + (i - 1)];
				map[y][x + (i - 1)] = 0;
				i++;
			}
		}
	}
	for (int y = 0; y < N; y++) { // 합치기
		for (int x = N - 2; x >= 0; x--) {
			if (map[y][x] == map[y][x + 1]) {
				map[y][x + 1] = map[y][x + 1] + map[y][x];
				map[y][x] = 0;
			}
		}
	}
	for (int y = 0; y < N; y++) { // 오른쪽으로 밀기
		for (int x = N - 2; x >= 0; x--) {
			int i = 1;
			while (map[y][x + i] == 0) {
				if ((x + i) >= N)break;
				map[y][x + i] = map[y][x + (i - 1)];
				map[y][x + (i - 1)] = 0;
				i++;
			}
		}
	}
}
void move_down() {
	for (int x = 0; x < N; x++) { // 아래로 밀기
		for (int y = N - 2; y >= 0; y--) {
			int i = 1;
			while (map[y + i][x] == 0) {
				if ((y + i) >= N)break;
				map[y + i][x] = map[y + (i - 1)][x];
				map[y + (i - 1)][x] = 0;
				i++;
			}
		}
	}
	for (int x = 0; x < N; x++) { // 합치기
		for (int y = N - 2; y >= 0; y--) {
			if (map[y][x] == map[y + 1][x]) {
				map[y + 1][x] = map[y + 1][x] + map[y][x];
				map[y][x] = 0;
			}
		}
	}
	for (int x = 0; x < N; x++) { // 아래로 밀기
		for (int y = N - 2; y >= 0; y--) {
			int i = 1;
			while (map[y + i][x] == 0) {
				if ((y + i) >= N)break;
				map[y + i][x] = map[y + (i - 1)][x];
				map[y + (i - 1)][x] = 0;
				i++;
			}
		}
	}
}
void dfs(int lv, int d) {
	if (lv > 4) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				map[y][x] = original_map[y][x];
			}
		}

		for (int i = 0; i < 5; i++) {
			if (path[i] == "left") move_left();
			if (path[i] == "up")move_up();
			if (path[i] == "right")move_right();
			if (path[i] == "down")move_down();
		}
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (max_num < map[y][x]) {
					max_num = map[y][x];
				}
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (i == 0) path[lv] = "left";
		if (i == 1) path[lv] = "up";
		if (i == 2) path[lv] = "right";
		if (i == 3) path[lv] = "down";
		dfs(lv + 1, i);
		path[lv] = "";
	}
}
void sol() {
	input();
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			map[y][x] = original_map[y][x];
		}
	}
	dfs(0, 0);
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