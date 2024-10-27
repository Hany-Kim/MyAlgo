#include <iostream>
#include <math.h>
using namespace std;

int N;

void sol() {
	cin >> N;

	long long num = 2;
	for (long long i = 0; i < N; ++i) {
		num += (pow(2, i));
	}
	long long ans = pow(num, 2);
	cout << ans;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}