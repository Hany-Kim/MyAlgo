#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector <string> name;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string t = "";
		cin >> t;
		name.push_back(t);
	}
}

string process(string nname) {
	int big_flag = 0;
	for (int i = 0; i < nname.size(); i++) {
		if (nname[i] >= 'A' && nname[i] <= 'Z') {
			big_flag++;
		}
	}
	if (big_flag == 0) {
		nname[0] = char(nname[0] - ('a' - 'A'));
	}
	if (big_flag > 1) {
		for (int i = 0; i < nname.size(); i++) {
			if (nname[i] >= 'a' && nname[i] <= 'z') {
				nname[i] = char(nname[i] - ('a' - 'A'));
			}
		}
	}

	return nname;
}

void sol() {
	input();
	for (int i = 0; i < N; i++) {
		name[i] = process(name[i]);
	}
	sort(name.begin(), name.end());
	for (int i = 0; i < name.size(); i++) {
		cout << name[i] << '\n';
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