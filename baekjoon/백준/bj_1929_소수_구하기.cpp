#include <stdio.h>

int M, N;
int sosu[1000001];

void sol() {
	scanf("%d %d", &M, &N);
	sosu[0] = sosu[1] = 1;
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j * i <= N; j++) {
			if(sosu[j*i] == 0) sosu[j * i] = 1;
		}
	}

	for (int i = M; i <= N; i++) {
		if (sosu[i] == 0)printf("%d\n", i);
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	sol();

	return 0;
}