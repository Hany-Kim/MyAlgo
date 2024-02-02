#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define R_MAX (20 + 1)
#define C_MAX (20 + 1)
#define FOR(i,s,e) for(int i=s; i<e; ++i)

int R, C, K;
int map[R_MAX][C_MAX];
struct NODE {
	int y;
	int x;
	int d;
};
NODE heater[410]; // 온풍기 정보 저장
NODE target[410]; // 조사할 위치 정보 저장
int dy[5] = { 0,0,0,-1,1 }; // 동 서 북 남
int dx[5] = { 0,1,-1,0,0 };
int W;
int wall[R_MAX * 2][C_MAX * 2]; // 벽 위치 저장
int temper[R_MAX][C_MAX]; // 온도 저장
int h_cnt;	// 온풍기 갯수
int t_cnt;	// 조사할 위치 갯수
int chocolate; // 먹은 초콜릿 수

void add_heaterMap_to_temper(int heater_map[][C_MAX]) {
	FOR(y, 1, R + 1) {
		FOR(x, 1, C + 1) {
			temper[y][x] += heater_map[y][x];
		}
	}
}

void blow_from_heater(int num) {
	/*
	온풍기에서 바람이 분다.
	*/
	queue<pair<int, int>> q; // 탐색할 좌표를 순서대로 집어 넣음
	int heater_map[R_MAX][C_MAX] = { 0, }; // 바람이 불면서 몇도의 온도가 저장되는지 기록
	int used[R_MAX][C_MAX] = { 0, }; // 이미 바람이 지나갔는지 확인
	NODE* now_heater = &heater[num]; // heater배열에서 현재 온풍기에 대한 정보를 저장해둠

	// 온풍기에서 바람이 불기 시작하는 위치
	int sy = now_heater->y + dy[now_heater->d];
	int sx = now_heater->x + dx[now_heater->d];

	heater_map[sy][sx] = 5;
	used[sy][sx] = 1;
	q.push(make_pair(sy, sx));

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		FOR(i, 1, 5) {
			if (now_heater->d == 1 && i == 2) continue; // 온풍기 방향이 동쪽이면 서쪽은 탐색안함
			else if (now_heater->d == 2 && i == 1) continue; // 온풍기 방향이 서쪽이면 동쪽은 탐색안함
			else if (now_heater->d == 3 && i == 4) continue; // 온풍기 방향이 북쪽이면 남쪽은 탐색안함
			else if (now_heater->d == 4 && i == 3) continue; // 온풍기 방향이 남쪽이면 북쪽은 탐색안함

			// 현재 위치에 대한 벽의 유무를 파악
			int ty = (now.first * 2) - 1 + dy[i];
			int tx = (now.second * 2) - 1 + dx[i];
			if (ty < 1 || ty >((R * 2) - 1) || tx < 1 || tx >((C * 2) - 1)) continue; // 범위를 벗어난 벽을 탐색하지 않는지 확인
			if (wall[ty][tx] == 1) continue; // 벽에 막혔다면 탐색안함

			// 다음 바람이 불 다음 위치 업데이트
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];
			if (i != now_heater->d) {
				/*
					북쪽이나 남쪽이라면 바람이 불던 방향(동 or 서)으로 한번더 꺽어줘야함
					동쪽이나 서쪽이라면 바람이 불던 방향(북 or 남)으로 한번더 꺽어줘야함
				*/

				// 현재 위치에 대한 벽의 유무파악
				ty = (ny * 2) - 1 + dy[now_heater->d];
				tx = (nx * 2) - 1 + dx[now_heater->d];
				if (ty < 1 || ty >((R * 2) - 1) || tx < 1 || tx >((C * 2) - 1)) continue; // 범위를 벗어난 벽을 탐색하지 않는지 확인
				if (wall[ty][tx] == 1) continue; // 벽에 막혔다면

				// 다음 바람이 불 다음 위치 업데이트
				ny = ny + dy[now_heater->d];
				nx = nx + dx[now_heater->d];
			}

			if (ny < 1 || ny > R || nx < 1 || nx > C) continue; //맵 밖으로 바람이 불진 않는지 확인
			if (heater_map[ny][nx] != 0) continue; // 이미 바람이 불었던 위치가 아닌지 확인
			if (used[ny][nx] != 0) continue; // 이미 바람이 불었던 위치가 아닌지 확인

			if ((heater_map[now.first][now.second] - 1) < 1) continue; // 온도가 0이하라면 더이상 바람이 닿지 않음
			heater_map[ny][nx] = heater_map[now.first][now.second] - 1; // 다음 바람이 불 위치의 온도를 저장
			used[ny][nx] = 1; // 바람이 지나간 자리임을 표시
			q.push(make_pair(ny, nx));
		}
	}

	add_heaterMap_to_temper(heater_map);
}

