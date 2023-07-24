#include <stdio.h>

int n;

void sol() {
	scanf("%d", &n);
	
	if (n != 1) {
		while (n) {
			int s = 2;
			while (n % s) {
				s++;
			}
			n = n / s;
			printf("%d\n", s);
			if (n == 1) break;
		}
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	sol();

	return 0;
}