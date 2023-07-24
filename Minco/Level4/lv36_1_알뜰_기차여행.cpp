#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, e;
struct Edge {
	int to;
	int dist;
};
vector<vector<Edge>> v;

void input() {
	cin >> n >> e;
	// [1] 그래프 구성
	// 인접 리스트형태 저장
	v = vector<vector<Edge>> (n + 1, vector<Edge>());
	for (int i = 0; i < e; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		v[from].push_back({ to, dist });
	}
}

bool operator<(Edge left, Edge right) {
	if (left.dist < right.dist)return true;
	if (left.dist > right.dist)return false;

	if (left.to < right.to)return true;
	if (left.to > right.to)return false;

	return false;
}

void sol() { // dijkstra
	input();
	vector<int> dist(n + 1, 2134567890);
	vector<int> used(n + 1, 0);

	// [2] queue 생성
	priority_queue<Edge> pq;

	// [3] 시작점 세팅
	dist[0] = 0;
	pq.push({ 0,0 });

	//[7] 4~6 반복
	while(!pq.empty()) {
		//[4] now : 꺼내기
		Edge now = pq.top();
		pq.pop();

		int nowDist = now.dist;
		int nowNode = now.to;
		if (used[nowNode] == 1) continue;
		used[nowNode] = 1;

		// [5] next찾기
		for (int i = 0; i < v[nowNode].size(); i++) {
			Edge edge = v[nowNode][i];
			int to = edge.to;
			int d = edge.dist;

			if (dist[to] <= dist[nowNode] + d)continue;
			// [6] next를 queue에 추가
			dist[to] = dist[nowNode] + d;
			pq.push({ to, dist[to] });
		}
	}

	if (dist[n - 1] == 2134567890) {
		cout << "impossible";
	}
	else cout << dist[n - 1];
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}