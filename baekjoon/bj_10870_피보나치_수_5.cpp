#include <iostream>
using namespace std;

int s1 = 0;
int s2 = 1;
int temp;
int n;

void input() {
	cin >> n;
}

void fivo(int lv) {
	temp = s1 + s2;
	s1 = s2;
	s2 = temp;
	if (n == lv) {
		return;
	}
	fivo(lv + 1);
}

void sol() {
	input();
	if (n == 0)cout << 0;
	else if (n == 1)cout << 1;
	else {
		fivo(2);
		cout << s2;
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