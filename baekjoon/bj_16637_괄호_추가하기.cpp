#include <iostream>
#include <string>
using namespace std;

int N;
string str;

void sol() {
	cin >> N >> str;
	
	int res = int(str[0] - '0');
	for (int i = 1; i <= N; i+=2) {
		if (str[i] == '+') {
			res += int(str[i + 1] - '0');
		}
		else if (str[i] == '-') {
			res = res - int(str[i + 1] - '0');
		}
		else if (str[i] == '*') {
			res = res * int(str[i + 1] - '0');
		}
	}
	cout << res;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}