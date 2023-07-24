#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int map[4][5];
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int copy_map[4][5];
int sec;
struct Node {
	int y, x;
};

void bfs(int y, int x) {
	queue<Node> q;
	Node start = { y,x };
	
	q.push(start);

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= 4 || nx < 0 || nx >= 5 || map[ny][nx] == 1)continue;
			if (copy_map[ny][nx] == 1)continue;

			copy_map[ny][nx] = 1;
		}
	}
}

void sol() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 5; x++) {
			cin >> map[y][x];
		}
	}

	while (1) {
		int flag = 1;
		sec++;
		memcpy(copy_map, map, sizeof map);
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 5; x++) {
				if (map[y][x] == 1) bfs(y, x);
			}
		}
		memcpy(map, copy_map, sizeof copy_map);

		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 5; x++) {
				if (map[y][x] == 0) {
					flag = 0;
					break;
				}
			}
			if (flag == 0)break;
		}

		if (flag) break;
	}
	cout << sec;

}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}