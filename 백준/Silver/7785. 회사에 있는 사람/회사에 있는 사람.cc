#include <iostream>
#include <set>
#include <string>
using namespace std;

int n;
set<string, greater<string>> s;

bool mstrcmp(string s1, string s2) {
	if (s1.size() != s2.size()) return false;

	for (int i = 0; i < s1.size(); ++i) {
		if (s1[i] != s2[i]) return false;
	}

	return true;
}

void sol() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string name, log;
		cin >> name >> log;

		if (mstrcmp(log, "enter")) {
			s.insert(name);
		}
		else if (mstrcmp(log, "leave")) {
			set<string>::iterator itr = s.find(name);
			if (itr != s.end()) {
				s.erase(name);
			}
		}
	}

	for (set<string>::iterator itr = s.begin(); itr != s.end(); itr++) {
		cout << *itr << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}