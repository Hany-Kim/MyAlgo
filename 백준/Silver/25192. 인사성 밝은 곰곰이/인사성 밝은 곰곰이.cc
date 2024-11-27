#include <iostream>
#include <set>
#include <string>
using namespace std;

int N;
set<string> s;
int ans;

bool mstrcmp(string s1, string s2) {
	if (s1.size() != s2.size()) return false;

	for (int i = 0; i < s1.size(); ++i) {
		if (s1[i] != s2[i]) return false;
	}

	return true;
}

void solution() {
	cin >> N;

	for (int i = 0; i < N; ++i) {
		string str = "";
		cin >> str;

		if (mstrcmp(str, "ENTER")) {
			ans += s.size();
			s.clear();
			continue;
		}
		else {
			s.insert(str);
		}
	}

	ans += s.size();

	cout << ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solution();
	return 0;
}