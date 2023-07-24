#include <iostream>
#include <queue>
using namespace std;

int P, C; // P : node , C : Edge
int K, A, B; // K -> A or B
vector<int>used;
struct Edge
{
	int to;
	int dist;
};
vector<vector<Edge>> v;

void input() {
	cin >> C >> P >> K >> A >> B;
	v = vector<vector<Edge>>(P + 1);
	for (int i = 0; i < C; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		v[from].push_back({ to,dist });
		v[to].push_back({ from,dist });
	}
}

bool operator<(Edge left, Edge right) {
	//if (left.dist < right.dist) return true;
	//if (left.dist > right.dist) return false;

	if (left.dist > right.dist) return true; // 우선순위가 ~~라면 true or false
	if (left.dist < right.dist) return false;

	return false;
}

int dijkstra(int s, int a) {
	vector<int>dist(P + 1, 2134567890);
	vector<int>used(P + 1);
	priority_queue <Edge> pq;

	dist[s] = 0;
	pq.push({ s,0 });

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (used[now.to] == 1)continue;
		used[now.to] = 1;

		for (int i = 0; i < v[now.to].size(); i++) {
			Edge next = v[now.to][i];

			if (dist[next.to] <= dist[now.to] + next.dist)continue;
			dist[next.to] = dist[now.to] + next.dist;
			pq.push({ next.to, dist[next.to] });
		}
	}
	return dist[a];
}

void sol() {
	input();
	// A -> B 거리는 공통
	int AtoB = dijkstra(A, B);
	// 이미 지나간 간선 빼고 (used)
	// K -> A or K -> B 최소 거리 비교
	int KtoA = dijkstra(K, A);
	int KtoB = dijkstra(K, B);

	int minDist = 0;
	if (KtoA < KtoB)minDist = AtoB + KtoA;
	else if (KtoA > KtoB)minDist = AtoB + KtoB;

	cout << minDist;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}