#include <stdio.h>

int n;
int cnt;

void sol() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp = 0;
		scanf("%d", &temp);

		int flag = 0;
		if (temp == 1 || temp == 0) continue;
		else if (temp == 2 || temp == 3) cnt++;
		else {
			for (int i = 2; i < temp; i++) {
				if (temp % i == 0) flag = 1;
				if (flag) break;
			}
			if (!flag) cnt++;
		}
		if (flag) continue;
	}
	printf("%d", cnt);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	
	sol();

	return 0;
}