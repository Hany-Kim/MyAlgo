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
		string s1 = "", s2 = "";
		cin >> s1 >> s2;

		if (!s.empty()) {
			set<string>::iterator itr1 = s.find(s1);
			set<string>::iterator itr2 = s.find(s2);
			if (itr1 != s.end()) {
				s.insert(s2);
			}
			if (itr2 != s.end()) {
				s.insert(s1);
			}
		}

		if (mstrcmp(s1, "ChongChong") || mstrcmp(s2, "ChongChong")) {
			s.insert(s1);
			s.insert(s2);
		}
	}

	cout << s.size();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solution();
	return 0;
}