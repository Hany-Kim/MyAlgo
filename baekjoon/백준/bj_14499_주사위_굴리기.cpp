#include <iostream>
#include <vector>
using namespace std;

int N, M;
int xx, yy, K;
int map[21][21];
int dy[5] = { 0,0,0,-1,1 }; // 동 서 북 남
int dx[5] = { 0,1,-1,0,0 };
int order[1001];
int cmd;
vector<int> dice(7);

void input() {
	cin >> N >> M >> xx >> yy >> K;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> order[i];
	}
}
void sol() {
	input();
	for (int i = 0; i < K; i++) {
		int ny = dy[order[i]]; // 맵상의 주사위 위치 이동
		int nx = dx[order[i]];
		if (ny + yy < 0 || ny + yy >= N || nx + xx < 0 || nx + xx >= M) continue;

		yy += ny;
		xx += nx;

		if (order[i] == 1) {
			dice = { 0,dice[4],dice[2],dice[1],dice[6],dice[5],dice[3] };
		}
		else if (order[i] == 2) {
			dice = { 0,dice[3],dice[2],dice[6],dice[1],dice[5],dice[4] };
		}
		else if (order[i] == 3) {
			dice = { 0,dice[5],dice[1],dice[3],dice[4],dice[6],dice[2] };
		}
		else if (order[i] == 4) {
			dice = { 0,dice[2],dice[6],dice[3],dice[4],dice[1],dice[5] };
		}

		cout << dice[1] << '\n';
		if (map[yy][xx] == 0) {
			map[yy][xx] = dice[6];
		}
		else {
			dice[6] = map[yy][xx];
			map[yy][xx] = 0;
		}
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