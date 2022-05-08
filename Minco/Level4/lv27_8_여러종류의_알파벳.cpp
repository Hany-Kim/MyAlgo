#include <iostream>
#include <string>

using namespace std;

char sen[11];
int dat_cnt[26];
int cnt;

void input() {
	cin >> sen;
}

void alphabet_cnt() {
	for (int i = 0; i < 10; i++) {
		if (sen[i] == '\n') break;
		dat_cnt[sen[i] - 'A']++;
	}
}

void search() {
	for (int i = 0; i < 26; i++) {
		if (dat_cnt[i] != 0) {
			cnt++;
		}
	}
}

int main() {

	input();
	alphabet_cnt();
	search();

	cout << cnt << "Á¾·ù";
	return 0;
}