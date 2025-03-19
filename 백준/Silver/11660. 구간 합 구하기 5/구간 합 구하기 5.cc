#include <iostream>
using namespace std;

#define N_MAX 1024

int N, M;
int map[N_MAX][N_MAX];

void sol() {
	cin >> N >> M;
	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < N; ++x) {
			cin >> map[y][x];
			if (x == 0) continue;

			map[y][x] = map[y][x] + map[y][x - 1];
		}
	}

	for (int i = 0; i < M; ++i) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;

		y1 -= 1;
		x1 -= 1;
		y2 -= 1;
		x2 -= 1;

		int sum = 0;
		for (int y = y1; y <= y2; ++y) {
			if (x1 > 0) {
				int tmp = map[y][x2] - map[y][x1 - 1];
				sum += tmp;
			}
			else {
				int tmp = map[y][x2];
				sum += tmp;
			}
		}
		cout << sum << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	sol();

	return 0;
}