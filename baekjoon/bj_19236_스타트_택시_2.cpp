#include <iostream>
#include <queue>
using namespace std;

int N, M, fuel;
int map[21][21];
struct Taxi
{
	int sy, sx; // 택시 위치
	int fuel; // 택시 남은 연료
};
Taxi driver;
struct Cli {
	int sy, sx; // 승객 출발 위치
	int gy, gx; // 승객 도착 위치
};
Cli client[410];
int cli_map[21][21];
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };
struct Info { // 승객의 우선순위 저장
	int num; // 승객 번호
	int y, x;
	int dist; // 택시 - 승객 거리
};

void init(int (*bmap)[21]) {
	for (register int y = 1; y <= N; ++y) {
		for (register int x = 1; x <= N; ++x) {
			bmap[y][x] = -1;
		}
	}
}
void input() {
	cin >> N >> M >> fuel;
	for (register int y = 1; y <= N; ++y) {
		for (register int x = 1; x <= N; ++x) {
			cin >> map[y][x];
		}
	}
	cin >> driver.sy >> driver.sx;
	for (register int i = 1; i <= M; ++i) {
		cin >> client[i].sy >> client[i].sx >> client[i].gy >> client[i].gx;
		cli_map[client[i].sy][client[i].sx] = i; // 승객위치 기록
	}
}

bool sort_cli(Info left, Info right) {
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

void find_cli() { // 최단거리 손님 찾기
	queue<pair<int,int>> q;
	int used[21][21] = { 0, };
	init(used);

	q.push({ driver.sy, driver.sx });
	used[driver.sy][driver.sx] = 0;

	vector<Info> v;

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		for (register int i = 0; i < 4; ++i) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny<1 || ny>N || nx<1 || nx>N) continue; // 맵 밖 못감
			if (used[ny][nx] != -1) continue; // 이미 지나온 길이면 못감
			if (map[ny][nx] == 1)continue; // 벽이면 못감

			used[ny][nx] = used[now.first][now.second] + 1;
			if (cli_map[ny][nx] != 0) {
				v.push_back({ cli_map[ny][nx], ny, nx, used[ny][nx]});
			}

			q.push({ ny,nx });
		}
	}

	sort(v.begin(), v.end(), sort_cli);

	int dde = 1;
}
void sol() {
	input();

	find_cli();

	int de = 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}