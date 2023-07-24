#include <stdio.h>

int N, M;
int matrix_N[100][100];
int matrix_M[100][100];

void sol() {
	scanf("%d %d", &N, &M);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf("%d", &matrix_N[y][x]);
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf("%d", &matrix_M[y][x]);
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			printf("%d ", matrix_N[y][x] + matrix_M[y][x]);
		}
		printf("\n");
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	sol();

	return 0;
}