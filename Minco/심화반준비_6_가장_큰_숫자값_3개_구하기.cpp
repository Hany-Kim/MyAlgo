#include <iostream>
#include <vector>
using namespace std;

int h, w;
struct point {
	int val;
	int y;
	int x;
};
point map[10][10];

void input() {
	cin >> h >> w;
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			cin >> map[y][x].val;
			map[y][x].y = y;
			map[y][x].x = x;
		}
	}
}

void compare(int y, int x) {
	for (int ny = y; ny < h; ny++) {
		for (int nx = x; nx < w; nx++) {
			if (map[y][x].val < map[ny][nx].val) {
				point temp = map[y][x];
				map[y][x] = map[ny][nx];
				map[ny][nx] = temp;
			}
		}
	}
}

void find() {
	for (int x = 0; x < 3; x++) {
		compare(0, x);
	}
}

void output() {
	for (int i = 0; i < 3; i++) {
		cout << map[0][i].val << "(" << map[0][i].y << "," << map[0][i].x << ")\n";
	}
}

void sol() {
	input();
	find();
	output();
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}