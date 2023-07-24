#include <stdio.h>

int T;
int sosu[10001];

void sol() {
	sosu[0] = sosu[1] = 1;
	for (int i = 2; i < 10001; i++) {
		for (int j = 2; j * i < 10001; j++) {
			if (sosu[j * i] == 0)sosu[j * i] = 1;
		}
	}
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		int n = 0;
		scanf("%d", &n);

		int flag = 0;
		for (int y = n/2; y > 1; y--) {
			if (sosu[y] == 1) continue;
			for (int x = n/2; x < n; x++) {
				if (sosu[x] == 1) continue;
				if ((y + x) == n) {
					printf("%d %d\n", y, x);
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	sol();

	return 0;
}