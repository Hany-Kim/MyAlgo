#include <stdio.h>

int TC, H, W, N;

void sol() {
	scanf("%d %d %d", &H, &W, &N);
	int floor = N % H;
	int ho = (N / H) + 1;
	if (floor == 0) {
		floor = H;
		ho -= 1;
	}

	int ans = floor * 100 + ho;
	printf("%d\n", ans);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	scanf("%d", &TC);
	for (int i = 0; i < TC; i++) {
		sol();
	}

	return 0;
}