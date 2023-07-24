#include <iostream>
using namespace std;

int N;

void sol() {
	cin >> N;
	for (int i = 0; i < (N/4); i++) {
		cout << "long ";
	}
	cout << "int";
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	sol();
	return 0;
}