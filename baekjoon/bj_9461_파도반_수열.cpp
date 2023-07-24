#include <iostream>
using namespace std;

long long tri[101] = { 1,1,1,2,2, };
int N;
int T;

void sol() {
	cin >> T;
	for (int i = 5; i < 101; i++) {
		tri[i] = tri[i - 5] + tri[i - 1];
	}
	for (int j = 0; j < T; j++) {
		cin >> N;
		cout << tri[N - 1] << '\n';
	}
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}