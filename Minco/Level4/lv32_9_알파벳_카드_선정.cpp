#include <iostream>
#include <vector>
#include <string>
#include  <algorithm>
using namespace std;

vector <char> card;
string str;
int N;
int cnt[26];

void input() {
	cin >> str >> N;
}

void sol() {
	input();
	for (int i = 0; i < str.length(); i++) {
		card.push_back(str[i]);
	}
	sort(card.begin(), card.end(), greater<>());
	for (int i = 0; i < N; i++) {
		cnt[int(card[i] - 'A')]++;
	}
	int max_num = 0;
	int idx = 0;
	for (int i = 0; i < 26; i++) {
		if (max_num < cnt[i]) {
			max_num = cnt[i];
			idx = i;
		}
	}
	cout << char(idx + 'A');
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}