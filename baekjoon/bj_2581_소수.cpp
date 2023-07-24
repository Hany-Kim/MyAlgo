#include <stdio.h>

int arr[10001];
int s, e;
int sum;
int flag, min_sosu;

void sol() {
	arr[0] = arr[1] = 1;
	for (int i = 2; i < 10001; i++) {
		for (int j = 2; j * i < 10001; j++) {
			arr[j * i] = 1;
		}
	}
	scanf("%d %d", &s, &e);
	for (int i = s; i <= e; i++) {
		if (arr[i] == 0) {
			if (!flag) {
				min_sosu = i;
				flag = 1;
			}
			sum += i;
		}
	}
	if (!sum && !min_sosu) printf("%d", -1);
	else printf("%d\n%d", sum, min_sosu);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	sol();

	return 0;
}