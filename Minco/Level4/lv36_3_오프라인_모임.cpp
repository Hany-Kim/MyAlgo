#include <iostream>
#include <queue>
using namespace std;

int N, P, M; // ���ڸ��� -> P -> ���ڸ���
struct Edge
{
	int to;
	int dist;
};
vector<vector<Edge>> v;

void input() {
	cin >> N >> M >> P;
	v = vector<vector<Edge>>(N + 1);
	for (int i = 0; i < M; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		v[from].push_back({ to, dist });
	}
	// [1] �׷��� ����
}

bool operator<(Edge left, Edge right) {
	if (left.dist < right.dist) return false;
	if (left.dist > right.dist) return true;

	//if (left.to < right.to) return true;
	//if (left.to > right.to)return false;

	return false;
}

void sol() {
	input();
	vector<int> record(N + 1);
	for (int i = 1; i <= N; i++) {
		// [2] queue ����
		priority_queue<Edge> pq;
		vector<int>dist(N + 1, 2134567890);
		vector<int>used(N + 1);

		// [3] ������ ����
		if (i == P) continue;

		dist[i] = 0;
		pq.push({ i,0 });

		// [7] 4~6 �ݺ�
		while (!pq.empty()) {
			//[4] now : ������
			Edge now = pq.top();
			pq.pop();

			if (used[now.to] == 1)continue;
			used[now.to] = 1;

			//[5] nextã��
			for (int j = 0; j < v[now.to].size(); j++) {
				Edge next = v[now.to][j];

				if (dist[next.to] <= dist[now.to] + next.dist)continue;
				//[6] next�� queue�� �߰�
				dist[next.to] = dist[now.to] + next.dist;
				pq.push({next.to, dist[next.to]});
				
			}
		}

 		record[i] = dist[P];

		// ���ư���
		dist = vector<int>(N + 1, 2134567890);
		used = vector<int>(N + 1);

		dist[P] = 0;
		pq.push({ P,0 });

		while (!pq.empty()) {
			Edge now = pq.top();
			pq.pop();

			if (used[now.to] == 1)continue;
			used[now.to] = 1;

			for (int j = 0; j < v[now.to].size(); j++) {
				Edge next = v[now.to][j];

				if (dist[next.to] <= dist[now.to] + next.dist)continue;
				dist[next.to] = dist[now.to] + next.dist;
				pq.push({ next.to,dist[next.to] });
			}
		}

		record[i] += dist[i];
	}

	int max = 0;
	for (int i = 0; i < record.size(); i++) {
		if (max < record[i])max = record[i];
	}
	cout << max;
	
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}