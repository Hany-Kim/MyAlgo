#include <iostream>
#include <string>
using namespace std;

char alpha[5][5];

void input() {
	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			cin >> alpha[y][x];
		}
	}
}

void change() {
	for (int y = 0; y < 5; y++) {
		char temp = ' ';
		temp = alpha[y][1];
		alpha[y][1] = alpha[y][3];
		alpha[y][3] = temp;
	}
}

void compare() {
	string answer = "MAPOM";
	int flag = 0;
	for (int y = 0; y < 5; y++) {
		if (alpha[y] == answer) {
			cout << "yes";
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		cout << "no";
	}
}

void sol() {
	input();
	change();
	compare();
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}