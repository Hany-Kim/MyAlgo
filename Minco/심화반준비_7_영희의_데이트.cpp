#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string man[3];
string path[3];

void input() {
	for (int i = 0; i < 3; i++) {
		cin >> man[i];
	}
}

void sort_man() {
	sort(man, man + 3);
}

void func(int lv) {
	if (lv == 3) {
		for (int i = 0; i < 3; i++) {
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < 3; i++) {
		path[lv] = man[i];
		func(lv + 1);
	}
}

void sol() {
	input();
	sort_man();
	func(0);
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}