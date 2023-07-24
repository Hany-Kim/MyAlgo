#include <stdio.h>

int map[100][100];
int N;
int py, px;
int area;

void sol() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &px, &py);
		for (int y = py; y < py + 10; y++) {
			for (int x = px; x < px + 10; x++) {
				map[y][x] = 1;
			}
		}
	}
	for (int y = 0; y < 100; y++) {
		for (int x = 0; x < 100; x++) {
			if (map[y][x] == 1)area++;
		}
	}
	printf("%d", area);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	sol();
	return 0;
}