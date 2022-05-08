#include <iostream>

using namespace std;

char house[4][4];
int dir[2][8] = {
	-1,-1,-1,0,0,1,1,1,
	-1,0,1,-1,1,-1,0,1
};

void input() {
	for (int i = 0; i < 3; i++) {
		int y, x;
		cin >> y >> x;
		house[y][x] = '#';
	}
}

void wrapped() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (house[y][x] == '#') {
				for (int i = 0; i < 8; i++) {
					int dy = y + dir[0][i];
					int dx = x + dir[1][i];

					if (dy < 0 || dy >= 4 || dx < 0 || dx >= 4 || house[dy][dx] != '\0')continue;
					house[dy][dx] = '@';
				}
			}
		 }
	}
}

void answer() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (house[y][x] == '\0')cout << '_';
			else cout << house[y][x];
		}
		cout << endl;
	}
}

int main() {
	input();
	wrapped();
	answer();

	return 0;
}