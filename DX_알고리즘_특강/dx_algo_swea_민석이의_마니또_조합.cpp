#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define Dummy 213456789
#define Sdf 61490 //Standard_dijk_floyd

int TC;
int N, M;
vector<vector<int>> d;
int min_dist = Dummy;

struct Edge {
	int to;
	int dist;
};
//vector<vector<Edge>> graph;
deque<deque<Edge>> graph;


void init() {
	d.clear();
	graph.clear();
	min_dist = Dummy;
}
void input() {
	cin >> N >> M;
	if (Sdf > M) { // 다익
		//graph = vector<vector<Edge>>(N + 1, vector<Edge>());
		graph = deque<deque<Edge>>(N + 1, deque<Edge>());

		for (register int i = 0; i < M; ++i) {
			int from = 0, to = 0, dist = 0;
			cin >> from >> to >> dist;

			if (from == to) min_dist = dist;

			else graph[from].push_back({ to, dist });
		}
	}
	else { // 플와
		d = vector<vector<int>>(N + 1, vector<int>(N + 1, Dummy));

		for (register int i = 1; i <= N; ++i) {
			d[i][i] = 0;
		}

		for (register int i = 0; i < M; ++i) {
			int from = 0, to = 0, dist = 0;
			cin >> from >> to >> dist;

			if (from == to) {
				min_dist = min(min_dist, dist);
			}

			else d[from][to] = dist;
		}
	}
}
void floyd() {
	for (register int B = 1; B <= N; ++B) {
		for (register int A = 1; A <= N; ++A) {
			for (register int C = 1; C <= N; ++C) {
				if (d[A][C] > d[A][B] + d[B][C]) {
					d[A][C] = d[A][B] + d[B][C];
				}
			}
		}
	}
}

void come_back() {
	for (register int y = 1; y <= N; ++y) {
		for (register int x = 1; x <= N; ++x) {
			if (y == x) continue;
			else {
				if (min_dist > d[y][x] + d[x][y]) min_dist = d[y][x] + d[x][y];
			}
		}
	}
}
bool operator<(Edge left, Edge right) {
	if (left.dist < right.dist) return false;
	if (left.dist > right.dist) return true;

	if (left.to < right.to) return false;
	if (left.to > right.to) return true;

	return false;
}
void dijkstra() {
	for (register int node = 1; node <= N; ++node) {
		bool flag = false;
		vector<int> dist(N + 1, Dummy);
		vector<int> used(N + 1, 0);

		priority_queue<Edge> pq;

		dist[node] = 0;
		pq.push({ node, 0 });

		while (!pq.empty()) {
			Edge now = pq.top();
			pq.pop();

			if (used[now.to] == 1) continue;
			used[now.to] = 1;

			for (register int i = 0; i < graph[now.to].size(); ++i) {
				Edge edge = graph[now.to][i];

				if (edge.to == node) {
					int nDist = dist[now.to] + edge.dist;
					if (nDist < min_dist) min_dist = nDist;
					flag = true;
					break;
				}
				if (dist[edge.to] >= min_dist) {
					break;
				}
				if (dist[edge.to] <= dist[now.to] + edge.dist) continue;
				dist[edge.to] = dist[now.to] + edge.dist;
				pq.push({ edge.to, dist[edge.to] });
			}
			if (flag) break;
		}
	}
}
void sol() {
	if (Sdf > M) {
		dijkstra(); // O (N * M * log N)
	}
	else {
		floyd(); // O (N * N * N)
		come_back(); // O (N * N)
	}
	if (min_dist == Dummy) cout << -1;
	else cout << min_dist;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	cin >> TC;
	for (register int testcase = 1; testcase <= TC; ++testcase) {
		cout << "#" << testcase << " ";
		input();
		sol(); // O (N * M * log N)
		cout << "\n";
		init();
	}
	return 0;
}