#include <iostream>
using namespace std;

long long ans;

void sol() {
	long long n = 0;
	cin >> n;
	
	for (int i = 1; i <= (n - 2); ++i) {
		ans += i;
	}

	long long tmp = ans;
	for (int i = (n - 2); i >= 1; i--) {
		ans += (tmp - i);
		tmp -= i;
	}

	cout << ans << "\n" << 3;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}