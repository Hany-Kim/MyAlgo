#include <iostream>
using namespace std;

long long ans;

void sol() {
	long long n = 0;
	cin >> n;
	
	ans = n * n * n;

	cout << ans << "\n" << 3;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}