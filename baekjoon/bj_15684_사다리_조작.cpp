#include <iostream>
using namespace std;

int N, M, H; // N : 세로 , M : 가로 , H : 가로선 개수
struct Edge {
	int map;
	int visit;
};
Edge sadari[11][30];
int ans = 9999999;

void input() {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) { // 사다리 가로선 다리 놓기
		int a = 0, b = 0;
		cin >> a >> b;
		sadari[b][a].visit = 1;
	}
}
bool start_game() { // 사다리 도착 지점 찾기
	for (int i = 1; i <= N; i++) {
		int cur_num = i;
		for (int j = 1; j <= H; j++) {
			if (sadari[cur_num][j].visit == 1) cur_num = cur_num + 1;
			else if (sadari[cur_num - 1][j].visit == 1)cur_num = cur_num - 1;
		}
		if (cur_num != i) return false;
	}
	return true;
}

void selec_line(int idx, int cnt) {
	if (cnt >= 4) return;
	if (start_game() == true) {
		if (ans > cnt) ans = cnt;
		return;
	}

	for (int i = idx; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (sadari[j][i].visit == 1) continue;
			if (sadari[j - 1][i].visit == 1) continue;
			if (sadari[j + 1][i].visit == 1) continue;

			sadari[j][i].visit = 1;
			selec_line(i, cnt + 1);
			sadari[j][i].visit = 0;
		}
	}
}
void sol() {
	input();
	selec_line(1, 0);
	if (ans == 9999999) ans = -1;
	cout << ans;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}