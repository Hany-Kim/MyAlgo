#include <iostream>
#include <string>
using namespace std;

string str;
int cnt;

void input() {
	getline(cin, str);
	cin >> str;
}

void sol() {
	input();
	if (str[0] != ' ')cnt++;
	for (int i = 1; i < str.length(); i++) {
		if (str[i-1] == ' ' && str[i]!= ' ')cnt++;
	}
	cout << cnt;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}