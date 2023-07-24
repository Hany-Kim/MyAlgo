#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

long long input[3];
long long a, b, c;

void sol() {
	while (1) {
		scanf("%lld %lld %lld", &input[0], &input[1], &input[2]);
	
		if (!input[0] && !input[1]) {
			if (!input[2]) break;
		}

		sort(input, input + 3);
		a = input[0];
		b = input[1];
		c = input[2];
		long long cmp = pow(a, 2) + pow(b, 2);
		if (cmp == pow(c, 2)) printf("right\n");
		else printf("wrong\n");
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	sol();
	return 0;
}