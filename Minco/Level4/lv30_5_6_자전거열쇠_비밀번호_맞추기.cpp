#include <iostream>
#include <string>
using namespace std;

int pw_num;
string pw[3];
char path[4] = { 'A','A','A','C' };
int num;
bool d = false;

void input() {
	cin >> pw_num;
	for (int i = 0; i < 3; i++) {
		cin >> pw[i];
	}
}

void compare() {
	for (int i = 0; i < 3; i++) {
		d = false;
		for (int j = 0; j < 4; j++) {
			if (pw[i][j] == path[j])continue;
			else d = true;
		}
		if (d) continue;
		else cout << num << endl;
	}
}

void func(int lv) {
	if (lv == 4) {
		num++;
		compare();
		return;
	}
	for (int i = 0; i < 26; i++) {
		path[lv] = char('A' + i);
		func(lv + 1);
	}
}

void sol() {
	input();
	func(0);
}

int main() {
	//freopen_s(new FILE*, "input.txt", "r", stdin);

	sol();

	return 0;
}