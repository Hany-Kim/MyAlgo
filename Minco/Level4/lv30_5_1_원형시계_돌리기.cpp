#include <iostream>
using namespace std;

int watch[4] = { 12,3,6,9 };
int rotate_angle;
int rotate_num;
int temp;

void input() {
	cin >> rotate_angle;
}

void watch_rotate() {
	temp = watch[3];
	for (int i = 2; i >= 0; i--) {
		watch[i + 1] = watch[i];
	}
	watch[0] = temp;
}

void output() {
	cout << watch[0] << " " << watch[3] << " " << watch[1] << " " << watch[2];
}

void solution() {
	input();
	rotate_num = rotate_angle / 90;
	for (int i = 0; i < rotate_num; i++) {
		watch_rotate();
	}
	output();
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	solution();

	return 0;
}