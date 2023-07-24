#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
하나의 말 위에 다른 말을 올릴 수 있다

*/

int N, K;
int turn;
int map[15][15];
//vector<vector<vector<int>>> h_map[15][15][15];
vector<vector<vector<int>>> h_map(15, vector<vector<int>>(15, vector<int>(15)));
struct Horse {
	int y;
	int x;
	int dir;
};
Horse arr[11];
int dy[5] = { 0,0,0,-1,1 }; // 이동 방향은 4보다 작거나 같은 자연수이고 1부터 순서대로 →, ←, ↑, ↓
int dx[5] = { 0,1,-1,0,0 };
int fourth_horse;

void input() {
	cin >> N >> K;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> map[y][x];
		}
	}

	for (int i = 1; i <= K; i++) {
		cin >> arr[i].y >> arr[i].x >> arr[i].dir; // 말은 1번부터 K번까지 번호가 매겨져 있고, 이동 방향도 미리 정해져 있다.
		int idx = 0;
		while (1) {
			if (h_map[arr[i].y][arr[i].x][idx] == 0) {
				h_map[arr[i].y][arr[i].x][idx] = i;
				break;
			}
			++idx;
		}
	}
}
void on_blue(int idx, int y, int x, int ny, int nx) {
	Horse now = { y,x,arr[idx].dir };
	/*
	파란색인 경우에는 A번 말의 이동 방향을 반대로 하고 한 칸 이동한다.
	방향을 반대로 바꾼 후에 이동하려는 칸이 파란색인 경우에는 이동하지 않고 가만히 있는다.
	*/
	vector<int> tmp;
	int s = 0;
	while (1) {
		if (h_map[now.y][now.x][s] == idx)break;
		++s;
	}
	int e = s;
	while (1) {
		if (h_map[now.y][now.x][e] == 0)break;
		tmp.push_back(h_map[now.y][now.x][e]);
		h_map[now.y][now.x][e] = 0;
		++e;
	}

	if (now.dir == 1) arr[idx].dir = 2;
	else if (now.dir == 2) arr[idx].dir = 1;
	else if (now.dir == 3) arr[idx].dir = 4;
	else if (now.dir == 4) arr[idx].dir = 3;

	int nny = now.y + dy[arr[idx].dir];
	int nnx = now.x + dx[arr[idx].dir];

	if (nny<1 || nny>N || nnx<1 || nnx>N) {
		int last_idx = 0;
		while (1) {
			if (h_map[now.y][now.x][last_idx] == 0)break;
			++last_idx;
		}
		for (int i = 0; i < tmp.size(); i++) {
			h_map[now.y][now.x][last_idx + i] = tmp[i];
			arr[tmp[i]] = { now.y, now.x, arr[tmp[i]].dir };
		}
	}
	else if (map[nny][nnx] == 2) {
		int last_idx = 0;
		while (1) {
			if (h_map[now.y][now.x][last_idx] == 0)break;
			++last_idx;
		}
		for (int i = 0; i < tmp.size(); i++) {
			h_map[now.y][now.x][last_idx + i] = tmp[i];
			arr[tmp[i]] = { now.y, now.x, arr[tmp[i]].dir };
		}
	}
	else if (map[nny][nnx] == 0) {
		int last_idx = 0;
		while (1) {
			if (h_map[nny][nnx][last_idx] == 0)break;
			++last_idx;
		}
		for (int i = 0; i < tmp.size(); i++) {
			h_map[nny][nnx][last_idx + i] = tmp[i];
			arr[tmp[i]] = { nny, nnx, arr[tmp[i]].dir };
		}
	}
	else if (map[nny][nnx] == 1) {
		reverse(tmp.begin(), tmp.end());
		int last_idx = 0;
		while (1) {
			if (h_map[nny][nnx][last_idx] == 0)break;
			++last_idx;
		}
		for (int i = 0; i < tmp.size(); i++) {
			h_map[nny][nnx][last_idx + i] = tmp[i];
			arr[tmp[i]] = { nny, nnx, arr[tmp[i]].dir };
		}
	}

	int maximum = 0;
	while (1) {
		if (h_map[nny][nnx][maximum] == 0) break;
		++maximum;
	}
	if (maximum >= 4) {
		fourth_horse = 1;
		return;
	}
}
void on_white(int idx, int y, int x, int ny, int nx) {
	Horse now = { y,x,arr[idx].dir };
	/*
	흰색인 경우에는 그 칸으로 이동한다.
		A번 말의 위에 다른 말이 있는 경우에는 A번 말과 위에 있는 모든 말이 이동한다
		예를 들어, A, B, C로 쌓여있고,
		이동하려는 칸에 D, E가 있는 경우에는 A번 말이 이동한 후에는
		D, E, A, B, C가 된다
	*/
	vector<int> tmp;
	int s = 0;
	while (1) {
		if (h_map[now.y][now.x][s] == idx)break;
		++s;
	}
	int e = s;
	while (1) {
		if (h_map[now.y][now.x][e] == 0)break;
		tmp.push_back(h_map[now.y][now.x][e]);
		h_map[now.y][now.x][e] = 0;
		++e;
	}

	int last_idx = 0;
	while (1) {
		if (h_map[ny][nx][last_idx] == 0)break;
		++last_idx;
	}
	for (int i = 0; i < tmp.size(); i++) {
		h_map[ny][nx][last_idx + i] = tmp[i];
		arr[tmp[i]] = { ny, nx, arr[tmp[i]].dir };
	}

	int maximum = 0;
	while (1) {
		if (h_map[ny][nx][maximum] == 0) break;
		++maximum;
	}
	if (maximum >= 4) {
		fourth_horse = 1;
		return;
	}
}
void on_red(int idx, int y, int x, int ny, int nx) {
	Horse now = { y,x,arr[idx].dir };
	/*
	빨간색인 경우에는
		A, B, C가 이동하고, 이동하려는 칸에 말이 없는 경우에는 C, B, A가 된다.
		A, D, F, G가 이동하고, 이동하려는 칸에 말이 E, C, B로 있는 경우에는
		E, C, B, G, F, D, A가 된다.
	*/
	vector<int> tmp;
	int s = 0;
	while (1) {
		if (h_map[now.y][now.x][s] == idx)break;
		++s;
	}
	int e = s;
	while (1) {
		if (h_map[now.y][now.x][e] == 0)break;
		tmp.push_back(h_map[now.y][now.x][e]);
		h_map[now.y][now.x][e] = 0;
		++e;
	}
	reverse(tmp.begin(), tmp.end());
	int last_idx = 0;
	while (1) {
		if (h_map[ny][nx][last_idx] == 0)break;
		++last_idx;
	}
	for (int i = 0; i < tmp.size(); i++) {
		h_map[ny][nx][last_idx + i] = tmp[i];
		arr[tmp[i]] = { ny, nx, arr[tmp[i]].dir };
	}

	int maximum = 0;
	while (1) {
		if (h_map[ny][nx][maximum] == 0) break;
		++maximum;
	}
	if (maximum >= 4) {
		fourth_horse = 1;
		return;
	}
}
void move_horse(int idx) {
	Horse now = arr[idx];

	int ny = now.y + dy[now.dir];
	int nx = now.x + dx[now.dir];

	// A번 말이 이동하려는 칸이
	if (ny<1 || ny>N || nx<1 || nx>N) { // 체스판을 벗어나는 경우에는 파란색과 같은 경우이다.
		on_blue(idx, now.y, now.x, ny, nx);
		if (fourth_horse) return;
	}
	else {
		// 0은 흰색, 1은 빨간색, 2는 파란색
		if (map[ny][nx] == 0) {
			on_white(idx, now.y, now.x, ny, nx);
			if (fourth_horse) return;
		}
		if (map[ny][nx] == 1) {
			on_red(idx, now.y, now.x, ny, nx);
			if (fourth_horse) return;
		}
		if (map[ny][nx] == 2) {
			on_blue(idx, now.y, now.x, ny, nx);
			if (fourth_horse) return;
		}
	}
}
void output() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cout << '[' << map[y][x] << ']';
			if (h_map[y][x][0] != 0) {
				int i = 0;
				cout << h_map[y][x][i];
				while (1) {
					++i;
					if (h_map[y][x][i] == 0) break;
					cout << ',' << h_map[y][x][i];
				}
				cout << '\t';
			}
			else cout << h_map[y][x][0] << '\t';
		}
		cout << '\n';
	}
	cout << '\n';
}
void sol() {
	input();

	/*
	한 말이 이동할 때 위에 올려져 있는 말도 함께 이동한다.
	턴이 진행되던 중에 말이 4개 이상 쌓이는 순간 게임이 종료된다.
	*/
	int flag = 0;
	while (1) {
		++turn;
		if (turn > 1000) {
			flag = 1;
			break;
		}

		// 턴 한 번은 1번 말부터 K번 말까지 순서대로 이동시키는 것이다.
		for (int i = 1; i <= K; i++) {
			move_horse(i);
			//output();
			if (fourth_horse) break;
		}
		if (fourth_horse) break;
	}
	if (flag) cout << -1;
	else cout << turn;

	int de = 1;
}
int main() {
	freopen_s(new FILE*, "Input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}