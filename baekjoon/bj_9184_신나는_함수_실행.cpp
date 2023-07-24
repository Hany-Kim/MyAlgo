#include <iostream>
using namespace std;

int map[21][21][21];

int w(int a, int b, int c) {
	if ((a <= 0) || (b <= 0) || (c <= 0)) {
		return 1;
	}
	else if ((a > 20) || (b > 20) || (c > 20)) {
		return w(20, 20, 20);
	}
	else if ((a < b) && (b < c)) {
		if (map[a][b][c] != 0) return map[a][b][c];
		else return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	else {
		if (map[a][b][c] != 0) return map[a][b][c];
		else return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	}
}

void sol() {
	for (int a = 0; a < 21; a++) {
		for (int b = 0; b < 21; b++) {
			for (int c = 0; c < 21; c++) {
				map[a][b][c] = w(a, b, c);
			}
		}
	}
	while (1) {
		int a, b, c;
		cin >> a >> b >> c;
		if ((a == -1 && b == -1) && c == -1) break;

		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
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