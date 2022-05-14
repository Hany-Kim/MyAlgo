#include <iostream>

using namespace std;

int A, B;
int m[6][6] = {
	0,0,1,0,1,1,
	1,0,0,1,0,0,
	0,0,0,0,1,0,
	1,0,0,0,0,0,
	1,0,0,0,0,0,
	0,0,0,0,0,0
};

int pathCnt;

void input() {
	cin >> A >> B;
}

void dfs(int now) {
	cout << now << " ";

	for (int to = 0; to < 6; to++) {
		if (m[now][to] == 1) {
			dfs(to);
		}
	}
}

void solution() {
	input();
	dfs(A);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	return 0;
}