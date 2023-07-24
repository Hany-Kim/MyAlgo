#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int P, N;

void input() {
	cin >> P >> N;
}

void run() {
	P = 2 * P;
	string str = to_string(P);
	reverse(str.begin(), str.end());
	P = stoi(str);
}

void sol() {
	input();
	for (int i = 0; i < N; i++) {
		run();
	}
	cout << P;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}