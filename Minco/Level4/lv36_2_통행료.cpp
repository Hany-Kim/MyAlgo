#include <iostream>
#include <queue>
using namespace std;

int N, M, K;
int s, a;
struct Edge {
	int to;
	int dist;
};
vector<vector<Edge>> relation; // f~t�� ����ᰡ c || M�� �Է�
vector<int> year;

void input() {
	cin >> N >> M >> K;
	relation = vector<vector<Edge>>(N + 1);
	cin >> s >> a;
	// [1] �׷��� ����
	for (int i = 0; i < M; i++) {
		int from, to, dist;
		cin >> from >> to >> dist;
		relation[from].push_back({to,dist});
		relation[to].push_back({ from,dist });
	}
	year.push_back(0);
	for (int i = 0; i < K; i++) {
		int t;
		cin >> t;
		year.push_back(t);
	}
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
	int increase = 0;
	for(int j=0; j<=K; j++){
		increase += year[j];
		vector<int>dist(N + 1, 2134567890);
		vector<int>used(N + 1, 0);
		// [2] queue ����
		priority_queue<Edge> pq;
		// [3] ������ ����
		dist[s] = 0;
		pq.push({ s, 0 });
		
		// [7] 4~6 �ݺ�
		while (!pq.empty()) {
			//[4] now : ������
			Edge now = pq.top();
			pq.pop();

			int nowNode = now.to;
			int nowDist = now.dist;
			if (used[nowNode] == 1)continue;
			used[nowNode] = 1;

			//[5] nextã��
			for (int i = 0; i < relation[nowNode].size(); i++) {
				Edge next = relation[nowNode][i];
				int nextNode = next.to;
				int nextDist = next.dist + increase;

				if (dist[nextNode] <= dist[nowNode] + nextDist) continue;
				//[6] next�� queue�� �߰�
				dist[nextNode] = dist[nowNode] + nextDist;
				pq.push({ nextNode, dist[nextNode] });
			}
		}
		cout << dist[a] << '\n';

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