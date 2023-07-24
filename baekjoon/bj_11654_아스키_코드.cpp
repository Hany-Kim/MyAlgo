#include <iostream>
using namespace std;

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	char ch;
	cin >> ch;

	cout << (int)ch;

	return 0;
}