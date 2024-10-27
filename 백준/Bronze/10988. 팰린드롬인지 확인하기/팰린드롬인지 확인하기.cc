#include <iostream>
#include <string>
using namespace std;

string str;

void sol() {
	cin >> str;

	int ans = 1;
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] != str[str.size() - i - 1]) {
			ans = 0;
			break;
		}
	}

	cout << ans;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}