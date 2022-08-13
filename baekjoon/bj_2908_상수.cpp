#include <iostream>
#include <string>
using namespace std;

string A, B;
string RA, RB;

void input() {
	cin >> A >> B;
}

void reverse() {
	for (int i = A.length() - 1; i >= 0; i--) {
		RA += A[i];
	}
	for (int i = B.length() - 1; i >= 0; i--) {
		RB += B[i];
	}
}

void sol() {
	input();
	reverse();
	if (stoi(RA) > stoi(RB)) {
		cout << RA;
	}
	else cout << RB;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}