void control_temper() {
	/*
	온도 조절
	*/
	int spread_temper[R_MAX][C_MAX] = { 0, }; // 온도 조절하기 위해 주변으로 퍼진 온도 값 저장
	int flow_out_temper[R_MAX][C_MAX] = { 0, }; // 온도 조절하기 위해 주변으로 퍼지기 위해 빠져나간 온도 값 저장

	FOR(y, 1, R + 1) {
		FOR(x, 1, C + 1) {
			spread_temper[y][x] = 0;
			flow_out_temper[y][x] = 0;
		}
	}

	FOR(y, 1, (R + 1)) {
		FOR(x, 1, (C + 1)) {
			if (temper[y][x] != 0) {
				FOR(i, 1, 5) {
					// 벽의 유무 확인
					int ty = (y * 2) - 1 + dy[i];
					int tx = (x * 2) - 1 + dx[i];
					if (ty < 1 || ty >((R * 2) - 1) || tx < 1 || tx >((C * 2) - 1)) continue;
					if (wall[ty][tx] == 1) continue;

					// 온도가 빠져나갈 좌표 확인
					int ny = y + dy[i];
					int nx = x + dx[i];
					if (ny<1 || ny > R || nx < 1 || nx > C) continue;

					if (temper[y][x] > temper[ny][nx]) {
						int L = (temper[y][x] - temper[ny][nx]) >> 2; // (두칸의 온도차 / 4)

						spread_temper[ny][nx] += L;
						flow_out_temper[y][x] -= L;
					}
				}
				flow_out_temper[y][x] += temper[y][x];
			}
		}
	}

	FOR(y, 1, (R + 1)) {
		FOR(x, 1, (C + 1)) {
			temper[y][x] = flow_out_temper[y][x] + spread_temper[y][x];
		}
	}
}

void decrease_outside_temper() {
	/*
	가장 바깥쪽 칸의 온도 1씩 감소
	*/
	FOR(x, 1, C) {
		if (temper[1][x] >= 1) {
			temper[1][x] -= 1;
		}
	}
	FOR(x, 2, (C + 1)) {
		if (temper[R][x] >= 1) {
			temper[R][x] -= 1;
		}
	}
	FOR(y, 2, (R + 1)) {
		if (temper[y][1] >= 1) {
			temper[y][1] -= 1;
		}
	}
	FOR(y, 1, R) {
		if (temper[y][C] >= 1) {
			temper[y][C] -= 1;
		}
	}
}

void eat_chocolate() {
	/* 초콜릿 먹기 */
	++chocolate;
}

bool isReachTargetTemper() {
	/* 목표 온도에 도달 했는지 */
	FOR(i, 0, t_cnt) {
		if (temper[target[i].y][target[i].x] < K) {
			return false;
		}
	}
	return true;
}

void sol() {
	while (isReachTargetTemper() == false) {
		FOR(i, 0, h_cnt) {
			blow_from_heater(i);
		}
		control_temper();
		decrease_outside_temper();
		eat_chocolate();
		if (chocolate > 100) {
			chocolate = 101;
			break;
		}
	}
	cout << chocolate;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> K;
	FOR(y, 1, (R + 1)) {
		FOR(x, 1, (C + 1)) {
			cin >> map[y][x];
			if (map[y][x] == 5) {
				target[t_cnt].y = y;
				target[t_cnt++].x = x;
			}
			else if (map[y][x] != 0) {
				heater[h_cnt].y = y;
				heater[h_cnt].x = x;
				heater[h_cnt++].d = map[y][x];
			}
		}
	}
	cin >> W;
	FOR(i, 0, W) {
		int r = 0, c = 0, d = 0;
		cin >> r >> c >> d;
		int y = (r * 2) - 1;
		int x = (c * 2) - 1;
		if (d == 0) {
			wall[y - 1][x] = 1;
		}
		else if (d == 1) {
			wall[y][x + 1] = 1;
		}
	}

	sol();

	return 0;
}