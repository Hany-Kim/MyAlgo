#include <iostream>
using namespace std;

int N;
int num = 1;

void input() {
	cin >> N;
}

void fac(int n) {
	if (n == 0) return;
	num = num * n;
	fac(n - 1);
}

void sol() {
	input();
	fac(N);
	cout << num;
}

int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	sol();

	return 0;
}