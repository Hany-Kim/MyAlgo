#include <iostream>
using namespace std;

long long ans;

void sol() {
	long long n = 0;
	cin >> n;
	
	for (int i = n - 1; i >= 1; i--) {
		ans += i;
	}

	cout << ans << "\n" << 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}