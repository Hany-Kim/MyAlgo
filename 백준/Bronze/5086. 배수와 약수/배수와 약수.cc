#include <iostream>
using namespace std;

int n1, n2;

void sol() {
	while (true) {
		cin >> n1 >> n2;
		if (n1 == n2) break;

		if (n1 > n2) {
			int mod = n1 % n2;
			if (mod == 0) {
				cout << "multiple";
			}
			else cout << "neither";
		}
		else {
			int mod = n2 % n1;
			if (mod == 0) {
				cout << "factor";
			}
			else cout << "neither";
		}
		cout << '\n';
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