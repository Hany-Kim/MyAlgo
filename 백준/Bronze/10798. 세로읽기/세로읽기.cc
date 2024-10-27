#include <iostream>
#include <string>
using namespace std;

string strArr[5];

void sol() {
	for (int i = 0; i < 5; ++i) {
		cin >> strArr[i];
	}

	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (i >= strArr[j].size()) continue;
			cout << strArr[j][i];
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}