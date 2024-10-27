#include <iostream>
using namespace std;

int T;

void sol() {
	cin >> T;
	for (int tc = 0; tc < T; ++tc) {
		int num = 0;
		cin >> num;

		cout << (num / 25);
		num = num % 25;
		cout << " " << (num / 10);
		num = num % 10;
		cout << " " << (num / 5);
		num = num % 5;
		cout << " " << (num / 1) << "\n";
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