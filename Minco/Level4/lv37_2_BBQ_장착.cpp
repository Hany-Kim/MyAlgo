#include <iostream>
#include <queue>
using namespace std;

int h,w;
vector<vector<int>> map;
struct Node
{
	int y;
	int x;
};

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void sol() {
	cin >> h >> w;
	map = vector<vector<int>>(h);

	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			int t;
			cin >> t;
			map[y].push_back(t);
		}
	}

	int y, x;
	cin >> y >> x;
	Node start = { y,x };

	vector<vector<int>> dist(h, vector<int>(w));
	vector<vector<int>> used(h,vector<int>(w));
	queue<Node> q;
	int sec = 0;

	q.push(start);

	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		used[now.y][now.x] = 1;

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= h || nx < 0 || nx >= w || used[ny][nx] == 1)continue;
			if (map[ny][nx] == 1)continue;

			if (map[ny][nx] == 0) {
				dist[ny][nx] = dist[now.y][now.x] + 1;
				if (dist[ny][nx] > sec) {
					sec = dist[ny][nx];
				}
			}
			q.push({ ny,nx });
		}
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