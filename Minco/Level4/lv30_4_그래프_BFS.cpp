#include <iostream>
#include <queue>
using namespace std;

int arr[6][6] = {
	0,0,0,0,1,0,
	1,0,1,0,0,1,
	1,0,0,1,0,0,
	1,1,0,0,0,0,
	0,1,0,1,0,1,
	0,0,1,1,0,0
};
bool used[6];
int startNode;
queue<int> q;

void bfs() {
	used[startNode] = 1;
	q.push(startNode);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		cout << now << endl;

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

	cin >> startNode;
	bfs();

	return 0;
}