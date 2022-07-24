#include <iostream>
#include <string>
using namespace std;

char ox[2] = {'o', 'x'};
int person_num;
char path[5];

void input() {
	cin >> person_num;
}

void path_output() {
	cout << path << endl;
}

void func(int num) {
	if (num == 0) {
		path_output();
		return;
	}
	for (int i = 0; i < 2; i++) {
		path[person_num-num] = ox[i];
		func(num - 1);
	}
}

void sol() {
	input();
	func(person_num);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	sol();

	return 0;
}