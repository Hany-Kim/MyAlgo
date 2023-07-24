#include <iostream>
#include <queue>
using namespace std;

int map[4][4] = {
	0,0,0,0,
	1,1,0,1,
	0,0,0,0,
	1,0,1,0
};
struct Node {
	int y;
	int x;
};
Node start;
Node arrival;
int used[4][4];

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void bfs(int y, int x) {
	queue<Node> q;
	q.push({ y,x });
	used[y][x] = 1;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || used[ny][nx] != 0)continue;
			if (used[ny][nx] == 0) {
				used[ny][nx] = used[now.y][now.x] + 1;
				q.push({ ny,nx });
			}
		}
	}

}

void sol() {
	cin >> start.y >> start.x;
	cin >> arrival.y >> arrival.x;

	bfs(start.y, start.x);
	cout << used[arrival.y][arrival.x] - 1 << "ȸ";
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}