#include <iostream>
using namespace std;

int N, M, K;
struct Info {
	int r, c; // 좌표
	int m; // 질량
	int s; // 속력
	int d; // 방향
};
Info fireBall[2501];
int dy[8] = { -1,-1,0,1,1,1,0,-1 };
int dx[8] = { 0,1,1,1,0,-1,-1,-1 };

void input() {
	cin >> N >> M >> K;
	for (register int i = 1; i <= M; ++i) {
		Info now = { 0,0,0,0,0 };
		cin >> now.r >> now.c >> now.m >> now.s >> now.d;

		fireBall[i] = now;
	}
}

void check_dir() {
	int test[3][3] = { 0, };
	for (int i = 0; i < 8; ++i) {
		int nowY = 1;
		int nowX = 1;
		int ny = nowY + dy[i];
		int nx = nowX + dx[i];
		test[ny][nx] = i;
	}
}

void move_fb() {
	int combi_map[50][50][2501] = {0,}; // [][][0] => 합쳐야하는지 유무
	// [][][1] ~ [][][2501] => 합칠 파이어볼 숫자 저장

	for (register int f_num = 1; f_num <= M; ++f_num) {
		Info now = fireBall[f_num];

		for (register int mv_num = 0; mv_num < now.s; ++mv_num) { // 속력만큼 이동
			int ny = now.r + dy[now.d];
			int nx = now.c + dx[now.d];

			if (ny < 0) ny = N - 1;
			else if (ny >= N) ny = 0;
			else if (nx < 0) nx = N - 1;
			else if (nx >= N) nx = 0;

			now.r = ny;
			now.c = nx;
		}

		combi_map[now.r][now.c][0] += 1;
		combi_map[now.r][now.c][f_num] = 1;

		fireBall[f_num] = now;
	}

	for (register int y = 0; y < N; ++y) {
		for (register int x = 0; x < N; ++x) {
			if (combi_map[y][x][0] > 2) { // 파이어볼 두개 이상이면 합친다.

			}
		}
	}
}

void sol() {
	input();
	
	move_fb(); // 파이어 볼 이동

	int de = 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}