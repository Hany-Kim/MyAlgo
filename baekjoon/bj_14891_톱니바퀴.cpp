#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<vector<int>> gear(5);
int K;
int sum;

void input() {
	for (int y = 1; y <= 4; y++) {
		string tmp = "";
		cin >> tmp;
		for (int x = 0; x < 8; x++) {
			gear[y].push_back(int(tmp[x] - '0'));
		}
	}
	cin >> K;
}

void rotate_gear_1(int dir) {
	if (dir == 1) {
		if (gear[1][2] != gear[2][6]) { // 다르면 회전
			if (gear[2][2] != gear[3][6]) {
				if (gear[3][2] != gear[4][6]) {
					gear[4] = { gear[4][1], gear[4][2], gear[4][3], gear[4][4], gear[4][5], gear[4][6], gear[4][7], gear[4][0] }; // 반시계
				}
				gear[3] = { gear[3][7], gear[3][0], gear[3][1], gear[3][2], gear[3][3], gear[3][4], gear[3][5], gear[3][6] }; // 시계
			}
			gear[2] = { gear[2][1], gear[2][2], gear[2][3], gear[2][4], gear[2][5], gear[2][6], gear[2][7], gear[2][0] }; // 반시계
		}
		gear[1] = { gear[1][7], gear[1][0], gear[1][1], gear[1][2], gear[1][3], gear[1][4], gear[1][5], gear[1][6] }; // 시계
	}
	else if (dir == -1) {
		if (gear[1][2] != gear[2][6]) { // 다르면 회전
			if (gear[2][2] != gear[3][6]) {
				if (gear[3][2] != gear[4][6]) {
					gear[4] = { gear[4][7], gear[4][0], gear[4][1], gear[4][2], gear[4][3], gear[4][4], gear[4][5], gear[4][6] }; // 시계
				}
				gear[3] = { gear[3][1], gear[3][2], gear[3][3], gear[3][4], gear[3][5], gear[3][6], gear[3][7], gear[3][0] }; // 반시계
			}
			gear[2] = { gear[2][7], gear[2][0], gear[2][1], gear[2][2], gear[2][3], gear[2][4], gear[2][5], gear[2][6] }; // 시계
		}
		gear[1] = { gear[1][1], gear[1][2], gear[1][3], gear[1][4], gear[1][5], gear[1][6], gear[1][7], gear[1][0] }; // 반시계
	}
}

void rotate_gear_2(int dir) {
	if (dir == 1) {
		if (gear[2][6] != gear[1][2]) {
			gear[1] = { gear[1][1], gear[1][2], gear[1][3], gear[1][4], gear[1][5], gear[1][6], gear[1][7], gear[1][0] }; // 반시계
		}
		if (gear[2][2] != gear[3][6]) {
			if(gear[3][2] != gear[4][6]){
				gear[4] = { gear[4][7], gear[4][0], gear[4][1], gear[4][2], gear[4][3], gear[4][4], gear[4][5], gear[4][6] }; // 시계
			}
			gear[3] = { gear[3][1], gear[3][2], gear[3][3], gear[3][4], gear[3][5], gear[3][6], gear[3][7], gear[3][0] }; // 반시계
		}
		gear[2] = { gear[2][7], gear[2][0], gear[2][1], gear[2][2], gear[2][3], gear[2][4], gear[2][5], gear[2][6] }; // 시계
	}
	else if (dir == -1) {
		if (gear[2][6] != gear[1][2]) {
			gear[1] = { gear[1][7], gear[1][0], gear[1][1], gear[1][2], gear[1][3], gear[1][4], gear[1][5], gear[1][6] }; // 시계
		}
		if (gear[2][2] != gear[3][6]) {
			if (gear[3][2] != gear[4][6]) {
				gear[4] = { gear[4][1], gear[4][2], gear[4][3], gear[4][4], gear[4][5], gear[4][6], gear[4][7], gear[4][0] }; // 반시계
			}
			gear[3] = { gear[3][7], gear[3][0], gear[3][1], gear[3][2], gear[3][3], gear[3][4], gear[3][5], gear[3][6] }; // 시계
		}
		gear[2] = { gear[2][1], gear[2][2], gear[2][3], gear[2][4], gear[2][5], gear[2][6], gear[2][7], gear[2][0] }; // 반시계
	}
}

