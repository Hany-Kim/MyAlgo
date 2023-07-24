#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int TC;
int n, m, t;
int s, g, h;
int gtoh;
vector<pair<int,int>> v[2010];
vector<int> goal_candiate;
int dummy = 2134567890;
int sDist[2010];
int gDist[2010];
int hDist[2010];

void init() {
	for (int i = 0; i < 2010; i++) {
		v[i].clear();
		sDist[i] = dummy;
		gDist[i] = dummy;
		hDist[i] = dummy;
	}
	goal_candiate.clear();
}

void input() {
	cin >> n >> m >> t; // n : 교차로, m : 도로갯수, t : 목적지 후보
	cin >> s >> g >> h; // s : 출발지, g - h : 사이의 도로를 지남
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	for (int i = 0; i < t; i++) { // goal_candiate : 목적지 후보
		int x;
		cin >> x;
		goal_candiate.push_back(x);
	}
}

void dijkstra(int s, int dist[2010]) {
	priority_queue<pair<int,int>> pq;
	pq.push(make_pair( 0,s ));
	dist[s] = 0;

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int Next = v[now][i].first;
			int nCost = v[now][i].second;

			if (dist[Next] <= cost + nCost)continue;
			dist[Next] = cost + nCost;
			pq.push(make_pair(-dist[Next], Next));
		}
	}
}

void sol() {
	init();
	input();
	dijkstra(s, sDist);
	dijkstra(g, gDist);
	gtoh = gDist[h];
	dijkstra(h, hDist);

	sort(goal_candiate.begin(), goal_candiate.end());
	for (int i = 0; i < goal_candiate.size(); i++) {
		//int Dest = goal_candiate[i];
		if (sDist[goal_candiate[i]] == sDist[g] + gtoh + hDist[goal_candiate[i]]) cout << goal_candiate[i] << ' ';
		else if (sDist[goal_candiate[i]] == sDist[h] + gtoh + gDist[goal_candiate[i]]) cout << goal_candiate[i] << ' ';
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> TC;
	for (int i = 0; i < TC; i++) {
		sol();
		cout << "\n";
	}

	return 0;
}