#include <iostream>
#include <string>
using namespace std;

string load;

void sol() {
	cin >> load;
	int idx = load.find("#_", 0);
	int ans = (idx + 1) * 10;
	cout << to_string(ans) + "%";
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();
	return 0;
}