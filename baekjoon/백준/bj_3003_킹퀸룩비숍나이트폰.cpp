#include <iostream>
using namespace std;

int need[6] = { 1,1,2,2,2,8 };
int cur[6];

void input() {
	for (int i = 0; i < 6; i++) {
		cin >> cur[i];
	}
}

void sol() {
	input();

	for (int i = 0; i < 6; i++) {
		cout << need[i] - cur[i] << " ";
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