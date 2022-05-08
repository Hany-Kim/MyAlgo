#include <iostream>

using namespace std;

int m[5][4];
int bomb_line;

void input() {
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> m[y][x];
		}
	}
}

void bomb(int line) {
	for (int i = 0; i < 4; i++) {
		m[line][i] = 0;
	}
}

void find() {
	for (int y = 0; y < 5; y++) {
		int cnt = 0;
		for (int x = 0; x < 4; x++) {
			if (m[y][x] == 1)cnt++;
		}
		if (cnt == 4) {
			bomb(y);
			bomb_line++;
		}
	}
}

void find_remain() {
	for (int y = 4; y >= 0; y--) {
		for (int x = 3; x >= 0; x--) {
			if (m[y][x] == 1) {
				int dy = y + bomb_line;
				if (dy >= 5)continue;
				m[dy][x] = m[y][x];
				m[y][x] = 0;
			}
		}
	}
}

void answer() {
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 4; x++) {
			cout << m[y][x] << " ";
		}
		cout << endl;
	}
}

int main() {
	input();
	find();
	find_remain();
	answer();

	return 0;
}