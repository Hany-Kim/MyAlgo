/*

N×N 크기의 격자
각 칸은 빈칸(0) or 벽(1)

if (택시가 빈칸에 있을 때,) than 상하좌우로 인접한 빈칸 중 하나로 이동
최단 경로로 인접한 빈칸 이동

M명의 승객은 빈칸 중 하나(출발지)에 서 있으며, 다른 빈칸 중 하나(목적지)로 이동하려고 한다
여러 승객이 같이 탑승하는 경우는 없다.
승객별로 출발지 - 목적지 정해져 있다.
한 승객을 태워 목적지로 이동시키는 일을 M번 반복해야 한다
각 승객은 스스로 움직이지 않으며, 출발지에서만 택시에 탈 수 있고, 목적지에서만 택시에서 내릴 수 있다.

태울 승객을 고를 때는 현재 위치에서 최단거리가 가장 짧은 승객을 고른다.
 if(그런 승객이 여러 명이면) than 그중 행 번호가 가장 작은 승객을
	if(그런 승객도 여러 명이면) than 그중 열 번호가 가장 작은 승객을 고른다
택시와 승객이 같은 위치에 서 있으면 그 승객까지의 최단거리는 0이다.

연료는 한 칸 이동할 때마다 1만큼 소모
한 승객을 목적지로 성공적으로 이동시키면, 그 승객을 태워 이동하면서 소모한 연료 양의 두 배가 충전된다.

이동하는 도중에 연료가 바닥나면 이동에 실패하고, 그 날의 업무가 끝난다
승객을 목적지로 이동시킨 동시에 연료가 바닥나는 경우는 실패한 것으로 간주하지 않는다.
*/
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define FOR(box,start,end)  for(register int box = start; box < end; ++box)
#define dummy 2134567890

int N, M;
int map[21][21];
struct Taxi {
	int y;
	int x;
	int fuel;
	int goal_num;
};
Taxi taxi_driver;
struct Client {
	int start_y;
	int start_x;
	int goal_y;
	int goal_x;
	bool isGoal = false;
};
Client cli_list[410];
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };
struct Node {
	int y;
	int x;
};
struct Info {
	int dist;
	int y;
	int x;
	int cli_num;
};

void input() {
	cin >> N >> M >> taxi_driver.fuel;
	FOR(y, 1, (N + 1)) {
		FOR(x, 1, (N + 1)) {
			cin >> map[y][x];
		}
	}
	cin >> taxi_driver.y >> taxi_driver.x;
	FOR(num, 2, (2 + M)) {
		cin >> cli_list[num].start_y >> cli_list[num].start_x >> cli_list[num].goal_y >> cli_list[num].goal_x;
		map[cli_list[num].start_y][cli_list[num].start_x] = num;
	}
}
void cpy_map(int (*cp_map)[21]) {
	FOR(y, 1, (N + 1)) {
		FOR(x, 1, (N + 1)) {
			cp_map[y][x] = map[y][x];
		}
	}
}
void init_used(int(*cp_map)[21]) {
	FOR(y, 1, (N + 1)) {
		FOR(x, 1, (N + 1)) {
			cp_map[y][x] = -1;
		}
	}
}
void pick_up_cli(int ty, int tx, int cost_fuel) {
	taxi_driver.y = ty;
	taxi_driver.x = tx;
	taxi_driver.fuel -= cost_fuel;
	taxi_driver.goal_num = map[ty][tx];
	map[ty][tx] = 0;
}
bool info_cmp(Info left, Info right) {
	if (left.dist <= right.dist) {
		if (left.dist == right.dist) {
			if (left.y <= right.y) {
				if (left.y == right.y) {
					if (left.x < right.x) {
						return true;
					}
					return false;
				}
				return true;
			}
			return false;
		}
		return true;
	}
	return false;
}
bool find_cli() {
	int used[21][21] = { 0, };
	init_used(used);

	//int cost_fuel_taxiToCli = 0; // 택시 - 승객 이동에 필요한 연료

	if (map[taxi_driver.y][taxi_driver.x] > 1) { // 택시 위치가 빈칸도 아니고, 벽도 아님 = 승객위치면
		pick_up_cli(taxi_driver.y, taxi_driver.x, 0); // 승객을 만나면 태운다.
		return true;
	}
	else if(map[taxi_driver.y][taxi_driver.x] == 0) { // 택시 출발 위치가 빈칸이면
		queue<Node> q;
		q.push({ taxi_driver.y, taxi_driver.x });
		used[taxi_driver.y][taxi_driver.x] = 0;
		vector<Info> v;

		while (!q.empty()) {
			Node now = q.front();
			q.pop();

			FOR(dir, 0, 4) {
				int ny = now.y + dy[dir];
				int nx = now.x + dx[dir];

				if (ny<1 || ny>N || nx<1 || nx>N)continue; // 맵 범위 벗어나면
				if (map[ny][nx] == 1 || used[ny][nx] != -1)continue;//벽이면 이미 지나간 곳이면

				used[ny][nx] = used[now.y][now.x] + 1;

				if (map[ny][nx] >= 2) { // 승객을 만났다면
					v.push_back({ used[ny][nx],ny,nx,map[ny][nx] });
				}
				else q.push({ ny,nx });
			}
		}

		if (v.size() == 0) return false;
		sort(v.begin(), v.end(), info_cmp);
		if (v[0].dist <= taxi_driver.fuel) { // 손님위치로 이동할 연료가 남아있으면
			pick_up_cli(v[0].y, v[0].x, used[v[0].y][v[0].x]); // 승객을 만나면 태운다.
			return true;
		}
		else { // 업무끝
			return false;
		}
	}
}
int find_goal() {
	int used[21][21] = { 0, };
	init_used(used);

	queue<Node> q;
	q.push({ taxi_driver.y, taxi_driver.x });
	used[taxi_driver.y][taxi_driver.x] = 0;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		FOR(dir, 0, 4) {
			int ny = now.y + dy[dir];
			int nx = now.x + dx[dir];

			if (ny<1 || ny>N || nx<1 || nx>N)continue; // 맵 범위 벗어나면
			if (map[ny][nx] == 1 || used[ny][nx] != -1)continue;//벽이면 이미 지나간 곳이면

			used[ny][nx] = used[now.y][now.x] + 1;

			if ((ny == cli_list[taxi_driver.goal_num].goal_y) && (nx == cli_list[taxi_driver.goal_num].goal_x)) { // 목적지 찾았다면
				//스타트 택시는 
				if (used[ny][nx] <= taxi_driver.fuel) { // 손님을 목적지로 데려다주면
					// 연료 충전 2배
					taxi_driver.fuel += used[ny][nx];
					taxi_driver.goal_num = 0;
					taxi_driver.y = ny;
					taxi_driver.x = nx;

					return true;
				}
				else { // 업무끝
					return false;
				}
				/*
				if (손님을 도착지로 데려다주면) than 연료가 충전
				if (연료가 바닥나면) than 그 날 업무가 끝난다.
				*/

				//return;
			}
			q.push({ ny,nx });
		}
	}

	return false;
}
void output() {

}
void sol() {

	FOR(cliNum, 0, M) { // 택시 기사는 오늘 M명의 승객을 태우는 것이 목표
		if (find_cli() == true) { // 가장 가까운 승객 찾아서 태우기
			if (find_goal() == true) { // 목적지로 이동 성공
				if ((M - 1) == cliNum)cout << taxi_driver.fuel;
			}
			else {
				cout << -1;
				break;
			}
		}
		else {
			cout << -1;
			break;
		}
	}
	
	int de = 1;
}
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	sol();
	return 0;
}