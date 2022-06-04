#include <iostream>

using namespace std;

int block[4][5];
struct POINT {
	int y;
	int x;
};
POINT block_start, block_end;

void input() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 5; x++) {
			cin >> block[y][x];
		}
	}
}

void find() {
	int flag = 0;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 5; x++) {
			if (block[y][x] == 1) {
				block_start = { y,x };
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}
	flag = 0;
	for (int y = 3; y >= 0; y--) {
		for (int x = 4; x >= 0; x--) {
			if (block[y][x] == 1) {
				block_end = { y,x };
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}
}

void output() {
	cout << "(" << block_start.y << "," << block_start.x << ")" << endl;
	cout << "(" << block_end.y << "," << block_end.x << ")" << endl;
}

void solution() {
	input();
	find();
	output();
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	return 0;
}