#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
using namespace std;

int map[9][9];
int path_len;
vector<pair<int, int>> zero_point;
int flag;

void input() {
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			scanf("%d", &map[y][x]);
			if (map[y][x] == 0) {
				path_len++;
				zero_point.push_back({ y,x });
			}
		}
	}
}

bool check(pair<int, int> p) {
	int sq_y = p.first / 3;
	int sq_x = p.second / 3;
	for (int i = 0; i < 9; i++) {
		if ((map[p.first][i] == map[p.first][p.second]) && (i != p.second))
			return false; // 같은 행 가지치기
		if ((map[i][p.second] == map[p.first][p.second]) && (i != p.first))
			return false; // 같은 열 가지치기
	}
	for (int i = 3 * sq_y; i < 3 * sq_y; i++) {
		for (int j = 3 * sq_x; j < 3 * sq_x; j++) {
			if (map[i][j] == map[p.first][p.second]) {
				if ((i != p.first) && (j != p.second))
					return false; // 사각형 가지치기
			}
		}
	}
	return true;
}

void output() {
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			printf("%d ", map[y][x]);
		}
		printf("\n");
	}
}

void backtracking(int lv) {
	if (lv >= path_len) {
		output();
		flag = 1;
		return;
	}
	for (int i = 1; i <= 9; i++) {
		map[zero_point[lv].first][zero_point[lv].second] = i;
		if (check(zero_point[lv])) backtracking(lv + 1);
		if (flag) return;
	}
	map[zero_point[lv].first][zero_point[lv].second] = 0;
	return;
}

void sol() {
	input();
	backtracking(0);
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	sol();
	return 0;
}