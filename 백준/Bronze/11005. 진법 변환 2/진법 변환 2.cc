#include <iostream>
#include <string>
using namespace std;

int N;
int B;
string ans;

void sol() {
	cin >> N >> B;

	while (N > 0) {
		int num = N % B;

		if (num >= 0 && num < 10) {
			ans += char(num + '0');
		}
		else {
			ans += char((num - 10) + 'A');
		}

		N /= B;
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i];
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}