#include <stdio.h>
#include <vector>
using namespace std;

int TC;
int N, M, Q;
vector<vector<int>> A;
int ans;

void init() {
	N = 0;
	M = 0;
	Q = 0;
	A.clear();
	ans = 0;
}
void input() {
	scanf("%d %d %d", &N, &M, &Q);
	A = vector<vector<int>>(N + 1, vector<int>(M + 1));

	for (register int y = 1; y <= N; ++y) {
		for(register int x= 1; x <= M; ++x) {
			scanf("%d", &A[y][x]);
		}
	}
}
bool isSafe(int r, int c) {
	for (register int y = 1; y <= N; ++y) {
		if (r == y) continue;
		if (A[r][c] < A[y][c]) return false; // 같은 열중에 더 큰 수 있다.
	}
	for (register int x = 1; x <= M; ++x) {
		if (c == x) continue;
		if (A[r][c] < A[r][x]) return false; // 같은 행중에 더 큰 수 있다.
	}
	return true;
}
void check_safe_cell() {
	for (register int y = 1; y <= N; ++y) {
		for (register int x = 1; x <= M; ++x) {
			if (isSafe(y, x) == true) ++ans;
		}
	}
}
void update_cell() {
	int r = 0, c = 0, x = 0;
	scanf("%d %d %d", &r, &c, &x);

	A[r][c] = x;
	check_safe_cell();
}
void sol() {
	for (register int num = 0; num < Q; ++num) {
		update_cell();
	}
	printf("%d", ans);
}
int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d", &TC);
	
	for (register int testcase = 1; testcase <= TC; ++testcase) {
		printf("#%d ", testcase);
		init();
		input();
		sol();
		printf("\n");
	}

	return 0;
}