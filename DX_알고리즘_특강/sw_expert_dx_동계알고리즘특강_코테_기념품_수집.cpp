#include <cstdio>
#include <iostream>
using namespace std;

int T,R,C;
char map[20][20];
int used[26];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int max_ans;

void init() {
	for (int i = 0; i < 26; i++) {
		used[i] = 0;
	}
	max_ans = 0;
}

void dfs(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || ny >= R || nx < 0 || nx >= C || used[int(map[ny][nx] - 'A')] == 1) continue;
		used[int(map[ny][nx] - 'A')] = 1;
		dfs(ny, nx);
		used[int(map[ny][nx] - 'A')] = 0;
	}

	int cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (used[i] == 1)cnt++;
	}
	if (max_ans < cnt) max_ans = cnt;
}

void sol() {
	scanf("%d %d", &R, &C);
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			char temp = ' ';
			scanf(" %c", &temp);
			map[y][x] = temp;
		}
	}

	used[int(map[0][0] - 'A')] = 1; // 이미 수집한 기념품 처리
	dfs(0, 0);

	printf("%d\n", max_ans);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("#%d ", i);

		init();
		sol();
	}

	return 0;
}