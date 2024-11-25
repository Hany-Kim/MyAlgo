#include <iostream>
#include <math.h>
using namespace std;

int N, K;

void solution() {
	cin >> N >> K;

	int divSon = 1;
	for (int i = 1; i <= N; ++i) {
		divSon *= i;
	}
	int divMom = 1;
	for (int i = 1; i <= (N-K); ++i) {
		divMom *= i;
	}
	for (int i = 1; i <= K; ++i) {
		divMom *= i;
	}

	double ans = double(divSon) / divMom;

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solution();
	return 0;
}