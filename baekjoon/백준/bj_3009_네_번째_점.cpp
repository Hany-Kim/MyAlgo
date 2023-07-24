#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Point
{
	int x;
	int y;
};
Point p[1001];
int numx, numy;
int ax, ay;

void sol() {
	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &numx, &numy);
		p[numx].x++;
		p[numy].y++;
	}
	for (int i = 0; i < 1001; i++) {
		if (p[i].x == 1) ax = i;
		if (p[i].y == 1) ay = i;
	}
	printf("%d %d", ax, ay);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	sol();
	return 0;
}