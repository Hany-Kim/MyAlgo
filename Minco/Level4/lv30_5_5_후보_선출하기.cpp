#include <iostream>
#include <string>
using namespace std;

string str;
int choice;
string path[2];

void input() {
	cin >> str >> choice;
}

void func(int lv) {
	if (lv == choice) {
		for (int i = 0; i < 2; i++) {
			cout << path[i];
		}
		cout << endl;
		return;
	}
	for (int i = 0; i < str.length(); i++) {
		path[lv] = str[i];
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