//#include <iostream>
//#include <queue>
//using namespace std;
//
//int map[4][4];
//int used[4][4];
//struct Node {
//	int y;
//	int x;
//};
//int dy[4] = { -1,1,0,0 };
//int dx[4] = { 0,0,-1,1 };
//int landsize;
//
//void bfs(int y, int x) {
//	queue<Node> q;
//
//	q.push({ y,x });
//	used[y][x] = 1;
//
//	while (!q.empty()) {
//		Node now = q.front();
//		q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int ny = now.y + dy[i];
//			int nx = now.x + dx[i];
//
//			if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || used[ny][nx] != 0)continue;
//			if (map[ny][nx] == 1) {
//				used[ny][nx] = 1;
//				q.push({ ny, nx });
//			}
//		}
//	}
//}
//
//void sol() {
//	for (int y = 0; y < 4; y++) {
//		for (int x = 0; x < 4; x++) {
//			cin >> map[y][x];
//		}
//	}
//
//	bfs(0, 0);
//
//	for (int y = 0; y < 4; y++) {
//		for (int x = 0; x < 4; x++) {
//			if (used[y][x] == 1) landsize++;
//		}
//	}
//	cout << landsize;
//}
//
//int main() {
//	freopen_s(new FILE*, "input.txt", "r", stdin);
//
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//
//	sol();
//
//	return 0;
//}

#include <iostream>
#include <queue>
using namespace std;

struct Node { int y; int x; };
int direct[4][2] = { -1,0,1,0,0,1,0,-1 };

int map[4][4];
int used[4][4];

Node q[11000];
int h, t;

int main()
{
	freopen_s(new FILE*, "input.txt", "r", stdin);
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> map[y][x];
		}
	}

	q[t++] = { 0, 0 };
	used[0][0] = 1;

	while (h != t) {
		Node now = q[h++];
		for (int i = 0; i < 8; i++) {
			int ny = now.y + direct[i][0];
			int nx = now.x + direct[i][1];
			if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
			if (map[ny][nx] == 0) continue;
			if (used[ny][nx] == 1) continue;
			used[ny][nx] = 1;

			q[t++] = { ny, nx };
		}
	}

	cout << t;

	return 0;
}