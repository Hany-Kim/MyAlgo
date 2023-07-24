#include <iostream>
#include <string>
using namespace std;

string se[6] = {
	"ABCD",
	"ABCE",
	"AGEH",
	"EIEI",
	"FEQE",
	"ABAD"
};
string w;
char word[4];

void input() {
	cin >> w;
}

void sol() {
	input();
	for (int i = 0; i < w.length(); i++) {
		if (w[i] != '?') {
			word[i] = w[i];
		}
	}
	int cnt = 0;
	int flag = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (word[j] != '\0') {
				if (word[j] == se[i][j]) flag = 1;
				else flag = 0;
			}
		}
		if (flag) cnt++;
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