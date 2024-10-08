#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

#define N_MAX 1000

int C, N, L;
int arr[N_MAX];
double minVal;

void sol() {
	for (int i = 0; i < (N-L+1); ++i) {
		for (int j = i; j < N; ++j) {
			if ((j - i + 1) < L) continue;
			int sum = 0;
			int cnt = 0;
			for (int k = i; k <= (j); ++k) {
				sum += arr[k];
				cnt += 1;
			}
			double avg = (double)sum / cnt;

			minVal = min(minVal, avg);
		}
	}
}

void in() {
	cin >> N >> L;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	minVal = 1010.0;
}

int main() {
	freopen("input.txt", "r", stdin);
	cin >> C;
	for (int i = 0; i < C; ++i) {
		in();
		sol();

		cout << fixed;
		cout.precision(10);
		cout << minVal << '\n';
	}

	return 0;
}