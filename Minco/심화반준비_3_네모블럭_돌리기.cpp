#include <iostream>
using namespace std;

int a[3][3], b[3][3];
int cnt;
int flag, check_flag;

void input() {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> a[y][x];
		}
	}
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> b[y][x];
		}
	}
}

void rotate() {
	int temp[3] = { 0, };
	for (int i = 0; i < 3; i++) {
		temp[i] = a[0][i];
	}

	for (int i = 0; i < 2; i++) {
		a[0][i] = a[i][2];
		a[i][2] = a[2][2 - i];
		a[2][2 - i] = a[2 - i][0];
		a[2 - i][0] = temp[i];
	}
}

void check() {
	flag = 0;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (a[y][x] != b[y][x]) {
				flag = 1;
				break;
			}
		}
		if (flag)break;
	}
}

void sol() {
	input();
	while (!check_flag) {
		rotate();
		cnt++;
		check();
		if (flag == 0)check_flag = 1;
	}
	cout << cnt;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}