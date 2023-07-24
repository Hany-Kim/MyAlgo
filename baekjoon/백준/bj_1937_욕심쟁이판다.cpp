#include <iostream>
#include <cstring>
using namespace std;

// 1. N x N (1<=N<=500)
// 2. �볪���� �԰� ��,��,��,�� �� ���纸�� ���� �볪���� �ִ� �Ѱ����� �̵�
// 3. ��� ����?? ��� ���?? => �ִ��� ���� ĭ �湮

int N;
int bamboo[501][501];
int moveCnt; // �̵��� ĭ��
int dir[2][4] = {
	0,0,-1,1,
	-1,1,0,0
};
bool used[501][501];

int curBamboo;
int nextBamboo;

int result[501][501]; // �ش� ��ǥ���� ����Ҷ� ���

void input() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> bamboo[y][x];
		}
	}
}

void init() {
	moveCnt = 0;
	memset(used, false, 501*501);
}

int compare(int max, int cur) {
	if (max > cur)return max;
	else return cur;
}

int dfs(int py, int px) {
	if (result[py][px]!=0)return result[py][px];
	// ���
	used[py][px] = true;
	result[py][px] = 1;
	curBamboo = bamboo[py][px];
	moveCnt++;
	
	// 4���� ���� ����?
	for (int i = 0; i < 4; i++) {
		int dy = py + dir[0][i];
		int dx = px + dir[1][i];
		if (dy < 0 || dy >= N || dx < 0 || dx >= N) {
			continue;
		}

		nextBamboo = bamboo[dy][dx];
		if (curBamboo < nextBamboo) {
			result[py][px] = compare(result[py][px],dfs(dy, dx) + 1);
		}
	}
	return result[py][px];
}

void solution() {
	int ans = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			//init();
			ans = compare(ans, dfs(y, x));
		}
	}
	cout << ans << endl;
}

int main() {
	input();
	solution();

	//int de = 1;
	return 0;
}