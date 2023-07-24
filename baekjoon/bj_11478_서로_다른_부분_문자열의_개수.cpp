#include <iostream>
#include <set>
#include <string>
using namespace std;

string S;
set<string> bubun;

void sol() {
	cin >> S;

	for (int i = 0; i < S.length(); i++) {
		string str = "";
		for (int j = i; j < S.length(); j++) {
			str += S[j];
			bubun.insert(str);
		}
	}
	cout << bubun.size();
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();

	return 0;
}