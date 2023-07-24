#include <iostream>
using namespace std;

int pro;

void input() {
	cin >> pro;
}

void sol() {
	input();
	if (pro == 1) {
		cout << 21;
	}
	else if (pro == 2) {
		cout << 2;
	}
	else if (pro == 3) {
		cout << 2;
	}
	else if (pro == 4) {
		cout << 2;
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}