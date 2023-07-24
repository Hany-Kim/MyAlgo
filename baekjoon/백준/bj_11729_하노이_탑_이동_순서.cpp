#include <iostream>
using namespace std;

int num;

void input() {
	cin >> num;
}

void hanoi(int n, int start, int to, int bypass) {
	if (n == 1) {
		cout << start << ' ' << to << '\n';
	}
	else {
		hanoi(n - 1, start, bypass, to);
		cout << start << ' ' << to << '\n';
		hanoi(n - 1, bypass, to, start);
	}
}

void sol() {
	input();
	cout << (1 << num) - 1 << '\n';
	hanoi(num, 1, 3, 2);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}