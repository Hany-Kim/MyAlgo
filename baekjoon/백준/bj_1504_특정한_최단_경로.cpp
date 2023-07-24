#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int N, E;
struct Edge {
	int to;
	int dist;
};
vector<vector<Edge>> v;
int wp1, wp2;
int dummy = 2134567890;

bool operator<(Edge left, Edge right) {
	if (left.dist < right.dist) return false;
	if (left.dist > right.dist)return true;

	return false;
}

long long dijkstra(int s, int e) {
	vector<int> dist(N + 1,dummy);
	//vector<int>used(N + 1, 0);
	priority_queue<Edge> q;

	q.push({ s,0 });
	dist[s] = 0;

	while (!q.empty()) {
		Edge now = q.top();
		q.pop();

		//if (used[now.to] == 1)continue;
		//used[now.to] = 1;

		for (int i = 0; i < v[now.to].size(); i++) {
			Edge next = v[now.to][i];

			if (dist[next.to]<=dist[now.to] + next.dist)continue;
			dist[next.to] = dist[now.to] + next.dist;

			q.push({ next.to, dist[next.to] });
		}
	}
	return dist[e];
}

void sol() {
	cin >> N >> E;
	v = vector<vector<Edge>>(N + 1);
	for (int i = 0; i < E; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		v[from].push_back({ to,dist });
		v[to].push_back({ from,dist });
	}
	cin >> wp1 >> wp2;

	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	long long w1 = dijkstra(1, wp1);
	long long w2 = dijkstra(wp2, N);
	if (w1 == dummy || w2 == dummy) flag1 = 1;
	long long w4 = dijkstra(wp2, 1);
	long long w3 = dijkstra(wp1, N);
	if (w3 == dummy || w4 == dummy) flag2 = 1;

	long long w = dijkstra(wp1, wp2);
	if (w == dummy)flag3 = 1;

	if ((flag1 == 1 && flag2 == 1) || flag3 == 1)cout << -1;
	else {
		long long minw = min(w1 + w2, w3 + w4);

		cout << minw + w;
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}