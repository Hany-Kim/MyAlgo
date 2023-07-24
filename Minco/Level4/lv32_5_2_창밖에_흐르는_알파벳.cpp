#include <iostream>
#include <string>
using namespace std;

string str;

void input() {
	cin >> str;
}

void sol() {
	input();

	int flag = 0;
	while (flag != str.length()) {
		flag = 0;
		cout << str << '\n';
		for (int i = 0; i < str.length(); i++) {
			if (str[i] == '_')continue;
			str[i] = char(str[i] - 1);
			if (str[i] < 'A') {
				str[i] = '_';
			}
		}
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == '_') flag++;
			if (flag == str.length()) {
				cout << str;
				break;
			}
		}
	}
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}