#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

unordered_set<int> us;

void sol() {
	while(true) {
		int maxLen = 0;
		int sum = 0;
		for (int i = 0; i < 3; ++i) {
			int n = 0;
			cin >> n;
			us.insert(n);
			maxLen = max(n, maxLen);
			sum += n;
		}

		if (sum == 0) break;

		sum -= maxLen;

		if (sum <= maxLen) cout << "Invalid";
		else {
			if (us.size() == 1) cout << "Equilateral";
			else if (us.size() == 2) cout << "Isosceles";
			else cout << "Scalene";
		}
		us.clear();
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}