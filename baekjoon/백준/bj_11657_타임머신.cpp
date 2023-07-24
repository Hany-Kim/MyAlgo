#define 
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int N, M, A, B, C;
vector<pair<int, long long>> v[501]; // to, dist
long long dist[501];
int dummy = 2134567890;
int flag;

void init() {
	for (int i = 0; i < 501; i++) {
		dist[i] = dummy;
	}
}

void input() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &A, &B, &C);
		v[A].push_back(make_pair(B, C));
		//v[B].push_back(make_pair(A, C));
	}
}

void dijkstra(int start) {
	priority_queue<pair<int, long long>> pq;

	pq.push(make_pair(start, 0));
	dist[start] = 0;

	while (!pq.empty()) {
		int now = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nCost = v[now][i].second;

			if (dist[next] < dist[now] + nCost)continue;
			if (dist[start] < 0) {
				flag = 1;
				break;
			}
			dist[next] = dist[now] + nCost;
			pq.push(make_pair(next, dist[next]));
		}
		if (flag) break;
	}
}

void sol() {
	init();
	input();

	dijkstra(1);

	if (flag) printf("%d", -1);
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == dummy || dist[i] < 0)printf("%d\n", -1);
			else printf("%d\n", dist[i]);
		}
	}
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);
	sol();

	return 0;
}