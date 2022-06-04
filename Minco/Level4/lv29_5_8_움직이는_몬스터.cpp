#include <iostream>
#include <cstring>
using namespace std;

char map[4][3];
char copy_map[4][3];
int dir[2][4] = {
	0,1,0,-1,
	1,0,-1,0
};

void input() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> map[y][x];
		}
	}
}

void move(int n) {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 3; x++) {
			if (map[y][x] != '_' && map[y][x] != '#') {
				int dy = y + dir[0][n];
				int dx = x + dir[1][n];
				if (dy < 0 || dy>3 || dx < 0 || dx>2 || map[dy][dx] == '#')continue;
				if (map[dy][dx] == 'A' || map[dy][dx] == 'C' || map[dy][dx] == 'D')continue;
				copy_map[dy][dx] = map[y][x];
				copy_map[y][x] = '_';
			}
		}
	}
}

void output() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 3; x++) {
			cout << map[y][x];
		}
		cout << endl;
	}
}

void solution() {
	input();
	memcpy(copy_map, map, 12);
	for (int i = 0; i < 5; i++) {
		move(i%4);
		memcpy(map, copy_map, 12);
	}
	output();
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	return 0;
}