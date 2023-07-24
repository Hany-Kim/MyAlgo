#include <iostream>
using namespace std;

int n;
int map[501][501];
int cpy[501][501];

void sol() {
	cin >> n;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < y + 1; x++) {
			cin >> map[y][x];
		}
	}
	cpy[0][0] = map[0][0];
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < y + 1; x++) {
			if (cpy[y + 1][x] < (cpy[y][x] + map[y + 1][x])) cpy[y + 1][x] = cpy[y][x] + map[y + 1][x];
			if (cpy[y + 1][x + 1] < (cpy[y][x] + map[y + 1][x + 1])) cpy[y + 1][x + 1] = cpy[y][x] + map[y + 1][x + 1];
		}
	}
	int maxn = 0;
	for (int i = 0; i < n; i++) {
		if (maxn < cpy[n - 1][i]) maxn = cpy[n - 1][i];
	}
	cout << maxn;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}