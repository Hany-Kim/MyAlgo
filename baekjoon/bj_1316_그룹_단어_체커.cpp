#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> in;
string str;
int T;
int alpha[26];
int flag;
int cnt;

void input() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> str;
		in.push_back(str);
	}
}

void except_overlap(int idx) {
	in[idx].erase(unique(in[idx].begin(), in[idx].end()), in[idx].end());
}

void alpha_init() {
	fill_n(alpha, 26, 0);
}

void check(int idx) {
	flag = 0;
	for (int i = 0; i < in[idx].length(); i++) {
		if (alpha[int(in[idx][i] - 'a')]==0) {
			alpha[int(in[idx][i] - 'a')] = 1;
		}
		else if (alpha[int(in[idx][i] - 'a')] == 1) {
			flag = 1;
		}
		if (flag) break;
	}
}

void sol() {
	input();
	for (int i = 0; i < T; i++) {
		except_overlap(i);
		alpha_init();
		check(i);
		if (flag == 0)cnt++;
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