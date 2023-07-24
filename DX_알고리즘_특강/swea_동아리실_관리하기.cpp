#include <iostream>
#include <string>
using namespace std;

long long compress(char str[13]) {
	long long res = 0;
	for (size_t i = 0; i < 12; ++i) {
		if (str[i] == '\0') break;
		else res = (res << 5) | (str[i] ^ 64);
	}
	return res;
}

void sol() {
	string str = "";
	cin >> str;
	char c[13] = { ' ', };
	for (register int i = 0; i < str.length(); ++i) {
		c[i] = str[i];
	}
	compress(c);
}

int main() {
	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC = 0;
	cin >> TC;
	for (register int testcase = 1; testcase <= TC; ++testcase) {
		cout << "#" << testcase << ' ';
		sol();
		cout << '\n';
	}

	return 0;
}