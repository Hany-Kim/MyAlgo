#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int x, y, w, h;
int min_num = 213456789;
int sum[4];

void sol() {
	scanf("%d %d %d %d", &x, &y, &w, &h);
	
	sum[0] = x - 0;
	sum[1] = w - x;
	sum[2] = y - 0;
	sum[3] = h - y;
	for (int i = 0; i < 4; i++) {
		if (min_num > sum[i]) min_num = sum[i];
	}
	printf("%d", min_num);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	sol();
	return 0;
}