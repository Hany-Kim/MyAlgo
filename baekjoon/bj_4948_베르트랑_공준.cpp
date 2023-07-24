#include <stdio.h>

int sosu[246914];

void sol() {
	sosu[0] = sosu[1] = 1;
	for (int i = 2; i < 246914; i++) {
		for (int j = 2; j * i < 246914; j++) {
			if (sosu[j * i] == 0)sosu[j * i] = 1;
		}
	}
	while (1) {
		int n = 0;
		int cnt = 0;
		scanf("%d", &n);
		if (n == 0) break;

		int e = 2 * n;
		for (int i = n + 1; i <= e; i++) {
			if (sosu[i] == 0) cnt++;
		}
		printf("%d\n", cnt);
	}
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	sol();

	return 0;
}