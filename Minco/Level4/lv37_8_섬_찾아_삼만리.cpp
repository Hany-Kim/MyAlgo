#include <iostream>
#include <queue>
using namespace std;

int map[100][100];
int used[100][100];
struct Node
{
	int y, x;
};
int N, M;
int landCnt;

void bfs(int y, int x) {
	queue<Node> q;

	q.push({ y,x });
	used[y][x] = landCnt;

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		int dy[4] = { 0,1,0,-1 };
		int dx[4] = { 1,0,-1,0 };
		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M || used[ny][nx] != 0)continue;
			if (map[ny][nx] != 1)continue;

			used[ny][nx] = landCnt;

			q.push({ ny,nx });
		}
	}
}

void sol() {
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] == 1 && used[y][x]==0) {
				landCnt++;
				bfs(y,x);
			}
		}
	}
	cout << landCnt;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}