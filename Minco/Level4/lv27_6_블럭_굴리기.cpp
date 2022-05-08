#include <iostream>
#include <cstring>

using namespace std;

int block[3][3] = {
	0,5,4,
	3,0,0,
	0,0,1
};

int temp[3][3];

void rotate() {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			temp[x][2 - y] = block[y][x];
		}
	}

	memcpy(block, temp, sizeof(int) * 9);
}

void output() {
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (block[y][x] == 0) {
				cout << '_';
				continue;
			}
			cout << block[y][x];
		}
		cout << endl;
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		rotate();
	}

	output();
	return 0;
}