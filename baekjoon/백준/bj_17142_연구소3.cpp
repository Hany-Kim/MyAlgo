#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

// ���̷��� ���� : Ȱ / ��Ȱ
// ���� ��Ȱ
// Ȱ�� ���̷��� -> �����¿�� ���ÿ� ���� 1�ʼҿ�
// M���� ���̷��� Ȱ�����·�
// ������ N x N
// ��ĭ 0, �� 1, ���̷��� 2
// Ȱ���� ��Ȱ�� ������ ��Ȱ�� Ȱ���� ��
int N, M;
int map[51][51];
struct Point {
	int y;
	int x;
	int used;
};
vector<Point> virus_point;
vector<Point> path;
vector<int> sucess;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
int min_time = 213456789;
int spread_map[51][51];
int virus_used[51][51];

void input() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 2) virus_point.push_back({ y,x,0 });
		}
	}
}

void spread_virus() {
	memset(virus_used, -1, sizeof(virus_used));
	memset(spread_map, 0, sizeof(spread_map));

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x] == 1) spread_map[y][x] = -1; // ��
			if (map[y][x] == 2) spread_map[y][x] = -2; // ��Ȱ ���̷���
		}
	}
	queue<Point> q;
	for (int i = 0; i < path.size(); i++) {
		q.push(path[i]);
		virus_used[path[i].y][path[i].x] = 0;
		spread_map[path[i].y][path[i].x] = virus_used[path[i].y][path[i].x];
	}

	while (!q.empty()) {
		Point now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue; // �������̸� ������
			if (map[ny][nx] == 1) continue; // ���̸� ������
			if (virus_used[ny][nx] >= 0) continue; // �̹� Ȯ������� ������

			virus_used[ny][nx] = virus_used[now.y][now.x] + 1;
			if (spread_map[ny][nx] == 0) spread_map[ny][nx] = virus_used[ny][nx];
			q.push({ ny,nx,0 });
		}
	}

	int max_time = 0;
	int isSpace = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if ((spread_map[y][x] == 0) && (virus_used[y][x] == -1)) { // ���� ������� �ִ�
				isSpace = 1;
				break;
			}
			else if((map[y][x] != 1) && (spread_map[y][x] != -2))
				if ((spread_map[y][x] != -2) && (max_time < spread_map[y][x]))
					max_time = spread_map[y][x];
		}
		if (isSpace) break;
	}
	if (!isSpace && (min_time > max_time)) {
		min_time = max_time;
		sucess.push_back(0);
	}
	else if (isSpace) sucess.push_back(-1);
}

void select_virus(int lv, int num) {
	if (lv >= M) {
		spread_virus();

		return;
	}
	for (int i = num; i < virus_point.size(); i++) {
		if (virus_point[i].used) continue;
		path.push_back(virus_point[i]);
		virus_point[i].used = 1;
		select_virus(lv + 1, i);
		path.pop_back();
		virus_point[i].used = 0;
	}
}
void sol() {
	input();
	select_virus(0, 0);
	int all_fail = 1;
	for (int i = 0; i < sucess.size(); i++) {
		if (sucess[i] == 0) {
			all_fail = 0;
			break;
		}
	}
	if (!all_fail) cout << min_time;
	else if (all_fail) cout << -1;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}