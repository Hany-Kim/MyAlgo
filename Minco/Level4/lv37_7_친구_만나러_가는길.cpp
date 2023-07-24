#include <iostream>
#include <queue>
using namespace std;

int N, M;
int map[20][20];
struct Node{
	int y, x;
};

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int bfs(Node start, Node arrival) {
	int used[20][20] = { 0, };
	queue<Node> q;
	q.push(start);
	used[start.y][start.x] = 1;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M || used[ny][nx] != 0 || map[ny][nx] == 1)continue;

			used[ny][nx] = used[now.y][now.x] + 1;
			if (arrival.y == ny && arrival.x == nx) return used[ny][nx]-1;

			q.push({ ny,nx });

		}
	}

}

void sol() {
	cin >> N >> M;
	Node S = { 0,0 };
	Node D = { 0,0 };
	Node C = { 0,0 };
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			char t = ' ';
			cin >> t;
			if (t == 'x')map[y][x] = 1;
			else if (t == '.')map[y][x] = 0;
			else if (t == 'S') {
				S = { y,x };
				map[y][x] = 0;
			}
			else if (t == 'D') {
				D = { y,x };
				map[y][x] = 0;
			}
			else if (t == 'C') {
				C = { y,x };
				map[y][x] = 0;
			}
		}
	}
	int de = 1;

	cout << bfs(S, C) + bfs(C, D);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}