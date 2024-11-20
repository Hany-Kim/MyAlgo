#include <iostream>

using namespace std;

int N;

void solution() {
	cin >> N;
    int ans = N * (N - 1);
    cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solution();
	return 0;
}