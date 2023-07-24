#include <iostream>
#include <string>
using namespace std;

string S;
int location[26];

void init() {
	for (int i = 0; i < 26; i++) {
		location[i] = -1;
	}
}

void input() {
	cin >> S;
}

void search() {
	for (int i = 0; i < S.length(); i++) {
		if (location[int(S[i] - 'a')] == -1) {
			location[int(S[i] - 'a')] = i;
		}
	}
}

void sol() {
	init();
	input();
	search();
	for (int i = 0; i < 26; i++) {
		cout << location[i] << " ";
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