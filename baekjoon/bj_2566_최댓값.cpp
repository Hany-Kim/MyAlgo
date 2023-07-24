#include <stdio.h>

int map[9][9];
int r, c, max_num;

void sol() {
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			scanf("%d", &map[y][x]);
		}
	}
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			if (max_num < map[y][x]) {
				max_num = map[y][x];
				r = y;
				c = x;
			}
		}
	}
	printf("%d\n%d %d", max_num, r+1, c+1);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	sol();
	return 0;
}