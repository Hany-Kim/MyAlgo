#include <iostream>

using namespace std;

int m[3][3];
int temp;
int flag;

void input() {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			cin >> m[y][x];
		}
	}
}

void search() {
	for (int y = 0; y < 3; y++) {
		temp = m[y][0];
		flag = 0;
		for (int x = 0; x < 3; x++) {
			if (temp != m[y][x]) {
				flag = 1;
				break;
			}
		}
		if (flag) cout << "x" << endl;
		else cout << temp << endl;
	}
}

void solution() {
	input();
	search();
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	return 0;
}