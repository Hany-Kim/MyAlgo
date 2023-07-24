#include <iostream>
#include <string>
using namespace std;

int T, R;
string S;

void answer() {
	for (int i = 0; i < S.length(); i++) {
		for (int j = 0; j < R; j++) {
			cout << S[i];
		}
	}
}

void input() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> R >> S;
		answer();
		cout << '\n';
	}
}

void sol() {
	input();

}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}