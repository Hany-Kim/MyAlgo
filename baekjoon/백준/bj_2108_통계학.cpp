#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int a[500001];
int arr[8002];
int avg, center, many, range;
int max_fre;
int flag;
int cnt;

void sol() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int temp = 0;
		scanf("%d", &temp);
		a[i] = temp;
		arr[temp + 4001]++;
		avg += temp;
	}
	
	avg = round(double(avg) / N);

	sort(a, a + N);
	center = a[(N-1) / 2];

	for (int i = 0; i < 8002; i++) {
		if (arr[i] > max_fre) max_fre = arr[i];
	}
	for (int i = 0; i < 8002; i++) {
		if (arr[i] == max_fre) {
			many = i - 4001;
			if (flag) {
				many = i - 4001;
				break;
			}
			flag = 1;
		}
	}

	range = a[N - 1] - a[0];

	printf("%d\n%d\n%d\n%d", avg, center, many, range);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	sol();
	return 0;
}