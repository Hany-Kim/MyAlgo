#include <iostream>
#include <queue>
using namespace std;

int V, E, K;
struct Edge
{
	int to;
	int dist;
};
vector<vector<Edge>>edgeInfo;

void input() {
	cin >> V >> E >> K;
	edgeInfo = vector<vector<Edge>>(V + 1);
	for (int i = 0; i < E; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		edgeInfo[from].push_back({ to, dist });
	}
}

bool operator<(Edge left, Edge right) {
	if (left.dist < right.dist) return false;
	if (left.dist > right.dist) return true;

	return false;
}

void sol() {
	input();
	
	vector<int>dist(V + 1, 2134567890);
	vector<int>used(V + 1);
	priority_queue<Edge> pq;

	dist[K] = 0;
	pq.push({ K,0 });

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (used[now.to] == 1)continue;
		used[now.to] = 1;

		for (int i = 0; i < edgeInfo[now.to].size(); i++) {
			Edge next = edgeInfo[now.to][i];

			if (dist[next.to] <= dist[now.to] + next.dist)continue;
			dist[next.to] = dist[now.to] + next.dist;
			pq.push({ next.to, dist[next.to] });
		}
	}

	for (int i = 1; i < dist.size(); i++) {
		if (dist[i] == 2134567890) cout << "INF\n";
		else cout << dist[i] << "\n";
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