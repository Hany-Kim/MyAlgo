#include <iostream>
#include <string>
using namespace std;

string str;
int alpha[26];
int max_num;
int idx;
bool flag;

void input() {
	cin >> str;
}

void init() {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			alpha[str[i] - 'A']++;
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			alpha[str[i] - 'a']++;
		}
	}
}

void search() {
	for (int i = 0; i < 26; i++) {
		if (max_num < alpha[i]) {
			max_num = alpha[i];
			idx = i;
			flag = false;
		}
		else if (max_num == alpha[i])flag = true;
	}
}

void output() {
	if (flag) cout << "?";
	else {
		cout << char(idx + 'A');
	}
}

void sol() {
	input();
	init();
	search();
	output();
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}