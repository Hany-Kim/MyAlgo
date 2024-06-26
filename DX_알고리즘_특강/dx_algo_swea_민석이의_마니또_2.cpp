#include <iostream>
#include <queue>
using namespace std;


int TC;
int N, M;
struct Edge {
	int to;
	int dist;
};
vector<vector<Edge>> graph;
int min_dist = 213456789;

void init() {
	graph.clear();
	min_dist = 213456789;
}
void input() {
	cin >> N >> M;

	graph = vector<vector<Edge>>(N + 1, vector<Edge>());

	for (register int i = 0; i < M; ++i) {
		int from = 0, to = 0, dist = 0;
		cin >> from >> to >> dist;

		if (from == to) min_dist = dist;

		else graph[from].push_back({ to, dist });
	}
}
void ex_input() {
	N = 400;
	M = 400 * 399;

	graph = vector<vector<Edge>>(N + 1, vector<Edge>());

	/*
	for (int from = 1; from <= 400; ++from) {
		for (int to = 1; to <= 400; ++to) {
			if (from == to)continue;

			int dist = 10000;
			graph[from].push_back({ to, dist });
		}
	}
	graph[399].push_back({ 399, 1999 });
	*/

	for (int i = 0; i < 399; ++i) {
		for (int from = 1 + i; from < i + 2; ++from) {
			for (int to = from + 1; to < from + 2; ++to) {
				int dist = 1;
				graph[from].push_back({ to, dist });
			}
		}
	}
	graph[400].push_back({ 1, 1 });

	// O ( N )

}
bool operator<(Edge left, Edge right) {
	if (left.dist < right.dist) return false;
	if (left.dist > right.dist) return true;

	if (left.to < right.to) return false;
	if (left.to > right.to) return true;

	return false;
}
void dijkstra(int node) {
	vector<int> dist(N + 1, 213456789);
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
			}
			if (dist[edge.to] <= dist[now.to] + edge.dist) continue;
			dist[edge.to] = dist[now.to] + edge.dist;
			pq.push({ edge.to, dist[edge.to] });
			/*else if (dist[edge.to] > dist[now.to] + edge.dist) {
				dist[edge.to] = dist[now.to] + edge.dist;
				pq.push({ edge.to, dist[edge.to] });
			}*/
		}
	}
}
void sol() {
	for (register int node = 1; node <= N; ++node) {
		dijkstra(node); // O (M * log N)
	}
	if (min_dist == 213456789) cout << -1;
	else cout << min_dist;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//freopen("input.txt", "r", stdin);
	cin >> TC;
	for (register int testcase = 1; testcase <= TC; ++testcase) {
		cout << "#" << testcase << " ";
		init();
		input();
		//ex_input(); // O (M)
		sol(); // O (N * M * log N)
		cout << "\n";
	}
	return 0;
}
