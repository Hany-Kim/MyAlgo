#include <iostream>

using namespace std;

int gear[3][4] = {
	3,2,5,3,
	7,6,1,6,
	4,9,2,7
};
int g1, g2, g3, g4;
int rotate_arr[4];

void input() {
	for (int i = 0; i < 4; i++) {
		cin >> rotate_arr[i];
	}
}

void rotate() {
	int temp = 0;
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < rotate_arr[j]; i++) {
			temp = gear[2][j];
			gear[2][j] = gear[1][j];
			gear[1][j] = gear[0][j];
			gear[0][j] = temp;
		}
	}
}

void output() {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 4; x++) {
			cout << gear[y][x];
		}
		cout << endl;
	}
}

void solution() {
	input();
	rotate();
	output();
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	return 0;
}