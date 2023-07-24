#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
/*
�� ĭ���� ����Ⱑ �ִ� 1���� �����Ѵ�.

�Ʊ� ���� ������ ��� ũ�⸦ ������ �ְ�, �� ũ��� �ڿ����̴�

�Ʊ� ���� 1�ʿ� �����¿�� ������ �� ĭ�� �̵�
�Ʊ� ���� �ڽ��� ũ�⺸�� ū ����Ⱑ �ִ� ĭ�� ������ �� ����,
������ ĭ�� ��� ������ �� �ִ�.
ũ�Ⱑ ���� ������ ���� �� ������, �� ����Ⱑ �ִ� ĭ�� ������ �� �ִ�.

�� �̻� ���� �� �ִ� ����Ⱑ ������ ���ٸ� �Ʊ� ���� ���� ���� ������ ��û�Ѵ�.
���� �� �ִ� ����Ⱑ 1�������, �� ����⸦ ������ ����.
���� �� �ִ� ����Ⱑ 1�������� ���ٸ�, �Ÿ��� ���� ����� ����⸦ ������ ����.
	�Ÿ��� �Ʊ� �� �ִ� ĭ���� ����Ⱑ �ִ� ĭ���� �̵��� ��,
		�������ϴ� ĭ�� ������ �ּڰ��̴�.
	�Ÿ��� ����� ����Ⱑ ���ٸ�, ���� ���� �ִ� �����,
		�׷��� ����Ⱑ �����������, ���� ���ʿ� �ִ� ����⸦ �Դ´�.

�Ʊ� ���� �ڽ��� ũ��� ���� ���� ����⸦ ���� �� ���� ũ�Ⱑ 1 �����Ѵ�.
���� ���, ũ�Ⱑ 2�� �Ʊ� ���� ����⸦ 2���� ������ ũ�Ⱑ 3�� �ȴ�.

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
				baby_shark = { y,x,2,0,0 }; //���� ó���� �Ʊ� ����� ũ��� 2
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