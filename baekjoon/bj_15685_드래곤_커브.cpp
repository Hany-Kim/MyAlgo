#include <iostream>
#include <vector>
using namespace std;

int N;
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };
int map[101][101];
int cnt;

void sol() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x = 0, y = 0, d = 0, g = 0;
		vector<int> v;
		cin >> x >> y >> d >> g;

		map[y][x] = 1;
		y = y + dy[d];
		x = x + dx[d];
		map[y][x] = 1;

		v.push_back(d);
		for (int j = 0; j < g; j++) {
			for (int k = (v.size() - 1); k >= 0; k--) {
				int nd = (v[k] + 1) % 4;
				y = y + dy[nd];
				x = x + dx[nd];
				map[y][x] = 1;
				v.push_back(nd);
			}
		}
	}
	
	for (int y = 0; y < 101; y++) {
		for (int x = 0; x < 101; x++) {
			if (map[y][x] == 1 && map[y + 1][x] == 1 && map[y][x + 1] == 1 && map[y + 1][x + 1] == 1)cnt++;
		}
	}
	cout << cnt;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}