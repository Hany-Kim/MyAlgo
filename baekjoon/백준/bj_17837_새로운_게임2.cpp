#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
�ϳ��� �� ���� �ٸ� ���� �ø� �� �ִ�

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
int dy[5] = { 0,0,0,-1,1 }; // �̵� ������ 4���� �۰ų� ���� �ڿ����̰� 1���� ������� ��, ��, ��, ��
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
		cin >> arr[i].y >> arr[i].x >> arr[i].dir; // ���� 1������ K������ ��ȣ�� �Ű��� �ְ�, �̵� ���⵵ �̸� ������ �ִ�.
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
	�Ķ����� ��쿡�� A�� ���� �̵� ������ �ݴ�� �ϰ� �� ĭ �̵��Ѵ�.
	������ �ݴ�� �ٲ� �Ŀ� �̵��Ϸ��� ĭ�� �Ķ����� ��쿡�� �̵����� �ʰ� ������ �ִ´�.
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
	����� ��쿡�� �� ĭ���� �̵��Ѵ�.
		A�� ���� ���� �ٸ� ���� �ִ� ��쿡�� A�� ���� ���� �ִ� ��� ���� �̵��Ѵ�
		���� ���, A, B, C�� �׿��ְ�,
		�̵��Ϸ��� ĭ�� D, E�� �ִ� ��쿡�� A�� ���� �̵��� �Ŀ���
		D, E, A, B, C�� �ȴ�
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
	�������� ��쿡��
		A, B, C�� �̵��ϰ�, �̵��Ϸ��� ĭ�� ���� ���� ��쿡�� C, B, A�� �ȴ�.
		A, D, F, G�� �̵��ϰ�, �̵��Ϸ��� ĭ�� ���� E, C, B�� �ִ� ��쿡��
		E, C, B, G, F, D, A�� �ȴ�.
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

	// A�� ���� �̵��Ϸ��� ĭ��
	if (ny<1 || ny>N || nx<1 || nx>N) { // ü������ ����� ��쿡�� �Ķ����� ���� ����̴�.
		on_blue(idx, now.y, now.x, ny, nx);
		if (fourth_horse) return;
	}
	else {
		// 0�� ���, 1�� ������, 2�� �Ķ���
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
	�� ���� �̵��� �� ���� �÷��� �ִ� ���� �Բ� �̵��Ѵ�.
	���� ����Ǵ� �߿� ���� 4�� �̻� ���̴� ���� ������ ����ȴ�.
	*/
	int flag = 0;
	while (1) {
		++turn;
		if (turn > 1000) {
			flag = 1;
			break;
		}

		// �� �� ���� 1�� ������ K�� ������ ������� �̵���Ű�� ���̴�.
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