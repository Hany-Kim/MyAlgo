#include <iostream>
#include <queue>
using namespace std;

int my, mx, N;
vector<vector<int>>map;
int tired;
struct Node
{
	int y;
	int x;
	int weight;
};
vector<vector<int>>dist;
Node mmax;

int direct[2][4] = {
	-1,1,0,0,
	0,0,-1,1
};

void input() {
	cin >> my >> mx >> N;
	map = vector<vector<int>>(N);

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int t;
			cin >> t;
			map[y].push_back(t);
		}
	}
}

bool operator<(Node left, Node right) {
	if (left.weight < right.weight) return true;
	if (left.weight > right.weight)return false;

	return false;
}

void dijkstra() {
	dist = vector<vector<int>>(N, vector<int>(N, 2134567890));
	vector<vector<int>>used(N, vector<int>(N));

	priority_queue<Node> pq;

	dist[my][mx] = map[my][mx];
	pq.push({ my,mx,map[my][mx]});

	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();

		//if (used[now.y][now.x] == 1)continue;
		//used[now.y][now.x] = 1;
		if (now.weight > dist[now.y][now.x])continue;

		for (int i = 0; i < 4; i++) {
			int dy = now.y + direct[0][i];
			int dx = now.x + direct[1][i];

			if (dy < 0 || dy >= N || dx < 0 || dx >= N || map[dy][dx] == -1)continue;
			
			Node next = { dy,dx,map[dy][dx] };

			if (dist[dy][dx] <= dist[now.y][now.x] + next.weight) continue;
			dist[dy][dx] = dist[now.y][now.x] + next.weight;
			pq.push({ dy,dx,dist[dy][dx] });
		}
	}


	int de = 1;
}

void choice() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (dist[y][x] == 2134567890) continue;
			if (mmax.weight < dist[y][x]) {
				mmax = { y,x,dist[y][x] };
			}
		}
	}
}

void sol() {
	input();
	dijkstra();
	choice(); //가장 피로도 높은곳으로 이동
	cout << mmax.weight;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}