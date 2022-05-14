#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int m[5][4];
vector<int> bomb_line;
int temp[4];

void input() {
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 4; x++) {
			cin >> m[y][x];
		}
	}
}

void bomb(int line) {
	for (int i = 0; i < 4; i++) {
		m[line][i] = 0;
	}
}

void find() {
	for (int y = 0; y < 5; y++) {
		int cnt = 0;
		for (int x = 0; x < 4; x++) {
			if (m[y][x] == 1)cnt++;
		}
		if (cnt == 4) {
			bomb(y);
			bomb_line.push_back(y);
		}
	}
}

void find_remain() {
	while (!bomb_line.empty()) {
		memcpy(temp, m[bomb_line.back()], 4);
		for (int y = bomb_line.back()-1; y >= 0; y--) {
			for (int x = 0; x < 4; x++) {
				m[y + 1][x] = m[y][x];
			}
		}
		for (int x = 0; x < 4; x++) {
			m[0][x] = temp[x];
		}
		bomb_line.pop_back();
		for (int i = 0; i < bomb_line.size(); i++) {
			bomb_line[i]++;
		}
	}
}

void answer() {
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 4; x++) {
			cout << m[y][x] << " ";
		}
		cout << endl;
	}
}

int main() {

	//freopen_s(new FILE*, "input.txt", "r", stdin);
	input();
	find();
	find_remain();
	answer();

	return 0;
}