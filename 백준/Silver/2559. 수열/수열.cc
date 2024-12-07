#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int arr[100000];
int ans = -110000;

void solution() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}

	int sum = 0;
	for (int i = 0; i < M; ++i) {
		sum += arr[i];
	}

	ans = max(sum, ans);
	for (int i = M; i < N; ++i) {
		sum -= arr[i - M];
		sum += arr[i];

		ans = max(sum, ans);
	}

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solution();
	return 0;
}