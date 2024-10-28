#include <iostream>
using namespace std;

long long cnt;

void sol() {
	long long n = 0;
	cin >> n;
	cnt = (n * n);
	cout << cnt << "\n" << 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}