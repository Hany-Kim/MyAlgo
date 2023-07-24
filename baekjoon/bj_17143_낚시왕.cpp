#include <iostream>
#include <cmath>
using namespace std;

/*
칸에는 상어가 최대 한 마리 들어있을 수 있다. 상어는 크기와 속도를 가지고 있다.
낚시왕은 처음에 1번 열의 한 칸 왼쪽에 있다.
낚시왕은 가장 오른쪽 열의 오른쪽 칸에 이동하면 이동을 멈춘다.

낚시왕은 처음에 1번 열의 한 칸 왼쪽에 있다.
다음은 1초 동안 일어나는 일이며, 아래 적힌 순서대로 일어난다.
낚시왕은 가장 오른쪽 열의 오른쪽 칸에 이동하면 이동을 멈춘다.
1. 낚시왕이 오른쪽으로 한 칸 이동한다.
2. 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다.
상어를 잡으면 격자판에서 잡은 상어가 사라진다.
3. 상어가 이동한다.

*/
int R, C, M;
struct Shark {
	int s; // 속력
	int d; // 이동방향
	int z; // 크기
};
Shark map[102][102];
int dy[5] = { 0,-1,1,0,0 };
int dx[5] = { 0,0,0,1,-1 };
struct Hunt {
	int y;
	int x;
};
Hunt hunter = { 0,0 }; //낚시왕은 처음에 1번 열의 한 칸 왼쪽에 있다.
int sum;

void input() {
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		int y = 0, x = 0, s = 0, d = 0, z = 0;
		cin >> y >> x >> s >> d >> z;
		map[y][x] = { s,d,z };
	}
}
void move_shark() {
	for (int y = 1; y <= R; y++) {
		for (int x = 1; x <= C; x++) {
			if (map[y][x].z) {
				int ny = y + (dy[map[y][x].d] * map[y][x].s);
				int nx = x + (dx[map[y][x].d] * map[y][x].s);
				if (ny < 1) {
					ny = abs(ny - 2);
					map[y][x].d = 2;
				}
				else if (nx < 1) {
					nx = abs(nx - 2);
					map[y][x].d = 3;
				}
				else if (ny > R) {
					ny = R + ((ny - R) * -1);
					map[y][x].d = 1;
				}
				else if (nx > C) {
					nx = C + ((nx - C) * -1);
					map[y][x].d = 4;
				}

				if (map[ny][nx].z) { // 이동할 곳에 상어가 있으면
					if (map[y][x].z > map[ny][nx].z) {// 잡아 먹는다.
						map[ny][nx].s = map[y][x].s;
						map[ny][nx].d = map[y][x].d;
						map[ny][nx].z = map[y][x].z;
						map[y][x] = { 0,0,0 };
					}
					else if (map[y][x].z < map[ny][nx].z) {// 잡아 먹힌다.
						map[y][x] = { 0,0,0 };
					}
				}
				else {
					map[ny][nx].s = map[y][x].s;
					map[ny][nx].d = map[y][x].d;
					map[ny][nx].z = map[y][x].z;
					map[y][x] = { 0,0,0 };
				}
			}
		}
	}
}
void sol() {
	input();
	while (1) {
		++hunter.x;
		if (hunter.x == C + 1) break;

		for (int y = 1; y <= R; y++) {
			if (map[y][hunter.x].z) {
				sum += map[y][hunter.x].z;
				map[y][hunter.x] = { 0,0,0 };
				break;
			}
		}

		move_shark();

	}
	cout << sum;
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