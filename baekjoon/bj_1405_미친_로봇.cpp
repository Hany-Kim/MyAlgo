#include <iostream>
using namespace std;

int N;
int map[30][30];
int dy[4] = { 0,0,-1,1 };
int dx[4] = { 1,-1,0,0 };
double percent[4];

double dfs(int lv, int y, int x) {
	if (lv >= N) return 1.0;
	map[y][x] = 1;
	double result = 0.0;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (map[ny][nx]) continue;
		result = result + percent[i] * dfs(lv + 1, ny, nx);
	}
	map[y][x] = 0;
	return result;
}
void sol() {
	cin >> N;
	for (int i = 0; i < 4; i++) {
		int a = 0;
		cin >> a;
		percent[i] = a / 100.0;
	}

	double R = dfs(0, 14, 14);
	cout.precision(10);
	cout << fixed << R << '\n';
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}