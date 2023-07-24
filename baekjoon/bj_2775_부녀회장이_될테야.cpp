#include <stdio.h>

int TC, k, n;
int apart[15][14];

void sol() {
	for (int i = 0; i <= k; i++) {
		apart[i][0] = 1;
	}

	for (int i = 1; i <= n; i++) {
		apart[0][i - 1] = i;
	}

	for (int y = 1; y <= k; y++) {
		for (int x = 1; x < n; x++) {
			int sum = 0;
			for (int i = 0; i <= x; i++) {
				sum += apart[y - 1][i];
			}
			apart[y][x] = sum;
		}
	}

	printf("%d\n", apart[k][n - 1]);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	scanf("%d", &TC);
	for (int i = 0; i < TC; i++) {
		scanf("%d %d", &k, &n);
		sol();
		k = 0;
		n = 0;
		apart[15][14] = { 0, };
	}

	return 0;
}