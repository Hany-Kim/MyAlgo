#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

extern void bfs_init(int N, int map[10][10]);
extern int bfs(int x1, int y1, int x2, int y2);
////////////////////////////////////////////////////////////

#define FOR(val,s,e) for(register int val = (s); val<=(e); ++val)

struct Node {
	int y, x;
};
int my_map[11][11];
int my_map_size;
int dy[4] = { 1,0,0,-1 };
int dx[4] = { 0,1,-1,0 };

void bfs_init(int map_size, int map[10][10]) {
	my_map_size = map_size;
	FOR(y, 1, my_map_size) FOR(x, 1, my_map_size) my_map[y][x] = map[y-1][x-1];
}
int bfs(int x1, int y1, int x2, int y2) {
	int used[11][11] = { 0, };
	FOR(y, 1, my_map_size) FOR(x, 1, my_map_size) used[y][x] = -1;

	Node Queue[110];
	int Front = -1;
	int Rear = -1;

	Queue[++Rear] = { y1,x1 };
	used[y1][x1] = 0;
	while (Front != Rear) {
		Node now = Queue[++Front];

		FOR(i, 0, 4) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny<1 || ny>my_map_size || nx<1 || nx>my_map_size)continue;
			if (used[ny][nx] != -1)continue;
			if (my_map[ny][nx] == 1) continue;

			used[ny][nx] = used[now.y][now.x] + 1;
			Queue[++Rear] = { ny,nx };
		}
	}

	return used[y2][x2];
}

////////////////////////////////////////////////////////////
static int test_bfs() {
	int N;
	int map[10][10];
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			scanf("%d", &map[i][j]);
		}
	}
	bfs_init(N, map);
	int M;
	int score = 100;
	scanf("%d", &M);
	for (int i = 0; i < M; ++i) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		int result = bfs(x1, y1, x2, y2);
		int dist;
		scanf("%d", &dist);
		if (result != dist) score = 0;
	}
	return score;
}

int main() {
	setbuf(stdout, NULL);
	freopen("input.txt", "r", stdin);
	printf("#total score : %d\n", test_bfs());

	return 0;
}