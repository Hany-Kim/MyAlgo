#include <iostream>
#include <queue>
using namespace std;

int map[4][6];
int used[4][6];
struct Node{
	int y, x;
};
int cnt;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs(int y, int x) {
	queue<Node> q;
	q.push({ y,x });

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		used[now.y][now.x] = 1;

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= 4 || nx < 0 || nx >= 6 || used[ny][nx] == 1)continue;
			if (map[ny][nx] == 1)continue;

			if (map[ny][nx] == 2) {
				cnt++;
				map[ny][nx] = 0;
			}
			q.push({ ny,nx });
		}
	}
}

void sol() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 6; x++) {
			cin >> map[y][x];
		}
	}

	bfs(0, 0);
	cout << cnt;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}