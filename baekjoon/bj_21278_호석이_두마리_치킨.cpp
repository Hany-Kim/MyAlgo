#include <iostream>
#include <queue>
using namespace std;

// N개의 건물, M개의 도로

int N, M;
int route[6][6];
int build1, build2;
int used[6];
int time_taken_result1[6];
int time_taken_result2[6];


void bfs(int start) {
	queue<int> q;
	used[start] = 1;
	q.push(start);

	while (!q.empty()) {
		int now = q.front();
		q.pop();

		cout << now << " " << endl;
		for (int to = 1; to <= N; to++) {
			if (route[now][to] == 0 || used[to] != 0)continue;
			used[to] = 1;
			q.push(to);
		}
	}
}

int main() {
	// input----------------------------------------------------------------------------------------------
	freopen_s(new FILE*, "input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int y, x;
		cin >> y >> x;

		route[y][x] = 1;
		route[x][y] = 1;
	}
	//----------------------------------------------------------------------------------------------------
	
	// set build ----------------------------------------------------------------------------------------
	bfs(1);
	/*for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (y == x)continue;
			build1 = y;
			build2 = x;
			bfs(y);
			bfs(x);
		}
	}*/
	
	//----------------------------------------------------------------------------------------------------
	return 0;
}