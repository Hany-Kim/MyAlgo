#include <iostream>

using namespace std;

int arr[4][4];
int dir[2][4] = {
	0,0,-1,1,
	-1,1,0,0
};

void input() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> arr[y][x];
		}
	}
}

void solution() {
	int flag = 0;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (arr[y][x] == 1) {
				for (int i = 0; i < 4; i++) {
					int dy = y + dir[0][i];
					int dx = x + dir[1][i];

					if (arr[dy][dx] == 1) {
						flag = 1;
						break;
					}
				}
				if (flag)break;
			}
		}
		if (flag)break;
	}
	if (flag) cout << "위험한 상태";
	else cout << "안전한 상태";
}

int main() {
	input();
	solution();

	return 0;
}