#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> us;

void sol() {
	int sum = 0;
	for (int i = 0; i < 3; ++i) {
		int n = 0;
		cin >> n;
		us.insert(n);
		sum += n;
	}

	if (sum != 180) cout << "Error";
	else {
		if (us.size() == 1) cout << "Equilateral";
		else if (us.size() == 2) cout << "Isosceles";
		else cout << "Scalene";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}