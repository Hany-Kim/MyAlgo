#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
/*
한 칸에는 물고기가 최대 1마리 존재한다.

아기 상어와 물고기는 모두 크기를 가지고 있고, 이 크기는 자연수이다

아기 상어는 1초에 상하좌우로 인접한 한 칸씩 이동
아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고,
나머지 칸은 모두 지나갈 수 있다.
크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.

더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.
먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
	거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때,
		지나야하는 칸의 개수의 최솟값이다.
	거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기,
		그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.

아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다.
예를 들어, 크기가 2인 아기 상어는 물고기를 2마리 먹으면 크기가 3이 된다.

*/
int N;
int map[21][21];
int used[21][21];
struct Shark {
	int y;
	int x;
	int size;
	int eat_num;
	int time;
};
Shark baby_shark;
struct Fish {
	int y;
	int x;
	int dist;
};
vector<Fish> fish_list;
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,-1,1,0 };

void input() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 9) {
				baby_shark = { y,x,2,0,0 }; //가장 처음에 아기 상어의 크기는 2
			}
		}
	}
}
void bfs(int y, int x){
	queue<Fish> q;
	q.push({ y,x,0 });
	used[y][x] = 1;

	while (!q.empty()) {
		Fish now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
			if (used[ny][nx]) continue;
			if (map[ny][nx] == 0) {
				used[ny][nx] = 1;
				q.push({ ny,nx,now.dist + 1 });
			}
			else if (map[ny][nx] < baby_shark.size) {
				Fish tmp = { ny,nx,now.dist + 1 };

				fish_list.push_back(tmp);
				used[ny][nx] = 1;
				q.push({ ny,nx,now.dist + 1 });
			}
			else if (map[ny][nx] == baby_shark.size) {
				used[ny][nx] = 1;
				q.push({ ny,nx,now.dist + 1 });
			}
		}
	}
}
bool fish_sort(Fish left, Fish right) {
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
void sol() {
	input();

	while (1) {
		fish_list.clear();
		memset(used, 0, sizeof(used));

		bfs(baby_shark.y, baby_shark.x);

		if (fish_list.size() == 0) {
			cout << baby_shark.time << '\n';
			break;
		}
		else if (fish_list.size() == 1) {
			map[fish_list[0].y][fish_list[0].x] = 9;
			map[baby_shark.y][baby_shark.x] = 0;
			baby_shark.y = fish_list[0].y;
			baby_shark.x = fish_list[0].x;
			baby_shark.eat_num++;
			baby_shark.time = baby_shark.time + fish_list[0].dist;

			if (baby_shark.eat_num == baby_shark.size) {
				baby_shark.eat_num = 0;
				baby_shark.size++;
			}
		}
		else {
			sort(fish_list.begin(), fish_list.end(), fish_sort);
			map[fish_list[0].y][fish_list[0].x] = 9;
			map[baby_shark.y][baby_shark.x] = 0;
			baby_shark.y = fish_list[0].y;
			baby_shark.x = fish_list[0].x;
			baby_shark.eat_num++;
			baby_shark.time = baby_shark.time + fish_list[0].dist;

			if (baby_shark.eat_num == baby_shark.size) {
				baby_shark.eat_num = 0;
				baby_shark.size++;
			}
		}
	}
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}