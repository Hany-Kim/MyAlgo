#include <iostream>
#include <queue>
using namespace std;
// 노드 방문 -> 출력
// 출발지점 입력
int arr[6][6] = {
	0,1,0,0,1,0,
	0,0,1,0,0,1,
	0,0,0,1,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0,
	0,0,0,0,0,0
};
int K;
bool used[6];
queue<int> q;

void bfs() {
	used[K] = 1;
	q.push(K);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << " ";

		for (int to = 0; to < 6; to++) {
			if (arr[now][to] == 0)continue;
			if (used[to] != 0)continue;

			used[to] = used[now] + 1;
			q.push(to);
		}
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> K;
	bfs();
	return 0;
}
