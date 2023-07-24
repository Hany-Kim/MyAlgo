#include <cstdio>
#include <vector>>
using namespace std;

int K, N;
vector<long long> k_lan;

long long check(long long standard) {
	int sum = 0;
	for (int i = 0; i < K; i++) {
		sum += k_lan[i] / standard;
	}
	return sum;
}


void BST() {
	long long s = 1;
	long long e = k_lan[0];
	int ans = 0;
	while (s <= e) {
		long long mid = (s + e) / 2;
		long long num = check(mid);
		if (N > num) {
			// 길이가 더 긴경우
			e = mid - 1;
		}
		else if (N <= num) {
			// 길이가 더 짧은 경우
			s = mid + 1;
			if (ans < mid)ans = mid; // ans값 업데이트
		}
	}
	printf("%d", ans);
}

void sol() {
	scanf("%d %d", &K, &N);
	for (int i = 0; i < K; i++) {
		int t;
		scanf("%d", &t);
		k_lan.push_back(t);
	}

	BST();
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	sol();

	return 0;
}