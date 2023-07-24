#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N, L, R;
int A[50][50];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int day;
int used[50][50] = { 0, };

void bfs(int y, int x) {
	queue<pair<int, int>> q;
	queue<pair<int, int>> nq;
	
	q.push({ y,x });
	nq.push({ y,x });
	used[y][x] = 1;

	int sum = 0, cnt = 0;

	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();

		sum = sum + A[y][x];
		cnt = cnt + 1;

		for (int i = 0; i < 4; i++) {
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N)continue;
			if (used[ny][nx])continue;
			int diff = abs(A[now.first][now.second] - A[ny][nx]);
			if (diff >= L && diff <= R) {
				used[ny][nx] = 1;
				q.push({ ny,nx });
				nq.push({ ny,nx });
			}
		}
	}

	int value = sum / cnt;
	while (!nq.empty()) {
		pair<int, int> now = nq.front();
		nq.pop();
		A[now.first][now.second] = value;
	}
}
bool isMove(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= N || nx < 0 || nx >= N)continue;
		int diff = abs(A[y][x] - A[ny][nx]);
		if (diff >= L && diff <= R) return true;
	}
	return false;
}
void sol() {
	cin >> N >> L >> R;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> A[y][x];
		}
	}

	bool check = true;
	while (check) {
		check = false;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (!used[y][x] && isMove(y,x)) {
					bfs(y, x);
					check = true;
				}
			}
		}
		cout << "ee\n";
		if(check) day++;
		memset(used, 0, sizeof(used));
	}

	cout << day;


	int de = 1;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}