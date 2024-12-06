#include <iostream>
using namespace std;

int N, M;
int arr[100000];

void solution() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		if (i > 0) {
			arr[i] = arr[i - 1] + arr[i];
		}
	}

	for (int i = 0; i < M; ++i) {
		int s = 0, e = 0;
		cin >> s >> e;

		if (s == 1) {
			cout << arr[e - 1] << '\n';
		}
		else {
			cout << arr[e - 1] - arr[s - 2] << '\n';
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solution();
	return 0;
}