void rotate_gear_3(int dir) {
	if (dir == 1) {
		if (gear[3][6] != gear[2][2]) {
			if (gear[2][6] != gear[1][2]) {
				gear[1] = { gear[1][7], gear[1][0], gear[1][1], gear[1][2], gear[1][3], gear[1][4], gear[1][5], gear[1][6] }; // 시계
			}
			gear[2] = { gear[2][1], gear[2][2], gear[2][3], gear[2][4], gear[2][5], gear[2][6], gear[2][7], gear[2][0] }; // 반시계
		}
		if (gear[3][2] != gear[4][6]) {
			gear[4] = { gear[4][1], gear[4][2], gear[4][3], gear[4][4], gear[4][5], gear[4][6], gear[4][7], gear[4][0] }; // 반시계
		}
		gear[3] = { gear[3][7], gear[3][0], gear[3][1], gear[3][2], gear[3][3], gear[3][4], gear[3][5], gear[3][6] }; // 시계
	}
	else if (dir == -1) {
		if (gear[3][6] != gear[2][2]) {
			if (gear[2][6] != gear[1][2]) {
				gear[1] = { gear[1][1], gear[1][2], gear[1][3], gear[1][4], gear[1][5], gear[1][6], gear[1][7], gear[1][0] }; // 반시계
			}
			gear[2] = { gear[2][7], gear[2][0], gear[2][1], gear[2][2], gear[2][3], gear[2][4], gear[2][5], gear[2][6] }; // 시계
		}
		if (gear[3][2] != gear[4][6]) {
			gear[4] = { gear[4][7], gear[4][0], gear[4][1], gear[4][2], gear[4][3], gear[4][4], gear[4][5], gear[4][6] }; // 시계
		}
		gear[3] = { gear[3][1], gear[3][2], gear[3][3], gear[3][4], gear[3][5], gear[3][6], gear[3][7], gear[3][0] }; // 반시계
	}
}

void rotate_gear_4(int dir) {
	if (dir == 1) {
		if (gear[4][6] != gear[3][2]) {
			if (gear[3][6] != gear[2][2]) {
				if (gear[2][6] != gear[1][2]) {
					gear[1] = { gear[1][1], gear[1][2], gear[1][3], gear[1][4], gear[1][5], gear[1][6], gear[1][7], gear[1][0] }; // 반시계
				}
				gear[2] = { gear[2][7], gear[2][0], gear[2][1], gear[2][2], gear[2][3], gear[2][4], gear[2][5], gear[2][6] }; // 시계
			}
			gear[3] = { gear[3][1], gear[3][2], gear[3][3], gear[3][4], gear[3][5], gear[3][6], gear[3][7], gear[3][0] }; // 반시계
		}
		gear[4] = { gear[4][7], gear[4][0], gear[4][1], gear[4][2], gear[4][3], gear[4][4], gear[4][5], gear[4][6] }; // 시계
	}
	else if (dir == -1) {
		if (gear[4][6] != gear[3][2]) {
			if (gear[3][6] != gear[2][2]) {
				if (gear[2][6] != gear[1][2]) {
					gear[1] = { gear[1][7], gear[1][0], gear[1][1], gear[1][2], gear[1][3], gear[1][4], gear[1][5], gear[1][6] }; // 시계
				}
				gear[2] = { gear[2][1], gear[2][2], gear[2][3], gear[2][4], gear[2][5], gear[2][6], gear[2][7], gear[2][0] }; // 반시계
			}
			gear[3] = { gear[3][7], gear[3][0], gear[3][1], gear[3][2], gear[3][3], gear[3][4], gear[3][5], gear[3][6] }; // 시계
		}
		gear[4] = { gear[4][1], gear[4][2], gear[4][3], gear[4][4], gear[4][5], gear[4][6], gear[4][7], gear[4][0] }; // 반시계
	}
}

void sol() {
	input();
	for (int i = 0; i < K; i++) {
		int gear_num = 0, gear_dir = 0;
		cin >> gear_num >> gear_dir;
		
		switch (gear_num)
		{
		case 1:
			rotate_gear_1(gear_dir);
			break;
		case 2:
			rotate_gear_2(gear_dir);
			break;
		case 3:
			rotate_gear_3(gear_dir);
			break;
		case 4:
			rotate_gear_4(gear_dir);
			break;
		default:
			break;
		}
	}
	if (gear[1][0]) sum += gear[1][0] * 1;
	if (gear[2][0]) sum += gear[2][0] * 2;
	if (gear[3][0]) sum += gear[3][0] * 4;
	if (gear[4][0]) sum += gear[4][0] * 8;
	cout << sum;
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}